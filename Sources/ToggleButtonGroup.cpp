//
//  ToggleButtonGroup.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "ToggleButtonGroup.hpp"
#include "GUI.hpp"
#include "GUIStyle.hpp"
#include "Primitives.hpp"



void ToggleButtonGroup::addButton(json::iterator it) {
    auto jsonData = *it;
    ButtonData newButtonData;
    
    newButtonData.caption = jsonData["title"];
    newButtonData.rect = ofRectangle(currentX, 0, buttonsWidth, rect.height);
    newButtonData.pressed = false;
    newButtonData.pushed = (jsonData["value"].is_number() && jsonData["value"].get<unsigned int>() == value) ? true : false;
    newButtonData.value = (jsonData["value"].is_number()) ? jsonData["value"].get<unsigned int>() : 0;
    
    
    buttons.push_back(newButtonData);
}

void ToggleButtonGroup::draw(NVGcontext* vg)
{
    Element::draw(vg);
    
    for (auto button:buttons) {
        ofRectangle theRect, visibleRect;
        Boolean isHovered;
        ofColor backgroundColor;
        
        theRect = button.rect;
        theRect.x = theRect.x + rect.x;
        theRect.y = theRect.y + rect.y;
        
        visibleRect = getVisibleRectForButton(button);
        isHovered =  visibleRect.inside(ofGetMouseX(), ofGetMouseY());
        backgroundColor = ToggleButton::getBackgroundColor(isHovered, button.pressed, button.pushed );
        drawButton(vg, button.caption, theRect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));
    }
    
    Element::finishDraw(vg);
}

void ToggleButtonGroup::update()
{
    Element::update();
    
    for (auto &button:buttons) {
        Boolean previousPressed = button.pressed;
        ofRectangle visibleRect;
        
        visibleRect = getVisibleRectForButton(button);
        if (!visibleRect.inside(ofGetMouseX(), ofGetMouseY())) continue;
     
        if (pressed) {
            button.pressed = pressed;
            
            if (button.pressed != previousPressed) {
                button.pushed = ! button.pushed;
            }
            
            selectedButtonData = button;
            for (auto &button2:buttons) {
                if (&button2 != &button) {
                    button2.pressed = false;
                    button2.pushed = false;
                }
            }
            value = button.value;
            if (onClick != NULL) onClick(this);
        }
    }
}

void ToggleButtonGroup::setOnClick(std::function<void(ToggleButtonGroup *toggleButtonGroup)> _onClick) {
    onClick = _onClick;
}


