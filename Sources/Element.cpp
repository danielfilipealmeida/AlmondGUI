//
//  Element.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "Element.hpp"
#include "Viewport.hpp"
#include <typeinfo>
#include "GUI.hpp"


Element::Element()
{
    parent = NULL;
    hover = FALSE;
    pressed = FALSE;
    entered = FALSE;
    exited = FALSE;
    
    rect.x = rect.y = rect.width = rect.height = -1;
}


Element::~Element()
{
    
}

Boolean Element::checkIsDragging()
{
    Boolean result;
    static bool previousMouseState;
    
    result =  ofGetMousePressed() == previousMouseState && ofGetMousePressed() > 0;
    previousMouseState = ofGetMousePressed();
    
    return result;
}


/** TODO: move hover outside */
void Element::update()
{
    dragging = checkIsDragging();
    
    Boolean previousHover = hover;
    hover = FALSE;
    visibleRect = calculateVisibleRect();
    ofRectangle croppedVisibleRect = visibleRect;
    if (parent != NULL) {
        croppedVisibleRect = croppedVisibleRect.getIntersection(parent->visibleRect);
    }
     
    if (!croppedVisibleRect.inside(ofGetMouseX(), ofGetMouseY())) {
        hover = FALSE;
        pressed = FALSE;
    }
    else {
        hover = TRUE;
        if (ofGetMousePressed() > 0) {
            pressed = TRUE;
            
            if (!GUI::getInstance().elementHasChilds(this) &&
                GUI::getInstance().getFocusedElement() != this
                ) {
                GUI::getInstance().setFocusedElement(this);
            }
        }
        //pressed = (ofGetMousePressed() > 0);
    }
    
    
    if (hover) {
        entered = (!previousHover) ? TRUE : FALSE;
    }
    else {
        exited = (previousHover) ? TRUE : FALSE;
    }
}

void Element::draw() {
    
    if (style.hasBackground) {
        ofFill();
        ofSetColor(style.backgroundColor);
        ofDrawRectangle(rect);
    }
}

void Element::finishDraw( ) {
#ifdef GUIDEBUG
    drawDebugRect();
#endif
    
    if (style.hasBorder) {
        ofNoFill();
        ofSetColor(GUI::getInstance().getFocusedElement() == this ? style.focusedColor : style.borderColor);
        ofDrawRectangle(rect);
    }
}

void Element::drawChilds( ) {
    GUI::getInstance().forEach([this](Element *element) {
        if (element->parent != this) return;
        element->draw();
    });
}


ofRectangle Element::getDrawingRec() {
    ofRectangle drawingRect = rect;
    
    if (parent!= NULL && parent->getClass().compare("Viewport") == 0) {
        drawingRect = ((Viewport *) parent)->calculateDrawingRectForElement(this);
    }
    
    return drawingRect;
}


// todo: convert this to of
void Element::drawDebugRect( ) {
    /*
    n BeginPath( );
    n FillColor( , n RGB(0,0,0));
    n Rect( , rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
    n Stroke( );
     */
}




void Element::set(json config) {
    if (!config.is_object()) return;
    
    if (!config["x"].is_number()) return;
    if (!config["y"].is_number()) return;
    if (!config["width"].is_number()) return;
    if (!config["height"].is_number()) return;
    
    rect.set(config["x"].get<unsigned int>(),
             config["y"].get<unsigned int>(),
             config["width"].get<unsigned int>(),
             config["height"].get<unsigned int>());
}



std::vector<Element*> Element::getChildElements() {
    return GUI::getInstance().filter([this](Element *element) {
        return element->parent == this;
    });
}


void Element::setParent(Element *_parent) {
    parent = _parent;
}

Element *Element::add(Element *newElement) {
    newElement->setParent(this);
    
    return newElement;
}


ofRectangle Element::calculateVisibleRect() {
    if (parent == NULL) {
        return rect;
    }
    
    ofRectangle parentRect = parent->calculateVisibleRect();
    ofRectangle visibleRect;
    
    visibleRect.x = parentRect.x + rect.x;
    visibleRect.y = parentRect.y + rect.y;
    visibleRect.width = rect.width;
    visibleRect.height = rect.height;
    
    if (parent->getClass().compare("Viewport") == 0) {
        Viewport *viewport = (Viewport *) parent;
        visibleRect.x = visibleRect.x - viewport->getOffsetX();
        visibleRect.y = visibleRect.y - viewport->getOffsetY();
    }

    return visibleRect;
}



string Element::description() {
    string description;
    
    return description;
}


ofRectangle Element::getRect() {
    ofRectangle returnedRect = rect;
    
    if (returnedRect.x < 0) {
        returnedRect.x = GUI_BORDER ;
    }
    if (returnedRect.y < 0) {
        returnedRect.y = GUI_BORDER;
    }
    if (returnedRect.width < 0) {
        returnedRect.width = (parent!=NULL) ? (parent->getRect().width - 2 * GUI_BORDER) : GUI_LINE_HEIGHT * 5;
    }
    if (returnedRect.height < 0) {
        returnedRect.height = GUI_LINE_HEIGHT * 1.5;
    }
    
    return returnedRect;
}


void Element::resize(ofRectangle newRect) {
    rect = newRect;
}


float Element::getHeightForWidth(float _width) {
    return GUI_LINE_HEIGHT * 1.5;
}

ofRectangle Element::getVisibleRectForRect(ofRectangle _rect) {
    ofRectangle visibleRect;
    
    visibleRect = _rect;
    visibleRect.x = visibleRect.x + rect.x;
    visibleRect.y = visibleRect.y + rect.y;
    if (parent != NULL) {
        ofRectangle parentRect = parent->getRect();
        visibleRect.x = visibleRect.x + parentRect.x;
        visibleRect.y = visibleRect.y + parentRect.y;
    };
    
    return visibleRect;
}

json Element::jsonDump()
{
    return {
        {"rect", GUI::jsonDump(rect)},
        {"visibleRect", GUI::jsonDump(visibleRect)},
        {"drawingRect",  GUI::jsonDump(drawingRect)},
        {"hover", hover},
        {"pressed", pressed},
        {"entered", entered},
        {"exited", exited},
        {"style",  style.jsonDump()}
    };
}

string Element::dump()
{
    return  jsonDump().dump(4);
}

Boolean Element::canScroll() {
    return false;
}
