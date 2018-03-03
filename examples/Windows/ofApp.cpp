#include "ofApp.h"
#include "GUIStyle.hpp"


ofApp* instance = NULL;

//--------------------------------------------------------------
void ofApp::setup(){
    instance = this;
    
    ofSetWindowTitle("Hello World");
    ofSetFrameRate(30);
    
    Button *button1 = GUI::getInstance().add<Button>({
        {"x", 20},
        {"y", 20},
        {"width", 120},
        {"height", 30},
        {"caption", "button 1"}
    });
    
    Window *secondWindow = GUI::getInstance().add<Window>({
        {"x", 10},
        {"y", 10},
        {"height", 400},
        {"width", 400}
    });
    //button1->setParent(secondWindow);
    //Window *secondWindow = new Window();
    //secondWindow->createWindow();
    /*
    Window *secondWindow = GUI::getInstance().add<Window>({
        {"x", 10},
        {"y", 10},
        {"height", 400},
        {"width", 400}
    });
     */
    
    secondWindow->add(button1);
    //button1->setParent(secondWindow);
    //secondWindow->setCurrentWindow();
    
}

static ofApp* getInstance() {
    return instance;
}

//--------------------------------------------------------------
void ofApp::update(){
    GUI::getInstance().update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(GUIStyle::getInstance().getDarkColor());
    
    GUI::getInstance().draw();
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
