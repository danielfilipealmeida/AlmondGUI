//
//  ContainerBase.cpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 09/03/2018.
//

#include "ContainerBase.hpp"
#include "ElementInterface.hpp"
#include "GUI.hpp"

void ContainerBase::setGUI(void *_gui)
{
    gui = _gui;
}

std::vector<ChildInterface*> ContainerBase::getChildElements()
{
    std::vector<ChildInterface*> childs;
    
    childs = ((GUI *)gui)->getChildsOfElement(this);
    
    return childs;
}

void ContainerBase::drawChilds() {
    /*
     gui->forEach([this](Element *element) {
     if (element->parent != this) return;
     element->draw();
     });
     */
    auto childs = getChildElements();
    for(auto child:childs) {
        ((Element*)child)->draw();
    }
}