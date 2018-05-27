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
#include "ContainerBase.hpp"

/*!
 \brief Implements a scrollable area that can contain elements. The Element class already allows this but isn't scrollable.
 
 rect: the definition of the rectangle of the viewport
 visibleRect: rect translated into screen coordinates
 
 TODO: implement a viewport without FBO's. the idea is to use OpenGL  masking capabilities
 Before drawing, should calculate all childs that are visible on the current viewport config.
 */
class Viewport : public ContainerBase
{
protected:
    
    Element *component;
    float overflowX, overflowY;
    float scrollPositionX, scrollPositionY;
    float totalHeight;
    float totalWidth;
    
   
    /*!
     \brief fbo to store the bitmap contents of the fbo
     */
     ofFbo fbo;

    /*!
     \brief updates the size of the fbo
     */
    void updateFbo();
    
    /*!
     \brief Draws all the viewport childs inside the fbo that is used as the video memory holding the viewport content
     */
    void drawChildsInFbo();
    
    /*!
     \brief Draws the visible part of the fbo on the screen
     */
    void drawFbo();
    
public:
    
    /*!
     \brief todo
     */
    Viewport();
    
    /*!
     \brief todo
     */
    ~Viewport();
    
    /*!
     \brief todo
     */
    void set(json config);
    
    /*!
     \brief todo
     */
    virtual void update();
    
    /*!
     \brief todo
     */
    virtual void draw( );
    
    /*!
     \brief todo
     */
    virtual string getClass() { return "Viewport";}
    
    /*!
     \brief todo
     */
    virtual std::vector<void*> getChildElements();
    

    
    

    /*!
     \brief returns the Y position to be occupied by the next element
     
     \note this probably should be protected
     */
    float getNextElementY();
    
    /*!
     \brief what is this for?
     */
    ofRectangle calculateDrawingRectForElement(Element *element);
    
    /*!
     \brief Manually sets the total height of available space on the viewport.
     
     This shouldn't be used directly and this setter only exists for helping out development
     */
    void setTotalHeight(float height);
    
    /*!
     \brief Manually sets the total width of available space on the viewport.
     
     This shouldn't be used directly and this setter only exists for helping out development
     */
    void setTotalWidth(float width);
    
    /*!
     \brief sets the percentage of scroll in the X axis. from 0 to 1
     */
    void setScrollPositionX(float position);
    
    /*!
     \brief sets the percentage of scroll in the Y axis. from 0 to 1
     */
    void setScrollPositionY(float position);
    
    /*!
     \brief returns the percentage of scroll in the Y axis. from 0 to 1
     */
    float getScrollPositionY();

    /*!
     \brief returns the percentage of scroll in the X axis. from 0 to 1
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
    void* add(void *newElement);
    
    /*!
     \brief Resizes the viewport to the required rect
     \param newRect the new size of the viewport
     */
    void resize(ofRectangle newRect);
    
    /*!
     \brief Resizes the Viewport to fit the total of it's content
     
     Traverses all the childs of the viewport and calculate all ocuppied space
     */
    void resizeInnerRectToFitContent();
    
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
     \brief Tells of the viewport can scroll
     
     \returns true or false
     */
    Boolean canScroll();
    
    /*!
     \brief Returns the rectangular definition of the viewport inner rectangle
     
     \return ofRectangle
     */
    ofRectangle getFullRect();
};

#endif /* Viewport_hpp */
