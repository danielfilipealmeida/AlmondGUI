//
//  SliderDecorator.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 12/11/2017.
//

#ifndef SliderDecorator_hpp
#define SliderDecorator_hpp

#include <stdio.h>
#include "Decorator.hpp"
#include "Slider.hpp"

/*!
 \brief Implements sliders to be used for scrolling viewport with overflow.
 
 Currently only shows vertical slider.
 TODO: implement horizontal slider and configuration possibility: Vertical, Horizontal, Both
 */
class SliderDecorator : public Decorator
{
    SliderData slider;
    
public:
    /*!
     ...
     */
    SliderDecorator(Element *el): Decorator(el) {}
    
    /*!
     ...
     */
    void draw( );
    
    /*!
     ...
     */
    void set(json config);
    
    /*!
     ...
     */
    void update();
    
    /*!
     ...
     */
    void setParent(Element *_parent);
    
    /*!
     \brief Resizes and updates the decorator and decorated element
     */
    void resize(ofRectangle newRect);
    
    /*!
     ...
     */
    void setSlider(ofRectangle _rect);
};
#endif /* SliderDecorator_hpp */
