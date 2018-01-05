#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Viewport example");
    
    //Viewport *viewport = new Viewport();
    Viewport *viewport = GUI::getInstance().add<Viewport>({});
    SliderDecorator *viewportWithSlider = new SliderDecorator(viewport);
    viewportWithSlider->set({
        {"x", 10},
        {"y", 10},
        {"width", 320},
        {"height", 240}
    });
    
    
    GUI::getInstance().add(viewportWithSlider);
    
    Label *label = GUI::getInstance().add<Label>({
        {"caption", "Presenting a Viewport"}
    });
    viewport->add(label);
    
    for(auto f=0; f < 20; f++) {
        viewport->add(GUI::getInstance().add<Button>({
            {"caption", "Button # " + ofToString(f+1)}
        }));
        viewport->add(GUI::getInstance().add<Slider>({
            {"caption", "Slider # " + ofToString(f+1)},
            {"minValue", 0},
            {"maxValue", 1},
            {"value", ofRandom(0, 1)}
        }));
    }
    
    viewport->setScrollPositionY(0.0);
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
