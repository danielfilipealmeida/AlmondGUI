#include "ofApp.h"
#include "GUIStyle.hpp"
#include "GUI.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Viewport example");
    
    gui = new GUI();
    
    gui->loadFonts();
    
    Viewport *viewport = gui->add<Viewport>({});
    SliderDecorator *viewportWithSlider = new SliderDecorator(viewport);
    viewportWithSlider->set({
        {"x", 10},
        {"y", 10},
        {"width", 320},
        {"height", 240}
    });
    
    gui->add(viewportWithSlider);
    
    Label *label = gui->add<Label>({
        {"caption", "Presenting a Viewport"}
    });
    viewport->add(label);
    
    for(auto f=0; f < 20; f++) {
        viewport->add(gui->add<Button>({
            {"caption", "Button # " + ofToString(f+1)}
        }));
        viewport->add(gui->add<Slider>({
            {"caption", "Slider # " + ofToString(f+1)},
            {"minValue", 0},
            {"maxValue", 1},
            {"value", ofRandom(0, 1)}
        }));
    }
    
    viewport->setScrollPositionY(0.0);
     gui->updateVisibleRects();
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
