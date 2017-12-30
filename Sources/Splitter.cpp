//
//  Splitter.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 04/10/17.
//
//

#include "Splitter.hpp"

Splitter::Splitter() {
    
}

Splitter::~Splitter()  {
    
}


void Splitter::set(json config) {
    if (!config["x"].is_number()) config["x"] = 0;
    if (!config["y"].is_number()) config["y"] = 0;
    if (!config["width"].is_number()) config["width"] = ofGetWidth();
    if (!config["height"].is_number()) config["height"] = ofGetHeight();
    
    Element::set(config);
    calculateChildsRects();
}



void Splitter::update() {
    
}



void Splitter::draw(NVGcontext* vg) {
    Element::draw(vg);
}


void Splitter::add(Element* element, float size) {
    SplitterChild child;
    
    child.element = element;
    child.size = size;
    
    childs.push_back(child);
    calculateRect();
    calculateChildsRects();
}

void Splitter::calculateRect() {
    rect = (parent != NULL) ? parent->getRect() : ofGetWindowRect();
}

void Splitter::calculateChildsRects() {
    float totalSizeInPercentage = 0;
    float totalSizeInPixels = (type == SPLITTER_HORIZONTAL) ? rect.width : rect.height;

    for(auto child:childs) {
        ofRectangle currentRect;
        
        if (type == SPLITTER_HORIZONTAL) {
            currentRect.x = totalSizeInPercentage * totalSizeInPixels;
            currentRect.width = totalSizeInPixels * child.size;
            currentRect.y = 0;
            currentRect.height = rect.height;
        }
        else {
            currentRect.y = totalSizeInPercentage * totalSizeInPixels;
            currentRect.height = totalSizeInPixels * child.size;
            currentRect.x = 0;
            currentRect.width = rect.width;
        }
        
        child.element->resize(currentRect);
        
        totalSizeInPercentage = totalSizeInPercentage + child.size;
    }
}
