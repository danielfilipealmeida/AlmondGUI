#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    gui = new GUI();
    
    ofSetWindowTitle("Splitters");
    ofSetFrameRate(30);
    
    Splitter *horizontalSpliter = gui->add<Splitter>({
        {"type", (unsigned int) SPLITTER_HORIZONTAL}
    });
    
    Viewport *viewport1 = gui->add<Viewport>({});
    Viewport *viewport2 = gui->add<Viewport>({});
    
    for (unsigned int f = 0; f < 20; f++) {
        Button *button = gui->add<Button>({
            {"caption", "Button " + ofToString(f+1)}
        });
        viewport1->add(button);
        
        Slider *slider = gui->add<Slider>({
            {"caption", "Slider " + ofToString(f+1)},
            {"value", ofRandom(0.0, 1.0)},
            {"minValue", 0.0},
            {"maxValue", 1.0}
        });
        viewport2->add(slider);
    }
    
    horizontalSpliter->add(viewport1, 0.50);
    horizontalSpliter->add(viewport2, 0.50);
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
