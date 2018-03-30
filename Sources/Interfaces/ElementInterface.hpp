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
    
    virtual string getIdentifier() = 0;
    
    /*!
     \brief Returns a string with the name of the element
    */
    virtual string getClass() = 0;
    
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
    virtual ofRectangle getRect() = 0;
    
    /*!
     \brief Returns the visible rect
     */
    virtual ofRectangle getVisibleRect() = 0;
    
    /*!
     \brief Traverse parents and calculate the elements visible rect, in screen coordinates.
     This is the actual place on the screen this element occupies.
     */
    virtual ofRectangle calculateVisibleRect() = 0;
    
    /*!
     \brief gets the height for a requested width
     */
    virtual float getHeightForWidth(float _width) = 0;
    
}; 

#endif /* ElementInterface_h */
