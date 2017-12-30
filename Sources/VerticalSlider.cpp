//
//  VerticalSlider.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 23/09/17.
//
//

#include "VerticalSlider.hpp"
#include "Primitives.hpp"
#include "GUIStyle.hpp"

VerticalSlider::VerticalSlider() {
    Slider::Slider();
}

VerticalSlider::~VerticalSlider() {
    Slider::~Slider();
}


void VerticalSlider::update() {
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


void VerticalSlider::draw(NVGcontext* vg) {
    ofColor backgroundColor = getBackgroundColor();
    Element::draw(vg);
    drawSlider(vg, value, caption, rect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255), true);
    Element::finishDraw(vg);
}

void VerticalSlider::set(json config) {
    //cout << config.dump(4) << endl;
    Slider::set(config);
}



