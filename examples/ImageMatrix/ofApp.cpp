#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    gui = new GUI();
    
    ofSetWindowTitle("Image Matrix");
    ofSetFrameRate(30);
    
    imageMatrix = new ImageMatrix();
    imageMatrix->set({
        {"x", 100},
        {"y", 100},
        {"width", 400},
        {"height", 300},
        {"columns", 4},
        {"rows", 3}
    });
    gui->add(imageMatrix);
    
    resourcesPath = ofFilePath::getCurrentWorkingDirectory();
    imageMatrix->addImage(new ofImage(resourcesPath + "/001.png"), 0, 0);
    imageMatrix->addImage(new ofImage(resourcesPath + "/002.png"), 1, 1);
    imageMatrix->addImage(new ofImage(resourcesPath + "/003.png"), 2, 2);
    imageMatrix->addImage(new ofImage(resourcesPath + "/004.png"), 3, 2);
    imageMatrix->addImage(new ofImage(resourcesPath + "/005.png"), 1, 2);
    imageMatrix->addImage(new ofImage(resourcesPath + "/006.png"), 4, 4); // <-- this wont show because it's outside the matrix. it will be ignored
    
    imageMatrix->setOnClick([this](ImageMatrix *imageMatrix) {
        std::pair<int, int> lastClickedCell = imageMatrix->getLastPressedCell();
        int column = lastClickedCell.first;
        int row = lastClickedCell.second;
        if (column < 0) return;
        if (row < 0) return;
        
        this->label->set({
            {"caption", "Cell: " + ofToString(column) + ", " + ofToString(row)}
        });
    });
    
    label = new Label();
    label->set({
        {"x", 100},
        {"y", 60},
        {"width", 400},
        {"height",40},
        {"caption", "[nothing selected yet]"}
    });
    gui->add(label);
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
