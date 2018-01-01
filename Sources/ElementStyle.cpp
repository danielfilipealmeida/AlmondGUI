//
//  ElementStyle.cpp
//  AlmondGUI
//
//  Created by Daniel Almeida on 31/12/2017.
//

#include "ElementStyle.hpp"
#include "GUIStyle.hpp"

ElementStyle::ElementStyle() {
    hasBorder = false;
    borderColor = ofColor::black;
    
    hasBackground = false;
    backgroundColor = GUIStyle::getInstance().getBackgroundColor();
    
    captionColor = ofColor::white;
    //font = Text;
}
