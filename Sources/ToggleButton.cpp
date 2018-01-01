//
//  ToggleButton.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "ToggleButton.hpp"
#include "GUIStyle.hpp"

void ToggleButton::update() {
    Boolean previousPressed = pressed;
    
    Element::update();
    
    if (pressed == FALSE && previousPressed != pressed) {
        pushed = !pushed;
        onClick(this);
    }
}

ofColor ToggleButton::getBackgroundColor(Boolean isHover, Boolean isPressed, Boolean isPushed) {
    ofColor backgroundColor;
    
    if (isHover == FALSE) {
        backgroundColor = isPushed ? GUIStyle::getInstance().getLightColor() : GUIStyle::getInstance().getBackgroundColor();
    }
    else {
        if (isPressed) {
            backgroundColor = isPushed ? GUIStyle::getInstance().getDarkColor(): GUIStyle::getInstance().getDarkColor() * 1.5;
        }
        else {
            backgroundColor =  isPushed ? GUIStyle::getInstance().getLightColor() * 1.5 : GUIStyle::getInstance().getLightColor();
        }
    }

    return backgroundColor;
}


void ToggleButton::draw( )
{
    ofColor backgroundColor;
    
    Element::draw( );
    backgroundColor = getBackgroundColor(hover, pressed, isPushed());
    
    // todo: draw button
    /*
    drawButton( , caption, getRect(), ofColor2N Color(backgroundColor, 255), ofColor2N Color(GUIStyle::getInstance().getTextColor(), 255));
     */
    
    Element::finishDraw( );
}

void ToggleButton::setOnClick(std::function<void(ToggleButton *toggleButton)> _onClick) {
    onClick = _onClick;
}

Boolean ToggleButton::isPushed() {
    return pushed;
}

void ToggleButton::setPushed(Boolean _pushed) {
    pushed = _pushed;
}
