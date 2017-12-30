//
//  ToggleButton.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "ToggleButton.hpp"
#include "Primitives.hpp"
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


void ToggleButton::draw(NVGcontext* vg)
{
    ofColor backgroundColor;
    
    Element::draw(vg);
    backgroundColor = getBackgroundColor(hover, pressed, isPushed());
    drawButton(vg, caption, getRect(), ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));
    
    Element::finishDraw(vg);
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
