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
