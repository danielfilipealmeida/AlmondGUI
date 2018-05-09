#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    gui = new GUI();
    
    ofSetWindowTitle("Paginated Viewport");
    ofSetFrameRate(30);
    
    paginatedViewport = gui->add<PaginatedViewport>({});
    
    for (unsigned int f = 0; f < 40; f++)
    {
        Button *button = gui->add<Button>({
            {"caption", "Button #" + ofToString(f+1)}
        });
        paginatedViewport->add(button);
    }
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
    if (key < 49 && key > 51) return;
    paginatedViewport->setPage(key - 49);
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
