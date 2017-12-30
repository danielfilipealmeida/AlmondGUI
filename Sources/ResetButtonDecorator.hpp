//
//  ResetButtonDecorator.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/11/2017.
//

#ifndef ResetButtonDecorator_hpp
#define ResetButtonDecorator_hpp

#include <stdio.h>
#include "Decorator.hpp"
#include "Button.hpp"

class ResetButtonDecorator : public Decorator
{
    ButtonData resetButton;
    
public:
    ResetButtonDecorator(Element *el): Decorator(el) {}
    void draw(NVGcontext* vg);
    void set(json config);
    void update();
    void setParent(Element *_parent);
    void resize(ofRectangle newRect);
    void setResetButton(ofRectangle _rect);
};

#endif /* ResetButtonDecorator_hpp */
