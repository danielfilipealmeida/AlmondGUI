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

/*!
 \brief Decorates an element by adding a botton with an `X` to be used next to sliders or toggles or other elements that can have default data.
 */
class ResetButtonDecorator : public Decorator
{
    ButtonData resetButton;
    
public:
    /*!
     \brief constructor
     */
    ResetButtonDecorator(Element *el): Decorator(el) {}
    
    /*!
     \brief Draws the decorator and the decorated element
     */
    void draw();
    
    /*!
     \brief Draws the button
     */
    void drawButton();
    
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
     ...
     */
    void resize(ofRectangle newRect);
    
    /*!
     ...
     */
    void setResetButton(ofRectangle _rect);
    
    /*!
     \brief returns the rect of the decorated element
     
     Contains the element and it's decorator
     */
    virtual ofRectangle getRect();
};

#endif /* ResetButtonDecorator_hpp */
