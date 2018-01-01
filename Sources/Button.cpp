//
//  Button.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "Button.hpp"
#include "GUIStyle.hpp"
#include "GUI.hpp"

Button::Button() 
{
    pushed = false;
    caption = "";
    style.hasBorder = true;
    style.hasBackground = true;

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


void Button::draw( )
{
    style.backgroundColor = getBackgroundColor(hover, pressed);
    Element::draw( );

    ofSetColor(style.captionColor);
    GUI::getInstance().drawCenteredText(caption, rect);
    
    Element::finishDraw( );
}



void Button::set(json config) {
    Element::set(config);
    if (config["caption"].is_string()) caption = config["caption"].get<string>();
    icon = (config["icon"].is_number_unsigned()) ? config["icon"].get<unsigned int>() : 0;
    
}

void Button::setOnClick(std::function<void(Button *button)> _onClick) {
    onClick = _onClick;
}



