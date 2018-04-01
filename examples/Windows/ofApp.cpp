#include "ofApp.h"
#include "GUIStyle.hpp"


ofApp* instance = NULL;

//--------------------------------------------------------------
void ofApp::setup(){
    instance = this;
    
    ofSetWindowTitle("Hello World");
    ofSetFrameRate(30);
    
    gui = new GUI();
    
    Button *button1 = gui->add<Button>({
        {"x", 20},
        {"y", 20},
        {"width", 120},
        {"height", 30},
        {"caption", "button 1"}
    });
    
    Window *secondWindow = gui->add<Window>({
        {"x", 10},
        {"y", 10},
        {"height", 400},
        {"width", 400}
    });
    
    secondWindow->add(button1);
}

static ofApp* getInstance() {
    return instance;
}

//--------------------------------------------------------------
void ofApp::update(){
    gui->update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(GUIStyle::getInstance().getDarkColor());
    
    gui->draw();
    
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
