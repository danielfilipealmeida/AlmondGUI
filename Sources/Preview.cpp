//
//  Preview.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 17/10/2017.
//

#include "Preview.hpp"
#include "GUIStyle.hpp"
#include "GUI.hpp"

Preview::Preview() {
    fbo = NULL;
    style.hasBorder = true;
    style.hasBackground = true;
}

Preview::~Preview()  {
    
}


void Preview::set(json config) {
    if (!config["x"].is_number()) config["x"] = 0;
    if (!config["y"].is_number()) config["y"] = 0;
    if (!config["width"].is_number()) config["width"] = ofGetWidth();
    if (!config["height"].is_number()) config["height"] = ofGetHeight();
    if (config["caption"].is_string()) caption = config["caption"].get<string>();
    
    Element::set(config);
}



void Preview::update() {
    Element::update();
}



void Preview::draw( ) {
    //Element::draw( );
    if (fbo == NULL) return;
    
    ofRectangle drawingRect = Element::getDrawingRec();
    
    ofRectangle fboRect = drawingRect;
    /*
     // todo: check if this is really needed. it shouldn't
    if (parent!=NULL) {
        fboRect.x = fboRect.x + this->parent->getRect().x;
        fboRect.y = fboRect.y + this->parent->getRect().y;
    }
     */
    Element::draw( );
    ofSetColor(255,255,255,255);
    fbo->draw(rect);
    
    if (!caption.empty()) {
        ofRectangle captionRect;
        ofRectangle stringRect = getFont(Text).getStringBoundingBox(caption, 0,0);
        
        captionRect.x = drawingRect.x + 2;
        captionRect.y = drawingRect.y + 2;
        captionRect.width = stringRect.width + 4;
        captionRect.height = stringRect.height + 4;
       
        ofSetColor(0,0,0);
        ofFill();
        ofDrawRectangle(captionRect);
        ofSetColor(style.captionColor);
        GUI::drawCenteredText(caption, captionRect);
    }
    Element::finishDraw( );
}


void Preview::setBuffer(ofFbo *_fbo) {
    fbo = _fbo;
}


float Preview::getHeightForWidth(float _width) {
    float height, originalAspectRatio;
    
    originalAspectRatio = (fbo != NULL) ? (fbo->getTexture().texData.tex_w / fbo->getTexture().texData.tex_h) : (4.0/3.0);
    
    return _width / originalAspectRatio;
}
