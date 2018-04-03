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

std::vector<void*> ContainerBase::getChildElements()
{
    std::vector<Element*> childs;
    std::vector<void*> childsResult;
    
    childs = ((GUI *)gui)->getChildsOfElement((void *) this);
    
    /* Converts std::vector<Element*> to std::vector<void*> */
    for(auto element:childs) {
        childsResult.push_back((void*) element);
    }
    
    return childsResult;
}

void ContainerBase::drawChilds() {
    auto childs = getChildElements();
    for(auto child:childs) {
        ((Element*)child)->draw();
    }
}
