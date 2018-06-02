//
//  ResetButtonDecorator.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/11/2017.
//

#include "ResetButtonDecorator.hpp"
#include "GUIStyle.hpp"
#include "Slider.hpp"
#include "GUI.hpp"

void ResetButtonDecorator::draw()
{
    Decorator::draw();
    drawButton();
}


void ResetButtonDecorator::drawButton()
{
    ofRectangle theRect;
    ofColor backgroundColor;

    theRect = resetButton.rect;
    backgroundColor = Button::getBackgroundColor(resetButton.hover, resetButton.pushed);
    
    ofFill();
    ofSetColor(backgroundColor);
    ofDrawRectangle(theRect);
    
    ofSetColor(style.captionColor);
    GUI::drawCenteredText("X", theRect);
    
    ofSetColor(style.borderColor);
    ofNoFill();
    ofDrawRectangle(theRect);

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
        ofRectangle parentRect = parent->getRect();
        visibleRect.x = visibleRect.x + parentRect.x;
        visibleRect.y = visibleRect.y + parentRect.y;
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

ofRectangle ResetButtonDecorator::getRect() {
    ofRectangle result = rect;
    result.growToInclude(resetButton.rect);
    return result;
}
