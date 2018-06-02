//
//  VerticalSlider.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 23/09/17.
//
//

#include "VerticalSlider.hpp"
#include "GUIStyle.hpp"

VerticalSlider::VerticalSlider() {
    className = "VerticalSlider";

    // todo: fix this
    //Slider::Slider();
}

VerticalSlider::~VerticalSlider() {
    Slider::~Slider();
}


void VerticalSlider::update() {
    if (visible == FALSE) return;

    float previousValue = value;
    
    Button::update();
    
    
    if(!hover) {
        if (exited && ofGetMousePressed() > 0) {
            if (ofGetMouseY() < visibleRect.y) value = minValue;
            if (ofGetMouseY() > visibleRect.y + visibleRect.height) value = maxValue;
        }
    }
    else {
        if (ofGetMousePressed() > 0) {
            value = (ofGetMouseY() - visibleRect.y) / (rect.height);
        }
    }
    
    if (previousValue != value &&
        onChange != NULL)
    {
        onChange(this);
    }
  
}


void VerticalSlider::draw( ) {
    ofColor backgroundColor = getBackgroundColor();
    
    if (visible == FALSE) return;
    
    Element::draw( );
    /*
    drawSlider( , value, caption, rect, ofColor2N Color(backgroundColor, 255), ofColor2N Color(GUIStyle::getInstance().getTextColor(), 255), true);
    */
    // todo: draw a slider here
     Element::finishDraw( );
}

void VerticalSlider::set(json config) {
    Slider::set(config);
}



