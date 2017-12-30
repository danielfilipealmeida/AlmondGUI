//
//  Viewport.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 22/09/17.
//
//

#ifndef Viewport_hpp
#define Viewport_hpp

#include <stdio.h>
#include "Element.hpp"


/*!
 \brief Implements a scrollable area that can contain elements. The Element class already allows this but isn't scrollable.
 */
class Viewport : public Element
{
protected:
    
    Element *component;
    float overflowX, overflowY;
    float scrollPositionX, scrollPositionY;
    float totalHeight;
    float totalWidth;

public:
    
    /*!
     ...
     */
    Viewport();
    
    /*!
     ...
     */
    ~Viewport();
    
    /*!
     ...
     */
    void set(json config);
    
    /*!
     ...
     */
    virtual void update();
    
    /*!
     ...
     */
    virtual void draw(NVGcontext* vg);
    
    /*!
     ...
     */
    virtual string getClass() { return "Viewport";}
    
    /*!
     \brief what is this for?
     */
    ofRectangle calculateDrawingRectForElement(Element *element);
    
    /*!
     \brief
     */
    void setScrollPositionY(float position);
    
    /*!
     \brief ...
     */
    void setScrollPositionX(float position);
    
    /*!
     \brief
     */
    float getScrollPositionY();

    /*!
     \brief
     */
    float getScrollPositionX();
    
    /*!
     \brief ...
     */
    float getOverflowX();
    
    /*!
     \brief ...
     */
    float getOverflowY();
    
    /*!
     \brief ...
     */
    float getOffsetX();
    
    /*!
     \brief ...
     */
    float getOffsetY();
    
    
    /*!
     Add a new element to the viewport
     */
    Element *add(Element *newElement);

    void resize(ofRectangle newRect);
    
 
};

#endif /* Viewport_hpp */
