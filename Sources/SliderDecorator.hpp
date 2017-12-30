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

class SliderDecorator : public Decorator
{
    SliderData slider;
    
public:
    SliderDecorator(Element *el): Decorator(el) {}
    void draw(NVGcontext* vg);
    void set(json config);
    void update();
    void setParent(Element *_parent);
    void resize(ofRectangle newRect);
    void setSlider(ofRectangle _rect);
};
#endif /* SliderDecorator_hpp */
