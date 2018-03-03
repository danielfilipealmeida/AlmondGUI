//
//  Slider.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 14/09/17.
//
//

#include "Slider.hpp"
#include "GUIStyle.hpp"
#include "Viewport.hpp"
#include "GUI.hpp"


Slider::Slider()
{
    className = "Slider";

    showValue = true;
}

Slider::~Slider()
{
    
}

/*
void Slider::setParent(ElementInterface *_parent) {
    parent=_parent;
}
 */

void Slider::update() {
    float previousValue = value;
    static bool previousMouseState;
    
    // calculate dragging = mouse is clicked and has the same value as previously
    dragging = (ofGetMousePressed() == previousMouseState && ofGetMousePressed() > 0);
    previousMouseState = ofGetMousePressed();
    
    Button::update();
    
    if(!hover) {
        if (exited && ofGetMousePressed() > 0) {
            if (ofGetMouseX() < visibleRect.x) value = minValue;
            if (ofGetMouseX() > visibleRect.x + visibleRect.width) value = maxValue;
        }
    }
    else {
        // todo: find a way to get access to the gui or to find if this is focused
        if (ofGetMousePressed() /*&& GUI::getInstance().getFocusedElement() == this*/) {
            value = getRealValue((ofGetMouseX() - visibleRect.x) / (rect.width));
        }
    }
    
    if (previousValue != value && onChange != NULL) {
        onChange(this);
    }
}

ofColor Slider::getBackgroundColor() {
    if (hover == FALSE) return GUIStyle::getInstance().getBackgroundColor();

    return (pressed) ? GUIStyle::getInstance().getDarkColor() : GUIStyle::getInstance().getLightColor();
}


float Slider::getNormalizedValue() {
    float totalAmount;
    
    totalAmount = maxValue-minValue;
    return (value - minValue) / totalAmount;
}

float Slider::getRealValue(float normalizedValue) {
    float totalAmount;
    
    totalAmount = maxValue - minValue;
    return normalizedValue * totalAmount + minValue;
}

void Slider::draw( )
{
    string displayedCaption = caption;
    ofColor backgroundColor = getBackgroundColor();
    Element::draw( );
    
    if (showValue) {
        displayedCaption.append(" | " + ofToString(value, 2));
    }
    
    float normalizedValue = getNormalizedValue();
    ofSetColor(backgroundColor + 50);
    ofDrawRectangle(rect.x, rect.y, rect.width * normalizedValue, rect.height);
    
    ofSetColor(ofColor::white);
    GUI::drawCenteredText(caption, rect);
    
    Element::finishDraw( );
}

void Slider::set(json config) {
    Button::set(config);
    
    if (!config["minValue"].is_null()) minValue = config["minValue"].is_number_float() ? config["minValue"].get<float>() : 0.0;
    if (!config["maxValue"].is_null()) maxValue = config["maxValue"].is_number_float() ? config["maxValue"].get<float>() : 1.0;
    if (!config["value"].is_null()) setValue((config["value"].is_number_float()) ? config["value"].get<float>() : minValue);
    if (!config["defaultValue"].is_null()) defaultValue = config["defaultValue"].is_number_float() ? config["defaultValue"].get<float>(): 0.0;
}

void Slider::setValue(float _value) {
    value = ofClamp(_value, minValue, maxValue);
}

float Slider::getValue() {
    return value;
}

void Slider::setOnChange(std::function<void(Slider *slider)> _onChange) {
    onChange = _onChange;
}

void Slider::setDefaultValue() {
    value = defaultValue;
    onChange(this);
}

