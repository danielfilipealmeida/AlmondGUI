#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Hello World");
    
    Viewport *viewport = GUI::getInstance().add<Viewport>({
        {"x", 100},
        {"y", 100},
        {"width", 200},
        {"height", 100}
    });
    
    Button *button = GUI::getInstance().add<Button>({
        {"caption", "Click me!"}
    });
    viewport->add(button);
    
    Label *label = GUI::getInstance().add<Label>({
        {"caption", "just a simple label"}
    });
    viewport->add(label);
    
    button->setOnClick([label](Button *button) {
        static unsigned int counter = 1;
        label->set({
            {"caption", "Button Clicked! " + ofToString(counter) + " times"}
        });
        counter++;
    });
    
    Slider *slider = GUI::getInstance().add<Slider>({
        {"caption", "a slider"},
        {"value", 0.5},
        {"minValue", 0},
        {"maxValue", 1}
    });
    viewport->add(slider);
    
    viewport->setTotalHeight(300);
    viewport->setScrollPositionY(0.1);
    GUI::getInstance().updateVisibleRects();
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
