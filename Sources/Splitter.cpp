//
//  Splitter.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 04/10/17.
//
//

#include "Splitter.hpp"

Splitter::Splitter() {
    type = SPLITTER_VERTICAL;
}

Splitter::~Splitter()  {
    
}


void Splitter::set(json config) {
    if (!config["x"].is_number()) config["x"] = 0;
    if (!config["y"].is_number()) config["y"] = 0;
    if (!config["width"].is_number()) config["width"] = ofGetWidth();
    if (!config["height"].is_number()) config["height"] = ofGetHeight();
    
    if (config["type"].is_number_integer()) type = (SplitterType) config["type"].get<int>();
    
    Element::set(config);
    calculateChildsRects();
}



void Splitter::update() {
    Element::update();
}



void Splitter::draw( ) {
    Element::draw( );
}


void Splitter::resize(ofRectangle newRect) {
    Element::resize(newRect);
    
    // resize childs
    calculateChildsRects();
}

void Splitter::add(Element* element, float size) {
    SplitterChild child;
    
    child.element = element;
    child.size = size;
    childs.push_back(child);
    
    calculateChildsRects();
}


// todo: what is this for?
void Splitter::calculateRect() {
    rect = (parent != NULL) ? parent->getRect() : ofGetWindowRect();
}

void Splitter::calculateChildsRects() {
    //float totalSizeInPercentage = 0.0;
    float totalSizeInPixels = (type == SPLITTER_HORIZONTAL) ? rect.width : rect.height;
    float currentPosition = 0.0;
    
    for(auto child:childs) {
        ofRectangle currentRect;
        float currentSize = totalSizeInPixels * child.size;
        
        if (type == SPLITTER_HORIZONTAL) {
            //currentRect.x = totalSizeInPercentage * totalSizeInPixels;
            currentRect.x = rect.x + currentPosition;
            currentRect.width = currentSize;
            currentRect.y = rect.y;
            currentRect.height = rect.height;
        }
        else {
            //currentRect.y = totalSizeInPercentage * totalSizeInPixels;
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
