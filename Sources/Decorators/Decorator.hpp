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


/*!
 \brief Implements the Decorator Class, needed for the Decoractor Pattern.
 
 A decorator is an adition to GUI element. It can be implemented in any way that the developer sees fit.
 Examples are the usage of 1 or more gui elements, or
 
 */
class Decorator : public Element {
    
    Element *element; //!< The decorated element 
    
public:
    /*!
     \brief Decorator constructor
     
     \param Element* the object to decorate
     */
    Decorator(Element *_el);
    
    /*!
     \brief Draws the decorator
     */
    void draw();
    
    /*!
     \brief Sets the decorator configuration
     
     \param json the configuration of the decorator in JSON format
     */
    void set(json config);
    
    /*!
     \brief Updates the decorator and decorated element
     */
    void update();
    
    /*!
     \brief Returns the element where this Decorator is applied to
     
     \return Element* gets the decorated element
     */
    Element* getElement();
   
    /*!
     \brief Sets the parent of the decorator and the decorated element
     
     \param Element* the parent element
     */
    void setParent(Element *_parent);
    
    /*!
     \brief Sets the dimensions of the total area ocupied by decorator and decorated element.
     
     This will properly setup the rects of both decorated elements and the decorator.
     */
    void resize(ofRectangle newRect);
    
    /*!
     \brief Tells of the decorated element can scroll
     */
    Boolean elementCanScroll();
};


#endif /* Decorator_hpp */
