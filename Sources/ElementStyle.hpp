//
//  ElementStyle.hpp
//  AlmondGUI
//
//  Created by Daniel Almeida on 31/12/2017.
//

#ifndef ElementStyle_hpp
#define ElementStyle_hpp

/*!
    The configuration of the style of each element type
 
    This class has all the possible common drawing aspects of an element.
 */

#include <stdio.h>
#include "ofMain.h"
//#include "GUI.hpp"

class ElementStyle {
public:
    Boolean hasBorder;
    ofColor borderColor;
    
    Boolean hasBackground;
    ofColor backgroundColor;
    
    ofColor captionColor;
    //Fonts font;
    
    ElementStyle();
    
    
};

#endif /* ElementStyle_hpp */
