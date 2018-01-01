//
//  ResetButtonDecorator.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/11/2017.
//

#include "ResetButtonDecorator.hpp"
#include "GUIStyle.hpp"
#include "Slider.hpp"

void ResetButtonDecorator::draw( ) {
    ofRectangle theRect;
    ofColor backgroundColor;
    
    Decorator::draw( );
    
    theRect = resetButton.rect;
    if (parent != NULL) {
        theRect.x = theRect.x + parent->rect.x;
        theRect.y = theRect.y + parent->rect.y;
    }
    backgroundColor = Button::getBackgroundColor(resetButton.hover, resetButton.pushed);
    /*
    drawButton( , resetButton.caption, theRect,
               ofColor2N Color(backgroundColor, 255),
               ofColor2N Color(GUIStyle::getInstance().getTextColor(), 255));
     */
    
    // todo: draw a button here
}

void ResetButtonDecorator::set(json config) {
    Decorator::set(config);
    
    if (config["x"].is_number() &&
        config["y"].is_number() &&
        config["width"].is_number() &&
        config["height"].is_number()
        ) {
        setResetButton(ofRectangle(config["x"].get<float>(),
                                   config["y"].get<float>(),
                                   config["width"].get<float>(),
                                   config["height"].get<float>()));
        config["width"] = config["width"].get<float>() - resetButton.rect.width - (GUI_BORDER / 2.0);
    }
    getElement()->set(config);
}

void ResetButtonDecorator::setResetButton(ofRectangle _rect) {
    resetButton.caption = "X";
    resetButton.rect.width = resetButton.rect.height = _rect.height;
    resetButton.rect.y = _rect.y;
    resetButton.rect.x = _rect.x + _rect.width - resetButton.rect.width;
}

void ResetButtonDecorator::update() {
    Decorator::update();
    
    Boolean previousPressed = resetButton.pressed;
    Boolean previousHover = resetButton.hover;
    ofRectangle visibleRect;
  
    visibleRect = resetButton.rect;
    if (parent != NULL) {
        visibleRect.x = visibleRect.x + parent->rect.x;
        visibleRect.y = visibleRect.y + parent->rect.y;
    }
    
    resetButton.hover = visibleRect.inside(ofGetMouseX(), ofGetMouseY());
    if (resetButton.hover) {
        resetButton.pressed = (ofGetMousePressed() > 0);
        resetButton.pushed = (resetButton.pressed == true && previousPressed != resetButton.pressed && previousHover == true) ? true : false;
        if (resetButton.pushed) {
            Decorator::getElement()->setDefaultValue();
        }
    }
    else {
        resetButton.pressed = false;
        resetButton.pushed = false;
    }
}


void ResetButtonDecorator::setParent(Element *_parent) {
    Decorator::setParent(_parent);
}

void ResetButtonDecorator::resize(ofRectangle newRect) {
    setResetButton(newRect);
    newRect.width = newRect.width - resetButton.rect.width - (GUI_BORDER / 2.0);
    Decorator::resize(newRect);
}
