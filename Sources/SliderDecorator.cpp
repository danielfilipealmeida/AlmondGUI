//
//  SliderDecorator.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 12/11/2017.
//

#include "SliderDecorator.hpp"
#include "GUIStyle.hpp"
#include "Primitives.hpp"
#include "Slider.hpp"
#include "Viewport.hpp"

void SliderDecorator::draw(NVGcontext* vg)
{
    ofColor backgroundColor = Button::getBackgroundColor(slider.hover, slider.pushed);
    
    Decorator::draw(vg);
    Element::draw(vg);
    drawSlider(vg, slider.value, "", slider.rect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor()), true);
    Element::finishDraw(vg);
}

void SliderDecorator::set(json config)
{
    Decorator::set(config);
    
    ofRectangle _rect = ofRectangle(config["x"].get<float>(),config["y"].get<float>(),config["width"].get<float>(),config["height"].get<float>());
    setSlider(_rect);
    
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
    
    Boolean previousPressed = slider.pressed;
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
            ((Viewport *) Decorator::getElement())->setScrollPositionY(slider.value);
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
