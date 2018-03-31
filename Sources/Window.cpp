//
//  Window.cpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 22/02/2018.
//

#include "Window.hpp"
#include "ofApp.h"
#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"


Window::Window() {
    className = "Window";

}

void* Window::add(void *newElement) {
    // todo: finish
    
    return newElement;
}

ofGLFWWindowSettings Window::getSettings() {
    ofGLFWWindowSettings settings;
    
    settings.width = 200;
    settings.height = 200;
    settings.setPosition(ofVec2f(0,0));
    
    return settings;
}


void Window::createWindow() {
    window = ofCreateWindow(getSettings());
    window->setVerticalSync(false);
    ofAddListener(window->events().draw, this, &Window::drawWithEvents);
    ofAddListener(window->events().update, this, &Window::updateWithEvents);
    ofAddListener(window->events().mouseMoved, this, &Window::mouseMovedWithEvents);
    ofAddListener(window->events().mousePressed, this, &Window::mousePressed);
    
}


void Window::update() {
   if (window == NULL) return;
    Element::update();
}

void Window::updateWithEvents(ofEventArgs & args) {
    setCurrentWindow();
    update();
}



void Window::draw() {
    if (window == NULL) return;
    Element::draw( );
    drawChilds();
    Element::finishDraw( );

}

void Window::drawWithEvents(ofEventArgs & args) {
    draw();
}




void Window::mousePressed(ofMouseEventArgs & mouse) {

}

void Window::mouseMovedWithEvents(ofMouseEventArgs & mouse) {
    window.get()->setWindowTitle(ofToString(mouse.x) + " x " + ofToString(mouse.y));
}

void Window::set(json config) {
    if (window == NULL) createWindow();
}


void Window::setCurrentWindow() {
    if (!window) return;
    
    ofGetMainLoop()->setCurrentWindow(window);
}

Element *Window::addToGUI(json elementData) {
    
}

