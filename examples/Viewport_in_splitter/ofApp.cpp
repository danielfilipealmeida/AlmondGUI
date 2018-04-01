#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    gui = new GUI();
    
    ofSetWindowTitle("Viewport in Splitter");
    ofSetFrameRate(30);
    
    Splitter *mainSplitter = gui->add<Splitter>({
        {"type", (unsigned int) SPLITTER_HORIZONTAL}
    });
    
    Splitter *subSplitter1 = gui->add<Splitter>({
        {"type", (unsigned int) SPLITTER_VERTICAL}
    });
    
    Viewport *viewport1 = gui->add<Viewport>({});
    SliderDecorator *viewportWithSlider1 = new SliderDecorator(viewport1);
    gui->add(viewportWithSlider1);
    
    for (unsigned int f = 0; f < 10; f++) {
        Slider *slider = new Slider();
        slider->set({
            {"caption", "Slider " + ofToString(f+1) + ". Left."},
            {"minValue", 0.0},
            {"maxValue", 1.0},
            {"value", ofRandom(1.0)}
        });
        ResetButtonDecorator *sliderWithReset = new ResetButtonDecorator(slider);
        gui->add(sliderWithReset);
        viewport1->add(sliderWithReset);
    }
    
    Viewport *viewport2 = gui->add<Viewport>({});
    SliderDecorator *viewportWithSlider2 = new SliderDecorator(viewport2);
    gui->add(viewportWithSlider2);
    
    for (unsigned int f = 0; f < 20; f++) {
        viewport2->add(gui->add<Button>({
            {"caption", "Button " + ofToString(f+1) + ". Right."}
        }));
    }
    
    subSplitter1->add(viewportWithSlider1, 0.7);
    subSplitter1->add(viewportWithSlider2);
    
    Splitter *subSplitter2 = gui->add<Splitter>({
        {"type", (unsigned int) SPLITTER_VERTICAL}
    });
    
    Viewport *viewport3 = gui->add<Viewport>({});
    SliderDecorator *viewportWithSlider3 = new SliderDecorator(viewport3);
    gui->add(viewportWithSlider3);
    
    for (unsigned int f = 0; f < 20; f++) {
        viewport3->add(gui->add<Button>({
            {"caption", "Button " + ofToString(f+1) + ". Left."}
        }));
    }
    
    Viewport *viewport4 = gui->add<Viewport>({});
    SliderDecorator *viewportWithSlider4 = new SliderDecorator(viewport4);
    gui->add(viewportWithSlider4);
    
    for (unsigned int f = 0; f < 20; f++) {
        viewport4->add(gui->add<Button>({
            {"caption", "Button " + ofToString(f+1) + ". Right."}
        }));
    }
    
    subSplitter2->add(viewportWithSlider3, 0.6);
    subSplitter2->add(viewportWithSlider4);
    
    mainSplitter->add(subSplitter1, 0.4);
    mainSplitter->add(subSplitter2);
}

//--------------------------------------------------------------
void ofApp::update() {
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
