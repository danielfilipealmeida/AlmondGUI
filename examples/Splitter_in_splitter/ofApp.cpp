#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    gui = new GUI();
    
    ofSetWindowTitle("Splitter in Splitter");
    ofSetFrameRate(30);
    
    Splitter *mainSplitter = gui->add<Splitter>({
        {"type", (unsigned int) SPLITTER_HORIZONTAL}
    });
    
    Splitter *subSplitter1 = gui->add<Splitter>({
        {"type", (unsigned int) SPLITTER_VERTICAL}
    });
    Button *button1 = gui->add<Button>({
        {"caption", "button 1"}
    });
    Button *button2 = gui->add<Button>({
        {"caption", "button 2"}
    });
    subSplitter1->add(button1, 0.5);
    subSplitter1->add(button2, 0.5);
    
    
    Splitter *subSplitter2 = gui->add<Splitter>({
        {"type", (unsigned int) SPLITTER_VERTICAL}
    });
    Button *button3 = gui->add<Button>({
        {"caption", "button 3"}
    });
    Button *button4 = gui->add<Button>({
        {"caption", "button 4"}
    });
    subSplitter2->add(button3, 0.5);
    subSplitter2->add(button4, 0.5);
    
    mainSplitter->add(subSplitter1, 0.5);
    mainSplitter->add(subSplitter2, 0.5);
    
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
