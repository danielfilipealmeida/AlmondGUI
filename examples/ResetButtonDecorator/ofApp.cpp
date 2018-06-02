#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    gui = new GUI();
    
    ofSetWindowTitle("ResetButtonDecorator Example");
    ofSetFrameRate(30);
    
    // Viewport (to gather all inside)
    Viewport *viewport = gui->add<Viewport>({
        {"x", 100},
        {"y", 100},
        {"width", 200},
        {"height", 200}
    });
    
    
    Slider *slider = new Slider();
    slider->set({
        {"caption", "a slider"},
        {"value", 0.2},
        {"minValue", 0.0},
        {"maxValue", 1.0}
    });
    ResetButtonDecorator *decorator = new ResetButtonDecorator(slider);
    decorator->setParent(viewport);
    gui->add(decorator);
    viewport->add(decorator);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    gui->update();
    
    video.update();
    fbo.begin();
    ofSetColor(255,255,255);
    video.draw(0,0,fbo.getWidth(), fbo.getHeight());
    fbo.end();
    
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
