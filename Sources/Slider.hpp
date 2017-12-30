//
//  Slider.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 14/09/17.
//
//

#ifndef Slider_hpp
#define Slider_hpp


#include <stdio.h>
#include "Button.hpp"

using json = nlohmann::json;

typedef struct SliderData {
    ofRectangle rect;
    Boolean pressed;
    Boolean pushed;
    Boolean hover;
    float value, maxValue, minValue;
} SliderData;


/*!
 @class Slider
 @abstract Implements a slider from the button
 @discussion Descends from the button but adds new behaviour by allowing the user to drag inside and set a value. This value is between a min and a max.
 */
class Slider : public Button
{
protected:
    std::function<void(Slider *slider)> onChange= NULL;
    float value, maxValue, minValue, defaultValue;
    Boolean showValue;

public:
    
    /*!
     ...
     */
    Slider();
    
    /*!
     ...
     */
    ~Slider();
    
    /*!
     ...
     */
    void update();
    
    /*!
     ...
     */
    void draw(NVGcontext* vg);
    
    /*!
     Calculate the background color according to the slider state
     */
    ofColor getBackgroundColor();
        
    /*!
     ...
     */
    void set(json config);
    
    /*!
     ...
     */
    void setValue(float _value);
    
    /*!
     ...
     */
    float getValue();
    
    /*!
     ...
     */
    void setOnChange(std::function<void(Slider *slider)> _onChange);
    
    /*!
     \brief ...
     */
    virtual string getClass() { return "Slider";}
    
    /*!
     \brief transform the actual value into a corresponding one from 0 to 1
     */
    float getNormalizedValue();
    
    /*!
     \brief transform a normalized value into on that corresponds to a real value inside the slider limits
     */
    float getRealValue(float normalizedValue);
    
    /*!
     \brief Update the value to the default
     */
    void setDefaultValue();

};

#endif /* Slider_hpp */
