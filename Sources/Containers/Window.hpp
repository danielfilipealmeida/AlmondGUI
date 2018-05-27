//
//  Window.hpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 22/02/2018.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>
#include "ContainerBase.hpp"
#include "ofAppGLFWWindow.h"
#include "GUI.hpp"

/*!
 \brief Implements Windows with Interface
 
 A window has it's own interface structure
 */
class Window : public ofBaseApp, public ContainerBase
{
    shared_ptr<ofAppBaseWindow> window = NULL;
    ofGLFWWindowSettings getSettings();
    Element *topElement;
    
    
public:
    /*!
     \brief todo
     */
    Window();
    
    /*!
     \brief todo
     */
    
    ~Window() {};
    
    /*!
     \brief todo
     */
    void createWindow();

    /*!
     \brief Returns the name of the class
     */
    string getClass() { return "Window"; }
    
    /*!
     \brief todo
     */
    Element *addToGUI(json elementData);
    
    /*!
     \brief todo
     */
    void* add(void *newElement);
    
    /*!
     \brief Checks if the mouse is hover and if the element is being pressed
     */
    void update();
    
    
    /*!
     \brief todo
     */
    void updateWithEvents(ofEventArgs & args);
    
    /*!
     \brief Draws
    */
    void draw();
    
    /*!
     \brief Draws
     */
    void drawWithEvents(ofEventArgs & args);
    
    /*!
     \brief todo
     */
    void mousePressed(ofMouseEventArgs & mouse);
    
    /*!
     \brief todo
     */
    void mouseMovedWithEvents(ofMouseEventArgs & mouse);

    
    /*!
     \brief Sets the Window
     */
    void set(json config);
    
    /*!
     \brief todo
     */
    void setCurrentWindow();
};

#endif /* Window_hpp */
