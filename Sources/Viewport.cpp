//
//  Viewport.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 22/09/17.
//
//

#include "Viewport.hpp"
#include "GUI.hpp"

Viewport::Viewport() {
    scrollPositionX = scrollPositionY = 0;
    style.hasBorder = true;
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
    
    updateFbo();
}


void Viewport::updateFbo()
{
    if (fbo.getHeight() == totalHeight && fbo.getWidth() == totalWidth) return;
    /*
    if (fbo.isAllocated()) {
        fbo.destroy();
    }
     */
    fbo.allocate(totalWidth, totalHeight);
}

void Viewport::update()
{
    //scrollPositionY = 0.5;
    overflowX = totalWidth - rect.width;
    overflowY = totalHeight - rect.height;
    visibleRect = rect;
    visibleRect.x = overflowX * scrollPositionX;
    visibleRect.y = overflowY * scrollPositionY;

    Element::update();
}

void Viewport::draw( )
{
    static Boolean saved = false;
    
    Element::draw( );
    
    fbo.begin();
    ofClear((style.hasBackground == true) ? style.backgroundColor : GUIStyle::getInstance().getDarkColor());
    
    drawChilds();
    
    fbo.end();
    update();

    fbo.getTexture().drawSubsection(rect.x,
                                    rect.y,
                                    rect.width, rect.height,
                                    getOffsetX(),
                                    getOffsetY());
    
    if (!saved) {
        GUI::getInstance().saveTexture("output.png", fbo.getTexture());
        saved = true;
    }
    
    Element::finishDraw( );
}


ofRectangle Viewport::calculateDrawingRectForElement(Element *element) {
    ofRectangle drawingRect;
    
    // todo: return empty rect if this isn't a parent of the given element
    
    drawingRect = element->rect;
    
    drawingRect.x = drawingRect.x - overflowX * scrollPositionX;
    drawingRect.y = drawingRect.y - overflowY * scrollPositionY;

    return drawingRect;
}


void Viewport::setTotalHeight(float height) {
    if (totalHeight < rect.height) return;
    totalHeight = height;
    updateFbo();
    update();
}

void Viewport::setTotalWidth(float width)  {
    if (totalWidth < rect.width) return;
    totalWidth = width;
    updateFbo();
    update();
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
    width = getRect().width - (2 * GUI_BORDER);
    height = newElement->getHeightForWidth(width);
    
    newElement->set({
        {"x", GUI_BORDER},
        {"y", elementY},
        {"width", width},
        {"height", height}
    });

    float nextElementY = height + elementY + 2 * GUI_BORDER;
    if (nextElementY > totalHeight) totalHeight = nextElementY;
    
    updateFbo();
    update();
    
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
    
        ofRectangle newRect;
        newRect.x = GUI_BORDER;
        newRect.y = currentY;
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
