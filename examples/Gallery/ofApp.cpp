#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    gui = new GUI();
    
    ofSetWindowTitle("Hello World");
    ofSetFrameRate(30);
    
    label = gui->add<Label>({
        {"x", 10},
        {"y", 10},
        {"width", 100},
        {"height", GUI_LINE_HEIGHT * 1.5},
        {"caption", "Label"},
    });
    
    button = gui->add<Button>({
        {"x", 10},
        {"y", 40},
        {"width", 100},
        {"height", GUI_LINE_HEIGHT * 1.5},
        {"caption", "Button"}
    });
    
    slider = gui->add<Slider>({
        {"x", 10},
        {"y", 70},
        {"width", 100},
        {"height", GUI_LINE_HEIGHT * 1.5},
        {"caption", "Slider"},
        {"maxValue", 1.0},
        {"minValue", 0.0},
        {"value", 0.5}
    });
    

    toggle = gui->add<ToggleButton>({
        {"x", 10},
        {"y", 100},
        {"width", 100},
        {"height", GUI_LINE_HEIGHT * 1.5},
        {"caption", "Toggle"},

    });
    
    togglePressed = gui->add<ToggleButton>({
        {"x", 10},
        {"y", 130},
        {"width", 100},
        {"height", GUI_LINE_HEIGHT * 1.5},
        {"caption", "Pressed Toggle"}
    });
    togglePressed->setPushed(true);
    

    
    firstDraw = TRUE;
}

//--------------------------------------------------------------
void ofApp::update(){
    gui->update();
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(GUIStyle::getInstance().getDarkColor());
    gui->draw();
    
    if (firstDraw == FALSE) return;
    
    button->saveScreenshot(ofFilePath::getAbsolutePath("button.png"));
    slider->saveScreenshot(ofFilePath::getAbsolutePath("slider.png"));
    label->saveScreenshot(ofFilePath::getAbsolutePath("label.png"));
    
    toggle->saveScreenshot(ofFilePath::getAbsolutePath("toggle.png"));
    togglePressed->saveScreenshot(ofFilePath::getAbsolutePath("togglePressed.png"));
    
    firstDraw = FALSE;
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
