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
    Window();
    ~Window() {};
    
    void createWindow();

    /*!
     \brief Returns the name of the class
     */
    string getClass() { return "Window"; }
    
    Element *addToGUI(json elementData);
    
    void* add(void *newElement);
    
    /*!
     \brief Checks if the mouse is hover and if the element is being pressed
     */
    void update();
    
        void updateWithEvents(ofEventArgs & args);
    
    /*!
     \brief Draws
    */
    void draw();
    
    /*!
     \brief Draws
     */
    void drawWithEvents(ofEventArgs & args);
    
    void mousePressed(ofMouseEventArgs & mouse);
    
    void mouseMovedWithEvents(ofMouseEventArgs & mouse);

    
    /*!
     \brief Sets the Window
     */
    void set(json config);
    
    void setCurrentWindow();
};

#endif /* Window_hpp */
