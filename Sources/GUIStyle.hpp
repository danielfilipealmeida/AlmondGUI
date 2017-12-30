//
//  style.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 12/09/17.
//
//

#ifndef style_hpp
#define style_hpp

#include <stdio.h>
#include "ofMain.h"


/*!
 * \brief A class to store a GUI style
 */
class GUIStyle
{
    
    GUIStyle();
    ~GUIStyle();
    
protected:
    
    ofColor baseColor, textColor, backgroundColor, darkColor, lightColor;
    float contrast, brightness, saturation;
    
public:

    /*!
     ...
     */
    static GUIStyle& getInstance();

    /*!
     ...
     */
    GUIStyle(GUIStyle const&) = delete;

    /*!
     ...
     */
    void operator=(GUIStyle const&) = delete;
    
    /*!
     Calculate all colors of the GUI according Contrast/Brightness/Saturation configuration
     */
    void calculateColors();

    /*!
     Text color getter
     */
    ofColor getTextColor();
    
    /*!
     Base color getter
     */
    ofColor getBaseColor();
    
    /*!
     Background color getter
     */
    ofColor getBackgroundColor();
    
    /*!
     Dark color Getter
     */
    ofColor getDarkColor();
    
    /*!
     Light color Getter
     */
    ofColor getLightColor();
    
    /*!
     Brightness getter
     */
    float getBrightness();
    
    /*!
     Saturation getter
     */
    float getSaturation();
    
};


#endif /* style_hpp */
