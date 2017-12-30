//
//  Viewport.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 22/09/17.
//
//

#include "Viewport.hpp"


Viewport::Viewport() {
    scrollPositionX = scrollPositionY = 0;
}


Viewport::~Viewport()  {
    
    
}


void Viewport::set(json config) {
    if (!config.is_object()) {
        config["x"] = 0;
        config["y"] = 0;
        config["width"] = ofGetWidth();
        config["height"] = ofGetHeight();
    }
    
    Element::set(config);
    
    totalWidth = config["totalWidth"].is_number() ? config["totalWidth"].get<float>() : rect.width;
    totalHeight = config["totalHeight"].is_number() ? config["totalHeight"].get<float>() : rect.height;

    if (totalWidth < rect.width) totalWidth = rect.width;
    if (totalHeight < rect.height) totalHeight = rect.height;
}

void Viewport::update()
{
    overflowX = totalWidth - rect.width;
    overflowY = totalHeight - rect.height;
    visibleRect = rect;
    visibleRect.x = overflowX * scrollPositionX;
    visibleRect.y = overflowY * scrollPositionY;

    Element::update();
}

void Viewport::draw(NVGcontext* vg) {
    Element::draw(vg);
    
    //Element::drawDebugRect(vg);
    
    Element::finishDraw(vg);
}


ofRectangle Viewport::calculateDrawingRectForElement(Element *element) {
    ofRectangle drawingRect;
    
    // todo: return empty rect if this isn't a parent of the given element
    
    
    drawingRect = element->rect;
    
    drawingRect.x = drawingRect.x - overflowX * scrollPositionX;
    drawingRect.y = drawingRect.y - overflowY * scrollPositionY;

    return drawingRect;
}


void Viewport::setScrollPositionY(float position) {
    scrollPositionY = position;
}

void Viewport::setScrollPositionX(float position) {
    scrollPositionX = position;
}

Element* Viewport::add(Element *newElement) {
    std::vector<Element*> childElements = getChildElements();
    float elementY, width, height;
    ofRectangle newElementRect = newElement->getRect();
    
    
    newElement->setParent(this);
    
    elementY = ((childElements.size() == 0) ? 0 : childElements.back()->getRect().y + childElements.back()->getRect().height) + GUI_BORDER;
    width = getRect().width - (2*GUI_BORDER);
    height = newElement->getHeightForWidth(width);
    
    newElement->set({
        {"x", GUI_BORDER},
        {"y", elementY},
        {"width", width},
        {"height", height}
    });

    return newElement;
}

void Viewport::resize(ofRectangle newRect) {
    float currentY = GUI_BORDER;
    
    Element::resize(newRect);
    
    
    
    for(auto element:getChildElements()) {
        ofRectangle elementRect = element->getRect();
        float width, height;
        
        width = getRect().width - (2*GUI_BORDER);
        height = element->getHeightForWidth(width);
        
        /*
        element->set({
            {"x", GUI_BORDER},
            {"y", currentY},
            {"width",width},
            {"height", height}
        });
         */
        ofRectangle newRect;
        newRect.x =GUI_BORDER;
        newRect.y =currentY;
        newRect.width = width;
        newRect.height = height;
        element->resize(newRect);
        currentY = currentY + height + GUI_BORDER;
    }
    
}

float Viewport::getScrollPositionY() {
       return scrollPositionY;
}

float Viewport::getScrollPositionX() {
    return scrollPositionX;
}

float Viewport::getOverflowX() {
    return overflowX;
}

float Viewport::getOverflowY() {
    return overflowY;
}

float Viewport::getOffsetX() {
    return scrollPositionX * overflowX;
}


float Viewport::getOffsetY() {
    return scrollPositionY * overflowY;
}
