//
//  style.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 12/09/17.
//
//git

#include "GUIStyle.hpp"


GUIStyle::GUIStyle() {
    baseColor = ofColor::dimGray;
    textColor = ofColor::white;
    saturation = 0.1;
    brightness = 20;
    calculateColors();
}


GUIStyle::~GUIStyle() {
    
}

void GUIStyle::calculateColors() {
    backgroundColor = baseColor;
    lightColor = backgroundColor + brightness;
    darkColor = backgroundColor - brightness;
}

GUIStyle& GUIStyle::getInstance() {
    static GUIStyle instance;
    
    return instance;
}



ofColor GUIStyle::getTextColor() {
    return textColor;
}


ofColor GUIStyle::getBaseColor() {
    return baseColor;
}


ofColor GUIStyle::getBackgroundColor() {
    return backgroundColor;
}


ofColor GUIStyle::getDarkColor() {
    return darkColor;
}


ofColor GUIStyle::getLightColor() {
    return lightColor;
}


float GUIStyle::getBrightness() {
    return brightness;
}


float GUIStyle::getSaturation(){
    return saturation;
}

