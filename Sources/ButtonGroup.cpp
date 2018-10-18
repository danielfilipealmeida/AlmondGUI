//
//  ButtonGroup.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "ButtonGroup.hpp"
#include "GUI.hpp"
#include "GUIStyle.hpp"


ButtonGroup::ButtonGroup()
{
    className = "ButtonGroup";
    currentX = 0;
    style.hasBorder = false;
    style.hasBackground = false;
}

ButtonGroup::~ButtonGroup()
{
    
}

void ButtonGroup::update()
{
    if (visible == FALSE) return;

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
        ofRectangle parentRect = ((ElementInterface *)parent)->getRect();
        visibleRect.x = visibleRect.x + parentRect.x;
        visibleRect.y = visibleRect.y + parentRect.y;
    };
    
    return visibleRect;
}


void ButtonGroup::draw()
{
    if (visible == FALSE) return;
    
    Element::draw();
    
    for (auto button:buttons) {
        ofRectangle theRect, visibleRect;
        Boolean isHovered;
        ofColor backgroundColor;
        
        theRect = getRectForButton(button);
        visibleRect = getVisibleRectForButton(button);
        isHovered =  visibleRect.inside(ofGetMouseX(), ofGetMouseY());
        backgroundColor = style.addAlphaToColor(Button::getBackgroundColor(isHovered, pressed));
        
        ofFill();
        ofSetColor(backgroundColor);
        ofDrawRectangle(theRect);
        
        ofSetColor(style.getCaptionColor());
        GUI::drawCenteredText(button.caption, theRect);
        
        ofSetColor(style.getBorderColor());
        ofNoFill();
        ofDrawRectangle(theRect);
    }
    Element::finishDraw( );
}

void ButtonGroup::set(json config)
{
    Element::set(config);
    if (config["options"].is_array() && config["options"].size() > 0) {
        options = config["options"];
        nButtons = options.size();
    }
    
    value = config["value"].is_number() ? config["value"].get<unsigned int>():0;
    
    if (buttons.size() > 0) {
        buttons.clear();
        currentX = 0;
    }
    
    createButtons();
}

float ButtonGroup::getButtonsWidth()
{
    float totalWidth = rect.width;
    
    if (totalWidth <= 0 && parent != NULL) {
        totalWidth = ((ElementInterface *)parent)->getRect().width;
    }
    
   return (totalWidth - (GUI_BORDER * (nButtons - 1))) / (float) nButtons;
}

void ButtonGroup::createButtons() {
    buttonsWidth = getButtonsWidth();
    
    for(json::iterator it = options.begin(); it!=options.end(); it++) {
        addButton(it);
        currentX = currentX + buttonsWidth + GUI_BORDER;
    }
}


void ButtonGroup::addButton(json::iterator it) {
    auto jsonData = *it;
    ButtonData newButtonData;
    
    newButtonData.caption = jsonData["caption"];
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

void ButtonGroup::setParent(ElementInterface *_parent) {
    Element::setParent(_parent);
    
    currentX = GUI_BORDER;
    buttonsWidth = getButtonsWidth();
    
    for(auto &button:buttons) {
        float newX = currentX;
        float newY = button.rect.y;
        float height = rect.height > -1 ? rect.height : GUI_LINE_HEIGHT;
        
        button.rect = ofRectangle(newX, newY, buttonsWidth, rect.height);
        currentX = currentX + buttonsWidth + GUI_BORDER;
    }
}

void ButtonGroup::resize(ofRectangle newRect) {
    Element::resize(newRect);
    if (parent!=NULL) setParent((ElementInterface *)parent);
}

unsigned int ButtonGroup::getValue() {
    return value;
}


unsigned int ButtonGroup::count() {
    return nButtons;
}

void ButtonGroup::forEach(std::function<void (ButtonData)> lambda) {
    for(auto button:buttons) {
        lambda(button);
    }
}

ButtonData ButtonGroup::getButtonDataAtIndex(unsigned int index) {
    if (buttons.size() <= index) {
        throw std::invalid_argument("Invalid index");
    }
    
    return buttons[index];
}
