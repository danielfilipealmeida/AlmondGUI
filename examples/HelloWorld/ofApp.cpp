#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Hello World");
    ofSetFrameRate(30);
    
    video.load(ofFilePath::getCurrentExeDir() + "../Resources/Loop001.mp4");
    video.play();

    Viewport *viewport = GUI::getInstance().add<Viewport>({
    });
    Button *button = GUI::getInstance().add<Button>({
        {"caption", "Click me!"}
    });
    viewport->add(button);
    
    Label *label1 = GUI::getInstance().add<Label>({
        {"caption", "just a simple label"}
    });
    viewport->add(label1);
    
    button->setOnClick([label1](Button *button) {
        static unsigned int counter = 1;
        label1->set({
            {"caption", "Button Clicked! " + ofToString(counter) + " times"}
        });
        counter++;
    });
    
    Slider *slider = GUI::getInstance().add<Slider>({
        {"caption", "a slider"},
        {"value", 0.5},
        {"minValue", 0},
        {"maxValue", 1}
    });
    viewport->add(slider);
    
    ToggleButton *toggleButton = GUI::getInstance().add<ToggleButton>({
        {"caption" , "a toggle button"}
    });
    viewport->add(toggleButton);
    
    
    ButtonGroup *bGroup = GUI::getInstance().add<ButtonGroup>({
        {"options", {
            {
                {"caption", "A"}
            },
            {
                {"caption", "B"}
            },
            {
                {"caption", "C"}
            },
        }},
        {"x", 0},
        {"y", 0},
        {"height", 32},
        {"width", 100}
    });
    viewport->add(bGroup);
    
    Label *label2 = GUI::getInstance().add<Label>({
        {"caption", "Button Group Label: Nothing pressed yet."}
    });
    viewport->add(label2);
    bGroup->setOnClick([label2](ButtonGroup *bg) {
        ButtonData buttonData = bg->getLastClickedButtonData();
        label2->set({
            {"caption", "Button Group Label: " + buttonData.caption + " pressed."}
        });
    });

    
    fbo.allocate(160, 120);
    Preview *preview = GUI::getInstance().add<Preview>({
        {"caption", "a preview!!!. see some videos playing"}
    });
    preview->setBuffer(&fbo);
    viewport->add(preview);
    
  
    
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
