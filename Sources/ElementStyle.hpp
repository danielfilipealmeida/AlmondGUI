//
//  ElementStyle.hpp
//  AlmondGUI
//
//  Created by Daniel Almeida on 31/12/2017.
//

#ifndef ElementStyle_hpp
#define ElementStyle_hpp


#include "json.hpp"

using json = nlohmann::json;

/*!
    \brief The configuration of the style of each element type
 
    This class has all the possible common drawing aspects of an element.
 */

#include <stdio.h>
#include "ofMain.h"
//#include "GUI.hpp"

class ElementStyle {

public:
    // todo: move all variables to protected
    Boolean hasBorder;
    ofColor borderColor, focusedColor;
    
    Boolean hasBackground;
    ofColor backgroundColor;
    
    ofColor captionColor;
    unsigned char alpha;
    
    ElementStyle();
    
    void setAlpha(float _alpha);
    
    /*!
     \brief Adds alpha information to a color if it is set
     */
    ofColor addAlphaToColor(ofColor color);
    
    /*!
     \brief Returns the background color with alpha value if alpha is set to less than 1.0
     */
    ofColor getBackgroundColor();
    
    /*!
     \brief Returns the border color with alpha value if alpha is set to less than 1.0
     */
    ofColor getBorderColor();
    
    /*!
     \brief Returns the caption color with alpha value if alpha is set to less than 1.0
     */
    ofColor getCaptionColor();
    
    json jsonDump();
};

#endif /* ElementStyle_hpp */
