//
//  Button.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "Button.hpp"
#include "Primitives.hpp"
#include "GUIStyle.hpp"

Button::Button() 
{
    pushed = false;
    caption = "";
}


Button::~Button()
{
   
}

void Button::update() {
    Boolean previousPressed = pressed;
    
    Element::update();

    if (pressed == FALSE && previousPressed != pressed) {
        onClick(this);
    }
}

ofColor Button::getBackgroundColor(Boolean isHover, Boolean isPressed) {
    ofColor backgroundColor;
    
    if (isHover == FALSE) {
        backgroundColor = GUIStyle::getInstance().getBackgroundColor();
    }
    else {
        backgroundColor = isPressed ? GUIStyle::getInstance().getDarkColor() : GUIStyle::getInstance().getLightColor();
    }
    
    return backgroundColor;
}


void Button::draw(NVGcontext* vg)
{
    ofColor backgroundColor;
    ofRectangle theRect;
    
    Element::draw(vg);
    
    backgroundColor = getBackgroundColor(hover, pressed);
    theRect = getRect();
    drawButton(vg, caption, theRect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));

    Element::finishDraw(vg);
}



void Button::set(json config) {
    Element::set(config);
    if (config["caption"].is_string()) caption = config["caption"].get<string>();
    icon = (config["icon"].is_number_unsigned()) ? config["icon"].get<unsigned int>() : 0;
    
}

void Button::setOnClick(std::function<void(Button *button)> _onClick) {
    onClick = _onClick;
}



