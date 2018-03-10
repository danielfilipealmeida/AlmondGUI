//
//  ElementInterface.h
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 03/03/2018.
//

#ifndef ElementInterface_hpp
#define ElementInterface_hpp

class ElementInterface
{
public:
    
    /*!
     \brief Returns a string with the name of the element
    */
    string getClass() {
        return className;
    };
    
    /*!
     \brief Checks if the mouse is hover and if the element is being pressed
     */
    virtual void update() = 0;
    
    /*!
     \brief Draws the element. Method to be overriden by childs.
     
     When overriding this method, the descendent needs always to run this because in here elements inside elements are properly handled.
     */
    virtual void draw() = 0;
    
    /*!
     \brief Finishes drawing the element. Important for properly drawing elements inside other elements.
     */
    virtual void finishDraw() = 0;
    
    /*!
     \brief Sets the element data using the provided json
     
     \param config a JSON variable containing all needed information for configuring the element
     */
    virtual void set(json config) = 0;
    
    /*!
     \brief Sets the visible rectangle configuration
     \param _visibleRect the configuration of the visible rect
     */
    virtual void setVisibleRect(ofRectangle _visibleRect) = 0;
    
    /*!
     \brief Sets the new rect
     \param newRect the definition of the new size and position of the element
     */
    virtual void resize(ofRectangle newRect) = 0;
    
    /*!
     \brief Returns the rect
     */
    ofRectangle getRect() {
        return rect;
    }
    
    /*!
     \brief Returns the visible rect
     */
    ofRectangle getVisibleRect() {
        return visibleRect;
    }
    
    /*!
     \brief Traverse parents and calculate the elements visible rect, in screen coordinates.
     
     This is the actual place on the screen this element occupies.
     */
    virtual ofRectangle calculateVisibleRect() = 0;
    
    /*!
     \brief gets the height for a requested width
     */
    virtual float getHeightForWidth(float _width) = 0;
    
    
    
protected:
    string className;
    
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
    
}; 

#endif /* ElementInterface_h */
