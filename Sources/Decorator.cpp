//
//  Decorator.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/11/2017.
//

#include "Decorator.hpp"


Decorator::Decorator(Element *_el)
{
    element = _el;
}


void Decorator::draw(NVGcontext* vg)
{
    element->draw(vg);
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


