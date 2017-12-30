//
//  VerticalSlider.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 23/09/17.
//
//

#ifndef VerticalSlider_hpp
#define VerticalSlider_hpp

#include <stdio.h>
#include "Slider.hpp"

/*!
 @class VerticalSlider
 @abstract A vertical oriented slider without caption (only because I haven't figured out how to rotate the text. this should be changed soon!)
 @discussion
 */
class VerticalSlider : public Slider {
public:
    
    /*!
     ...
     */
    VerticalSlider();
    
    /*!
     ...
     */
    ~VerticalSlider();
    
    /*!
     ...
     */
    void update();
    
    /*!
     ...
     */
    void draw(NVGcontext* vg);
    
    /*!
     ...
     */
    void set(json config);

    /*!
     ...
     */
    virtual string getClass() { return "VerticalSlider";}
    

};
#endif /* VerticalSlider_hpp */
