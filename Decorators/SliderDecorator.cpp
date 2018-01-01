//
//  SliderDecorator.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 12/11/2017.
//

#include "SliderDecorator.hpp"
#include "GUIStyle.hpp"
#include "Slider.hpp"
#include "Viewport.hpp"
#include "GUI.hpp"

void SliderDecorator::draw( )
{
    ofColor backgroundColor = Button::getBackgroundColor(slider.hover, slider.pushed);
    Decorator::draw();
    Element::draw();
    
    // todo: move the following code somewhere to have a slider reusable
    ofSetColor(backgroundColor + 40);
    ofFill();
    ofDrawRectangle(slider.rect.x, slider.rect.y, slider.rect.width , slider.rect.height *  slider.value);
    ofNoFill();
    ofSetColor(ofColor::black);
    ofDrawRectangle(slider.rect);
    
    Element::finishDraw( );
}

/* TODO: this needs to be remake and cleaned up */
void SliderDecorator::set(json config)
{
    Decorator::set(config);
    
    ofRectangle _rect = ofRectangle(config["x"].get<float>(),
                                    config["y"].get<float>(),
                                    config["width"].get<float>(),
                                    config["height"].get<float>());
    setSlider(_rect);
    config["width"] = config["width"].get<float>() - slider.rect.width;
    
    getElement()->set(config);
}

void SliderDecorator::setSlider(ofRectangle _rect) {
    slider.rect.width = GUI_LINE_HEIGHT;
    slider.rect.height = _rect.height;
    slider.rect.y = _rect.y;
    slider.rect.x = _rect.x + _rect.width - slider.rect.width;
    
    slider.maxValue = 1.0;
    slider.minValue = 0.0;
}

void SliderDecorator::update()
{
    Decorator::update();
    
    Boolean previousHover = slider.hover;
    ofRectangle visibleRect;
    
    visibleRect = slider.rect;
    if (parent != NULL) {
        visibleRect.x = visibleRect.x + parent->rect.x;
        visibleRect.y = visibleRect.y + parent->rect.y;
    }
    
    slider.hover = visibleRect.inside(ofGetMouseX(), ofGetMouseY());
    if (slider.hover) {
        slider.pressed = (ofGetMousePressed() > 0);
        slider.pushed = (slider.pressed == true && previousHover == true) ? true : false;
        
        if (slider.pushed) {
            slider.value = (ofGetMouseY() - visibleRect.y) / (rect.height);
            Viewport *viewport= ((Viewport *) Decorator::getElement());
            viewport->setScrollPositionY(slider.value);
            viewport->update();
        }
        
    }
    else {
        slider.pressed = false;
        slider.pushed = false;
    }
}

void SliderDecorator::setParent(Element *_parent)
{
    Decorator::setParent(_parent);
}

void SliderDecorator::resize(ofRectangle newRect)
{
    setSlider(newRect);
    newRect.width = newRect.width - slider.rect.width - (GUI_BORDER / 2.0);
    Decorator::resize(newRect);
    
}
