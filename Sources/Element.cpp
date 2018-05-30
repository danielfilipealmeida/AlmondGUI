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
    className = "Element";
    parent = NULL;
    hover = FALSE;
    pressed = FALSE;
    entered = FALSE;
    exited = FALSE;
    visible = TRUE;
    
    rect.x = rect.y = rect.width = rect.height = -1;
    
    std::stringstream ss1;
    identifier = calculateIdentifier();
}

Element::~Element()
{}

string Element::calculateIdentifier()
{
    std::stringstream ss1;
    ss1 << this;
    return className + "-" + ss1.str();
}

string Element::getIdentifier()
{
    return identifier;
}


string Element::getClass()
{
    return className;
}


ofRectangle Element::getVisibleRect()
{
    return visibleRect;
}

void Element::setVisibleRect(ofRectangle _visibleRect)
{
    visibleRect = _visibleRect;
}


void Element::setParent(void *_parent)
{
    parent = (Element *) _parent;
};


void* Element::getParent() {
    return parent;
};

void Element::setVisible(Boolean _visible)
{
    visible = _visible;
}


Boolean Element::getVisible()
{
    return visible;
}



Boolean Element::checkIsDragging()
{
    Boolean result;
    static bool previousMouseState;
    
    result =  ofGetMousePressed() == previousMouseState && ofGetMousePressed() > 0;
    previousMouseState = ofGetMousePressed();
    
    return result;
}


/** TODO:
  - move hover outside
  - receives current gui instance as parameter
 */
void Element::update()
{
    if (visible == FALSE) return;
    
    dragging = checkIsDragging();
    
    Boolean previousHover = hover;
    hover = FALSE;
    pressed = FALSE;
    visibleRect = calculateVisibleRect();
    ofRectangle croppedVisibleRect = visibleRect;
    if (parent != NULL) {
        croppedVisibleRect = croppedVisibleRect.getIntersection(((ElementInterface *)parent)->getVisibleRect());
    }
     
    if (!croppedVisibleRect.inside(ofGetMouseX(), ofGetMouseY())) {
        hover = FALSE;
        pressed = FALSE;
    }
    else {
        hover = TRUE;
        if (ofGetMousePressed() > 0) {
            pressed = TRUE;
            
            
            // todo: better way to handle focusing.
            // this should be done directly on the GUI object.
            // focused should be an element attribute and the GUI
            // handles turning it on and off
            /*
            if (!gui->elementHasChilds(this) && gui->getFocusedElement() != this)
            {
                gui->setFocusedElement(this);
            }
             */
        }
    }
    
    
    if (hover) {
        entered = (!previousHover) ? TRUE : FALSE;
    }
    else {
        exited = (previousHover) ? TRUE : FALSE;
    }
}

void Element::draw() {
    if (visible == FALSE) return;
    
    if (style.alpha < 255) ofEnableAlphaBlending();
    
    if (style.hasBackground) {
        ofFill();
        ofSetColor(style.getBackgroundColor());
        ofDrawRectangle(rect);
    }
}

void Element::finishDraw()
{
    if (visible == FALSE) return;
    
#ifdef GUIDEBUG
    drawDebugRect();
#endif
    
    if (style.hasBorder) {
        ofNoFill();
        ofSetLineWidth(1);
        ofSetColor(style.getBorderColor());
        ofDrawRectangle(rect);
    }
    
    if (style.alpha < 255) ofDisableAlphaBlending();
}


ofRectangle Element::getDrawingRec() {
    ofRectangle drawingRect = rect;
    
    if (parent!= NULL && ((ElementInterface *)parent)->getClass().compare("Viewport") == 0) {
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
    
    if (config["visible"].is_boolean()) {
        visible = config["visible"].get<Boolean>();
    }
}



/*
std::vector<Element*> Element::getChildElements() {
    return gui->filter([this](Element *element) {
        return element->parent == this;
    });
}
*/

void *Element::add(void *newElement) {
    ((Element *)newElement)->setParent(this);
    
    return newElement;
}


ofRectangle Element::calculateVisibleRect() {
    if (parent == NULL) {
        return rect;
    }
    
    ofRectangle parentRect = ((ElementInterface *)parent)->calculateVisibleRect();
    ofRectangle visibleRect;
    
    visibleRect.x = parentRect.x + rect.x;
    visibleRect.y = parentRect.y + rect.y;
    visibleRect.width = rect.width;
    visibleRect.height = rect.height;
    
    // todo: this needs to be completely redone because scollable will be a new interface and it's needed to use this
    /*
    if (((ElementInterface *)parent)->getClass().compare("Viewport") == 0) {
        //Viewport *viewport = (Viewport *) parent;
        // todo: fix the problem of the casting being incomplete due to multi-inheritance
        Viewport *viewport = static_cast<Viewport *>(parent);
        visibleRect.x = visibleRect.x - viewport->getOffsetX();
        visibleRect.y = visibleRect.y - viewport->getOffsetY();
    }
     */
    return visibleRect;
}



string Element::description()
{
    string description;
    
    return description;
}


ofRectangle Element::getRect()
{
    ofRectangle returnedRect = rect;
    
    if (returnedRect.x < 0) {
        returnedRect.x = GUI_BORDER ;
    }
    if (returnedRect.y < 0) {
        returnedRect.y = GUI_BORDER;
    }
    if (returnedRect.width < 0) {
        returnedRect.width = (parent!=NULL) ? (((ElementInterface *)parent)->getRect().width - 2 * GUI_BORDER) : GUI_LINE_HEIGHT * 5;
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
        ofRectangle parentRect = ((ElementInterface *)parent)->getRect();
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

ElementStyle* Element::getStyle() {
    return &style;
}

void Element::saveScreenshot(string path) {
    ofImage img;
    
    img.grabScreen(rect.x, rect.y, rect.width, rect.height);
    img.save(path);
    
}
