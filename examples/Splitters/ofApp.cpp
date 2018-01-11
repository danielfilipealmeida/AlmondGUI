#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Splitters");
    ofSetFrameRate(30);
    
    Splitter *horizontalSpliter = GUI::getInstance().add<Splitter>({
        {"type", (unsigned int) SPLITTER_HORIZONTAL}
    });
    
    Viewport *viewport1 = GUI::getInstance().add<Viewport>({});
    
    
    Viewport *viewport2 = GUI::getInstance().add<Viewport>({});
    
    
    for (unsigned int f = 0; f < 20; f++) {
        Button *button = GUI::getInstance().add<Button>({
            {"caption", "Button " + ofToString(f+1)}
        });
        viewport1->add(button);
        
        Slider *slider = GUI::getInstance().add<Slider>({
            {"caption", "Slider " + ofToString(f+1)}
        });
        viewport2->add(slider);
    }
    
    horizontalSpliter->add(viewport1, 0.50);
    horizontalSpliter->add(viewport2, 0.50);
    
    GUI::getInstance().updateVisibleRects();
     
}

//--------------------------------------------------------------
void ofApp::update(){
    GUI::getInstance().update();
    
    video.update();
    fbo.begin();
    ofSetColor(255,255,255);
    video.draw(0,0,fbo.getWidth(), fbo.getHeight());
    fbo.end();
    
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
