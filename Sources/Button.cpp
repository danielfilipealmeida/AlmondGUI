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
    className = "Button";
    pushed = false;
    caption = "";
    style.hasBorder = true;
    style.hasBackground = true;
}

Button::~Button()
{}

string Button::getClass() {
    return "Button";
}


void Button::update() {
    Boolean previousPressed = pressed;
   
    Element::update();
    if (visible == FALSE) return;

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
        // tirar a ternaria. é muito grande
        backgroundColor = isPressed ? GUIStyle::getInstance().getDarkColor() : GUIStyle::getInstance().getLightColor();
    }
    
    return backgroundColor;
}

void Button::draw( )
{
    if (visible == FALSE) return;
    
    style.backgroundColor = style.addAlphaToColor(getBackgroundColor(hover, pressed));
    Element::draw( );

    ofSetColor(style.getCaptionColor());
    GUI::drawCenteredText(caption, rect);
    
    Element::finishDraw( );
}

void Button::set(json config) {
    Element::set(config);
    
    if (config["caption"].is_string()) {
        caption = config["caption"].get<string>();

    }}

void Button::setOnClick(std::function<void(Button *button)> _onClick) {
    onClick = _onClick;
}


string Button::getCaption() {
    return caption;
}
