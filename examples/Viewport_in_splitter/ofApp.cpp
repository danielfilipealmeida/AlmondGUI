#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Viewport in Splitter");
    ofSetFrameRate(30);
    
    Splitter *splitter = GUI::getInstance().add<Splitter>({
        {"type", (unsigned int) SPLITTER_HORIZONTAL}
    });
    
    Viewport *viewport1 = GUI::getInstance().add<Viewport>({});
    SliderDecorator *viewportWithSlider1 = new SliderDecorator(viewport1);
    
    for (unsigned int f = 0; f < 40; f++) {
        viewport1->add(GUI::getInstance().add<Button>({
            {"caption", "Button " + ofToString(f+1) + ". Left."}
        }));
    }
    
    Viewport *viewport2 = GUI::getInstance().add<Viewport>({});
    SliderDecorator *viewportWithSlider2 = new SliderDecorator(viewport2);
    
    for (unsigned int f = 0; f < 40; f++) {
        viewport2->add(GUI::getInstance().add<Button>({
            {"caption", "Button " + ofToString(f+1) + ". Right."}
        }));
    }
    
    splitter->add(viewportWithSlider1, 0.5);
    splitter->add(viewportWithSlider2, 0.5);
}

//--------------------------------------------------------------
void ofApp::update() {
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
