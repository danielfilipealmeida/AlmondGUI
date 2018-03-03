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
#include "json.hpp"
#include "ElementStyle.hpp"
#include "GUIStyle.hpp"



/*!
 GUI definitions for dimensions
 */
#define GUI_LINE_HEIGHT 16
#define GUI_BORDER GUI_LINE_HEIGHT / 4



using json = nlohmann::json;

/*!
 \brief GUI Root class, from which all other GUI classes descends from

 Handles basic state and position/size. Possible events are: hover, pressed and entered. TODO (maybe) callbacks for those events. Element can also contain other elements.
 
 WORK TODO:
 
 standartize the usage of rects. they need to follow the rules:
 
 rect:
 the rect definition of the current element. it should be (0,0, totalHeigth, totalWidth);
 
 clipRect:
 the definition of printed part of the rect. If the rect is clipped (allows scrolling), this should define wich part is being displayed.
 this means that this rect cannot go outside the rect.
 Need to take into consideration if this element is inside other element.
 
 visibleRect:
 need to sort this out. suposibly this should be the final position of the rect in the screen and it is use to handle mouse hover events.
 
 Important to figure out:
 how to handle elements inside elements.
 */
class Element
{
protected:
    Element *parent;
    Boolean hover;
    Boolean pressed;
    Boolean entered;
    Boolean exited;
    Boolean dragging;
    ElementStyle style;
    
    /*!
        Returns true if a dragging event is happening
     
        Dragging happens whtn the mouse is clicked and the the click
        value is the same as before
     */
    Boolean checkIsDragging();
    
public:
    
    /*!
     \brief The rectangle definition in the GUI system.
     */
    ofRectangle rect;
    
    /*!
     \brief The rectangle definition related to the screen.
     
     Only represents the parts of the element that are visible, since parts can be hidden due to scrolled parents, etc.
     */
    ofRectangle visibleRect;
    
    /*!
     \brief Rectangle definition used for drawing the rectangle.
     
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
    
    /*!
     ...
     */
    virtual string getClass() { return "Element"; }
    
    /*!
     \brief Checks if the mouse is hover and if the element is being pressed
     */
    virtual void update();
    
    /*!
     \brief Draws the element. Method to be overriden by childs.
     
     When overriding this method, the descendent needs always to run this because in here elements inside elements are properly handled.
     */
    virtual void draw() = 0;
    
    /*!
     \brief Finishes drawing the element. Important for properly drawing elements inside other elements.
     */
    void finishDraw();
    
    /*!
     \brief Draws all the childs of the current element
     */
    void drawChilds();
    
    /*!
     \brief Sets the Rectangle
     */
    virtual void set(json config) = 0;
    
    /**
     \brief Returns all the children of this element
     TODO: move this to the GUI. element should not have access to this
     */
    //std::vector<Element*> getChildElements();
    
    /*!
     \brief Sets the element that will contain this element
     */
    virtual void setParent(Element *_parent);
    
    /*!
     \brief Returns the parent
     */
    Element* getParent() { return parent; }
    
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
    void drawDebugRect();
    
    /*!
     \brief Get the rectangle definition of the element
     */
    virtual ofRectangle getRect();
    
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
     
     \param _rect rectangle from which the visible part is requested
     \return the visible part of the input rectangle
     */
    ofRectangle getVisibleRectForRect(ofRectangle _rect);
    
    /*!
     \brief Method to be used to set the value to a default value that should be defined
     
     This method is defined and is empty and should only be overriden where it's needed, like in the Sliders
     */
    virtual void setDefaultValue() {}
    
    
    /*!
     \brief gets a dump of the state of the element in json format
     
     This will be used to generate the string dump
     */
    json jsonDump();
    
    /*!
     \brief Get a dump of all data of the element
     
     \return a string representing the state of the element
     */
    string dump();
    
    /*!
     \brief Tells if the element has a bigger rect than the visible rect definition
     */
    virtual Boolean canScroll();
};

#endif /* Element_hpp */
