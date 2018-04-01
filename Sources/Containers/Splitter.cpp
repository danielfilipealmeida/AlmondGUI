//
//  Splitter.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 04/10/17.
//
//

#include "Splitter.hpp"

Splitter::Splitter() {
    className = "Splitter";
    type = SPLITTER_VERTICAL;
}


Splitter::~Splitter()
{}


void Splitter::set(json config)
{
    if (!config["x"].is_number()) config["x"] = 0;
    if (!config["y"].is_number()) config["y"] = 0;
    if (!config["width"].is_number()) config["width"] = ofGetWidth();
    if (!config["height"].is_number()) config["height"] = ofGetHeight();
    
    if (config["type"].is_number_integer()) type = (SplitterType) config["type"].get<int>();
    
    Element::set(config);
    calculateChildsRects();
}



void Splitter::update()
{
    Element::update();
}



void Splitter::draw()
{
    Element::draw( );
}


void Splitter::resize(ofRectangle newRect)
{
    Element::resize(newRect);
    
    // resize childs
    calculateChildsRects();
}


void* Splitter::add(void *newElement)
{
    add((Element *) newElement, 0.5, SPLITTER_MODE_PERCENTAGE);
}


void Splitter::add(Element* element, float size, SplitMode mode)
{
    SplitterChild child;
    
    child.element = element;
    child.size = size;
    child.mode = mode;
    childs.push_back(child);
    
    calculateChildsRects();
}


// todo: what is this for?
void Splitter::calculateRect() {
    rect = (parent != NULL) ? ((ElementInterface *)parent)->getRect() : ofGetWindowRect();
}

// todo: make unit tests
float Splitter::getSplitSizeForChild(float totalSplitterSize, SplitterChild child) {
    float result = 0;
    float size;
    
    size = child.size;
    
    switch (child.mode) {
    case SPLITTER_MODE_PERCENTAGE:
            size = ofClamp(size, 0.0, 1.0);
            result = totalSplitterSize * size;
            break;
        
        case SPLITTER_MODE_FIXED:
             size = ofClamp(size, 0.0, totalSplitterSize);
            result = size;
            break;
    }
    
    return result;
}

void Splitter::calculateChildsRects() {
    float totalSizeInPixels = (type == SPLITTER_HORIZONTAL) ? rect.width : rect.height;
    float currentPosition = 0.0;
    
    // todo: make the last child get all remaining space!
    for(auto it = childs.begin(); it != childs.end(); it++) {
        auto child = *it;
        ofRectangle currentRect;
        float currentSize;
        
        // calculate the dimension of the current split.
        // if it's the last take as much space possible!
        if (std::next(it) != childs.end()) {
            currentSize = getSplitSizeForChild(totalSizeInPixels, child);
        }
        else {
            currentSize = totalSizeInPixels - currentPosition;
        }
        
        if (type == SPLITTER_HORIZONTAL) {
            currentRect.x = rect.x + currentPosition;
            currentRect.width = currentSize;
            currentRect.y = rect.y;
            currentRect.height = rect.height;
        }
        else {
            currentRect.y = rect.y + currentPosition;
            currentRect.height = currentSize;
            currentRect.x = rect.x;
            currentRect.width = rect.width;
        }

        child.element->resize(currentRect);
        
        //totalSizeInPercentage = totalSizeInPercentage + child.size; // <- ????
        currentPosition = currentPosition + currentSize;
    }
}
