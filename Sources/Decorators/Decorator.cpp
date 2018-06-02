//
//  Decorator.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/11/2017.
//

#include "Decorator.hpp"
#include "GUI.hpp"

Decorator::Decorator(Element *_el)
{
    element = _el;
    element->setParent(this);
}


void Decorator::draw()
{
    element->draw( );
}

void Decorator::set(json config) {
    Element::set(config);
}

void Decorator::update() {
    Element::update();
    element->update();
}

Element* Decorator::getElement() {
    return element;
}

void Decorator::setParent(Element *_parent) {
    Element::setParent(_parent);
    element->setParent(_parent);
}

void Decorator::resize(ofRectangle newRect) {
    Element::resize(newRect);
    element->resize(newRect);
}

Boolean Decorator::elementCanScroll() {
    return element->canScroll();
}
