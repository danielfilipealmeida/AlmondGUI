#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    gui = new GUI();
    
    ofSetWindowTitle("Hello World");
    ofSetFrameRate(30);
    
    // Viewport (to gather all inside)
    Viewport *viewport = gui->add<Viewport>({});
    Button *button = gui->add<Button>({
        {"caption", "Click me!"}
    });
    viewport->add(button);
    
    
    // Button (plus label)
    Label *label1 = gui->add<Label>({
        {"caption", "just a simple label"}
    });
    label1->getStyle()->setAlpha(127);
    viewport->add(label1);
    
    button->setOnClick([label1](Button *button) {
        static unsigned int counter = 1;
        label1->set({
            {"caption", "Button Clicked! " + ofToString(counter) + " times"}
        });
        counter++;
    });
    button->getStyle()->setAlpha(127);
    
    
    // Slider
    Slider *slider = gui->add<Slider>({
        {"caption", "a slider"},
        {"value", 0.5},
        {"minValue", 0},
        {"maxValue", 1}
    });
    slider->getStyle()->setAlpha(127);
    viewport->add(slider);
    slider->setOnChange([](Slider *slider) {
        slider->set({
            {"caption", "Slider value: " + ofToString(slider->getValue()) + "!"}
        });
    });
    
    
    // ToggleButton
    ToggleButton *toggleButton = gui->add<ToggleButton>({
        {"caption" , "a toggle button"}
    });
    toggleButton->getStyle()->setAlpha(127);
    viewport->add(toggleButton);
    

    // ButtonGroup (plus label)
    ButtonGroup *bGroup = gui->add<ButtonGroup>({
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
    bGroup->getStyle()->setAlpha(127);
    viewport->add(bGroup);
    
    Label *label2 = gui->add<Label>({
        {"caption", "Button Group Label: Nothing pressed yet."}
    });
    viewport->add(label2);
    
    bGroup->setOnClick([label2](ButtonGroup *bg) {
        ButtonData buttonData = bg->getLastClickedButtonData();
        label2->set({
            {"caption", "Button Group Label: " + buttonData.caption + " pressed."}
        });
    });

    
    // Preview & playing video
    video.load(ofFilePath::getCurrentExeDir() + "../Resources/Loop001.mp4");
    video.play();
    fbo.allocate(160, 120);
    Preview *preview = gui->add<Preview>({
        {"caption", "a preview!!!. see some videos playing"}
    });
    preview->setBuffer(&fbo);
    preview->getStyle()->setAlpha(127);
    viewport->add(preview);
    
  
    
    gui->updateVisibleRects();
     
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
