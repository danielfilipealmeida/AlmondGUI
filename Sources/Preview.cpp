//
//  Preview.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 17/10/2017.
//

#include "Preview.hpp"
#include "GUIStyle.hpp"

Preview::Preview() {
    fbo = NULL;
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
    if (parent!=NULL) {
        fboRect.x = fboRect.x + this->parent->getRect().x;
        fboRect.y = fboRect.y + this->parent->getRect().y;
    }
    fbo->draw(fboRect);
    
    
    Element::draw( );
    /*
    n BeginPath( );
    n Rect( , drawingRect.x, drawingRect.y, drawingRect.width, drawingRect.height);
    n StrokeColor( , ofColor2N Color(ofColor::black, 255));
    n Stroke( );
     */
    
    if (!caption.empty()) {
        ofRectangle captionRect;
        captionRect.x = drawingRect.x + 2;
        captionRect.y = drawingRect.y + 2;
        captionRect.width = 72;
        captionRect.height = 20;
        /*
        drawFilledRect( , captionRect, ofColor2N Color(ofColor::black));
        printCenteredText( , caption, captionRect, ofColor2N Color(ofColor::white));
         */
        // todo: draw caption
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
