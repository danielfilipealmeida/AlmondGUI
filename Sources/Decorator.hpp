//
//  Decorator.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/11/2017.
//

#ifndef Decorator_hpp
#define Decorator_hpp

#include <stdio.h>
#include "Element.hpp"

class Decorator : public Element {
    Element *element;
    
public:
    /*!
     \brief Decorator constructor
     */
    Decorator(Element *_el);
    
    /*!
     \brief Draws the decorator
     */
    void draw(NVGcontext* vg);
    
    /*!
     \brief Sets the decorator
     */
    void set(json config);
    
    /*!
     \brief Updates the decorator and decorated element
     */
    void update();
    
    /*!
     \brief Returns the element where this Decorator is applied to
     */
    Element* getElement();
   
    /*!
     \brief ...
     */
    void setParent(Element *_parent);
    
    /*!
     \brief ...
     */
    void resize(ofRectangle newRect);
};


#endif /* Decorator_hpp */
