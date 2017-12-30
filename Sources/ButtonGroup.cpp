//
//  ButtonGroup.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "ButtonGroup.hpp"
#include "GUI.hpp"
#include "GUIStyle.hpp"
#include "Primitives.hpp"


ButtonGroup::ButtonGroup()
{
    currentX = 0;
}

ButtonGroup::~ButtonGroup()
{
    
}

void ButtonGroup::update()
{
    Element::update();
    
    for (auto &button:buttons) {
        Boolean previousPressed = button.pressed;
        ofRectangle visibleRect;
        
        visibleRect = getVisibleRectForButton(button);
        if (!visibleRect.inside(ofGetMouseX(), ofGetMouseY())) continue;
        
        button.pressed = pressed;
       
        if (button.pressed == FALSE && previousPressed != pressed) {
            selectedButtonData = button;
            value = button.value;
            if (onClick != NULL) onClick(this);
        }
    }
}



ofRectangle ButtonGroup::getRectForButton(ButtonData button) {
    ofRectangle theRect;
    
    theRect = button.rect;
    theRect.x = theRect.x + rect.x;
    theRect.y = theRect.y + rect.y;
    
    return theRect;
}

ofRectangle ButtonGroup::getVisibleRectForButton(ButtonData button) {
     ofRectangle visibleRect;
    
    visibleRect = getRectForButton(button);
    if (parent != NULL) {
        ofRectangle parentRect = parent->getRect();
        visibleRect.x = visibleRect.x + parentRect.x;
        visibleRect.y = visibleRect.y + parentRect.y;
    };
    
    return visibleRect;
}


void ButtonGroup::draw(NVGcontext* vg)
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
        backgroundColor = Button::getBackgroundColor(isHovered, pressed);
        drawButton(vg, button.caption, theRect, ofColor2NVGColor(backgroundColor, 255), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));
    }
    
    Element::finishDraw(vg);
}

void ButtonGroup::set(json config)
{
    Element::set(config);
    options = config["options"];
    nButtons = options.size();
    value = config["value"].is_number() ? config["value"].get<unsigned int>():0;
    
    createButtons();
}

float ButtonGroup::calculateButtonsWidth() {
    unsigned int nButtons = buttons.size();
    return (rect.width - (GUI_BORDER * (nButtons)))/ (float) nButtons;
}

void ButtonGroup::createButtons() {
    buttonsWidth = calculateButtonsWidth();
    
    for(json::iterator it = options.begin(); it!=options.end(); it++) {
        addButton(it);
        currentX = currentX + buttonsWidth + GUI_BORDER;
    }
}


void ButtonGroup::addButton(json::iterator it) {
    auto jsonData = *it;
    ButtonData newButtonData;
    
    newButtonData.caption = jsonData["title"];
    newButtonData.rect = ofRectangle(currentX, 0, buttonsWidth, rect.height);
    newButtonData.pressed = false;
    buttons.push_back(newButtonData);
}

ButtonData ButtonGroup::getLastClickedButtonData() {
    return selectedButtonData;
}

void ButtonGroup::setOnClick(std::function<void(ButtonGroup *buttonGroup)> _onClick) {
    onClick = _onClick;
}

void ButtonGroup::setParent(Element *_parent) {
    Element::setParent(_parent);
    
    currentX = GUI_BORDER;
    buttonsWidth = calculateButtonsWidth();
    
    for(auto &button:buttons) {
        float newX = currentX;
        float newY = button.rect.y;
        
        button.rect = ofRectangle(newX, newY, buttonsWidth, rect.height);
        currentX = currentX + buttonsWidth + GUI_BORDER;
    }
    
}

void ButtonGroup::resize(ofRectangle newRect) {
    Element::resize(newRect);
    if (parent!=NULL) setParent(parent);
}

unsigned int ButtonGroup::getValue() {
    return value;
}
