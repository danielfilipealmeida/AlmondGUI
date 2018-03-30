#include "ofApp.h"
#include "GUIStyle.hpp"
#include "Table.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    gui = new GUI();
    
    ofSetWindowTitle("Table Example");
    ofSetFrameRate(30);
    
    Table *table = gui->add<Table>({
        {"x", 10},
        {"y", 10},
        {"width", 400},
        {"height", 400},
        {"nRows", 4},
        {"nColumns", 4},
        {"allowResize", false}
    });
    
    Button *button1 = gui->add<Button>({
         {"caption", "a button"}
    });
    table->pushElement(button1, 0, 0);
    
    Slider *slider1 = gui->add<Slider>({
        {"caption", "a slider"},
        {"minValue", 0},
        {"maxValue", 1},
        {"value", 0.3}
    });
    table->pushElement(slider1, 1, 1);
    
    ToggleButton *toggle1 = gui->add<ToggleButton>({
        {"caption", "a toggle button"}
    });
    table->pushElement(toggle1, 2, 2);
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
