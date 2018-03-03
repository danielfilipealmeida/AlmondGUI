//
//  ToggleButtonGroup.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "ToggleButtonGroup.hpp"
#include "GUI.hpp"
#include "GUIStyle.hpp"



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

void ToggleButtonGroup::draw( )
{
    Element::draw( );
    
    for (auto button:buttons) {
        ofRectangle theRect, visibleRect;
        Boolean isHovered;
        ofColor backgroundColor;
        
        theRect = getRectForButton(button);
        visibleRect = getVisibleRectForButton(button);
        isHovered =  visibleRect.inside(ofGetMouseX(), ofGetMouseY());
        backgroundColor = ToggleButton::getBackgroundColor(isHovered, button.pressed, button.pushed );
        
        ofFill();
        ofSetColor(backgroundColor);
        ofDrawRectangle(theRect);
        
        ofSetColor(style.captionColor);
        GUI::drawCenteredText(button.caption, theRect);
        
        ofSetColor(style.borderColor);
        ofNoFill();
        ofDrawRectangle(theRect);
    }
    
    Element::finishDraw( );
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


