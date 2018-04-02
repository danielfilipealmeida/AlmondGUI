//
//  ElementStyle.cpp
//  AlmondGUI
//
//  Created by Daniel Almeida on 31/12/2017.
//

#include "ElementStyle.hpp"
#include "GUIStyle.hpp"
#include "GUI.hpp"

ElementStyle::ElementStyle() {
    hasBorder = false;
    borderColor = ofColor::black;
    focusedColor = ofColor::yellow;
    
    hasBackground = false;
    backgroundColor = GUIStyle::getInstance().getBackgroundColor();
    
    captionColor = ofColor::white;
    
    alpha = 255;
}


json ElementStyle::jsonDump() {
    return {
        {"hasBorder", hasBorder},
        {"borderColor", GUI::jsonDump(borderColor)},
        {"backgroundColor", GUI::jsonDump(backgroundColor)},
        {"captionColor", GUI::jsonDump(captionColor)},
        {"hasBackground", hasBackground},
    };
}


void ElementStyle::setAlpha(float _alpha)
{
    alpha = _alpha;
}

ofColor ElementStyle::getBackgroundColor()
{
    return addAlphaToColor(backgroundColor);
}


ofColor ElementStyle::getBorderColor()
{
    return addAlphaToColor(borderColor);
}

ofColor ElementStyle::getCaptionColor()
{
    return addAlphaToColor(captionColor);
}


ofColor ElementStyle::addAlphaToColor(ofColor color)
{
    ofColor resultColor = color;
    
    if (alpha < 255) resultColor.a = alpha;
    
    return resultColor;
}
