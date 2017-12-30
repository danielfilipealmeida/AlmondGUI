//
//  Element.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#ifndef Element_hpp
#define Element_hpp

#include <stdio.h>
#include "ofMain.h"
#include "nanovg.h"
#include "json.hpp"


//#define GUIDEBUG

/*!
 GUI definitions for dimensions
 */
#define GUI_LINE_HEIGHT 16
#define GUI_BORDER GUI_LINE_HEIGHT / 4



using json = nlohmann::json;

/*!
 @class Element
 @abstract GUI Root class, from which all other GUI classes descends from
 @discussion Handles basic state and position/size. Possible events are: hover, pressed and entered. TODO (maybe) callbacks for those events. Element can also contain other elements.
 */
class Element 
{
protected:
    Element *parent;
    Boolean hover;
    Boolean pressed;
    Boolean entered;
    Boolean exited;
   
    
public:
    
    /*!
     The rectangle definition in the GUI system.
     */
    ofRectangle rect;
    
    /*!
     The rectangle definition related to the screen.
     Only represents the parts of the element that are visible, since parts can be hidden due to scrolled parents, etc.
     */
    ofRectangle visibleRect;
    
    /*!
     Rectangle definition used for drawing the rectangle.
     This is related to a parent viewport and if the vary from the `rect` if the parent is scrolled
     */
    ofRectangle drawingRect;
    
    /*!
     ...
     */
    Element();
    
    
    /*!
     ...
     */
    ~Element();
    
    
    virtual string getClass() { return "Element";}
    
    /*!
     Checks if the mouse is hover and if the element is being pressed
     */
    virtual void update();
    
    /*!
     Draws. Method to be overriden by childs.
     When overriding this method, the descendent needs always to run this because in here elements inside elements are properly handled.
     */
    virtual void draw(NVGcontext* vg) = 0;
    
    
    /*!
     Finishes drawing the element. Important for properly drawing elements inside other elements.
     */
    void finishDraw(NVGcontext* vg);
    
    /*!
     Sets the Rectangle 
     */
    virtual void set(json config) = 0;
    
    /**
     ...
     */
    std::vector<Element*> getChildElements();
    
    /*!
     \brief Sets the element that will contain this element
     */
    virtual void setParent(Element *_parent);
    
    /*!
     \brief Adds another element as a child
     */
    virtual Element *add(Element *newElement);
    
    /*!
     \brief Traverse parents and calculate the elements visible rect, in screen coordinates.
     
     This is the actual place on the screen this element occupies.
     */
    ofRectangle calculateVisibleRect();
    
    /*!
     \brief Returns the zone to draw
     */
    ofRectangle getDrawingRec();
    
    /*!
     \brief Outputs to stdout the state of the element
     */
    string description();
    
    /*!
     \brief Draws a rect around the visible area of the element for debugging purposes
     */
    void drawDebugRect(NVGcontext* vg);
    
    /*!
     Get the rectangle definition of the element
     */
    ofRectangle getRect();
    
    
    /*!
     \brief Sets the new rect
     */
    virtual void resize(ofRectangle newRect);
    
    /*!
     \brief gets the height for a requested width
     */
    virtual float getHeightForWidth(float _width);
    
    /*!
     \brief Get a visible rect, in the screen coordinates and crop if needed
     
     A returned rect can be croped if it´s inside a viewport that isn't completely visible
     */
    ofRectangle getVisibleRectForRect(ofRectangle _rect);
    
    /*!
     \brief Method to be used to set the value to a default value that should be defined
     
     This method is defined and is empty and should only be overriden where it's needed, like in the Sliders
     */
    virtual void setDefaultValue() {}
    
};

#endif /* Element_hpp */
