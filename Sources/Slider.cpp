//
//  Slider.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 14/09/17.
//
//

#include "Slider.hpp"
#include "Primitives.hpp"
#include "GUIStyle.hpp"
#include "Viewport.hpp"


Slider::Slider()
{
    showValue = true;
}


Slider::~Slider()
{
    
}



void Slider::update() {
    float previousValue = value;
    
    Button::update();
    
    if(!hover) {
        if (exited && ofGetMousePressed() > 0) {
            if (ofGetMouseX() < visibleRect.x) value = minValue;
            if (ofGetMouseX() > visibleRect.x + visibleRect.width) value = maxValue;
        }
    }
    else {
        if (ofGetMousePressed() > 0) {
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


void Slider::draw(NVGcontext* vg)
{
    string displayedCaption = caption;
    ofRectangle drawingRect = Element::getDrawingRec();
    ofColor backgroundColor = getBackgroundColor();
    Element::draw(vg);
    
    if (showValue) {
        displayedCaption.append(" | " + ofToString(value, 2));
    }
    
    drawSlider(vg, getNormalizedValue(), displayedCaption, drawingRect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));
    Element::finishDraw(vg);
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

