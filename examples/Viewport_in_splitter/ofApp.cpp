#include "ofApp.h"
#include "GUIStyle.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Viewport in Splitter");
    ofSetFrameRate(30);
    
    Splitter *mainSplitter = GUI::getInstance().add<Splitter>({
        {"type", (unsigned int) SPLITTER_HORIZONTAL}
    });
    
    Splitter *subSplitter1 = GUI::getInstance().add<Splitter>({
        {"type", (unsigned int) SPLITTER_VERTICAL}
    });
    
    
    Viewport *viewport1 = GUI::getInstance().add<Viewport>({});
    SliderDecorator *viewportWithSlider1 = new SliderDecorator(viewport1);
    GUI::getInstance().add(viewportWithSlider1);
    
    for (unsigned int f = 0; f < 20; f++) {
        viewport1->add(GUI::getInstance().add<Button>({
            {"caption", "Button " + ofToString(f+1) + ". Left."}
        }));
    }
    
    Viewport *viewport2 = GUI::getInstance().add<Viewport>({});
    SliderDecorator *viewportWithSlider2 = new SliderDecorator(viewport2);
    GUI::getInstance().add(viewportWithSlider2);
    
    for (unsigned int f = 0; f < 20; f++) {
        viewport2->add(GUI::getInstance().add<Button>({
            {"caption", "Button " + ofToString(f+1) + ". Right."}
        }));
    }
    
    subSplitter1->add(viewportWithSlider1, 0.2);
    subSplitter1->add(viewportWithSlider2);
    
    Splitter *subSplitter2 = GUI::getInstance().add<Splitter>({
        {"type", (unsigned int) SPLITTER_VERTICAL}
    });
    
    Viewport *viewport3 = GUI::getInstance().add<Viewport>({});
    SliderDecorator *viewportWithSlider3 = new SliderDecorator(viewport3);
    GUI::getInstance().add(viewportWithSlider3);
    
    for (unsigned int f = 0; f < 20; f++) {
        viewport3->add(GUI::getInstance().add<Button>({
            {"caption", "Button " + ofToString(f+1) + ". Left."}
        }));
    }
    
    Viewport *viewport4 = GUI::getInstance().add<Viewport>({});
    SliderDecorator *viewportWithSlider4 = new SliderDecorator(viewport4);
    GUI::getInstance().add(viewportWithSlider4);
    
    for (unsigned int f = 0; f < 20; f++) {
        viewport4->add(GUI::getInstance().add<Button>({
            {"caption", "Button " + ofToString(f+1) + ". Right."}
        }));
    }
    
    subSplitter2->add(viewportWithSlider3, 0.6);
    subSplitter2->add(viewportWithSlider4);
    
    mainSplitter->add(subSplitter1, 0.4);
    mainSplitter->add(subSplitter2);
    
    
    // right now I need to resize here!
    // should check what happens when I add a viewport to a slider. is it changing the rect?
    //viewport1->resizeToFitContent();
    //viewport2->resizeToFitContent();
    //viewport3->resizeToFitContent();
    //viewport4->resizeToFitContent();

}

//--------------------------------------------------------------
void ofApp::update() {
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
