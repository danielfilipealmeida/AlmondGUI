//
//  Label.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "Label.hpp"
#include "Primitives.hpp"
#include "GUIStyle.hpp"

Label::Label(){
	caption = "";
}


Label::~Label(){
}

void Label::update(){
}

void Label::draw(NVGcontext* vg){
    Element::draw(vg);
    printCenteredText(vg, caption, getRect(), ofColor2NVGColor(GUIStyle::getInstance().getTextColor(), 255));
    Element::finishDraw(vg);
}

void Label::set(json config){
    Element::set(config);
    if (config["caption"].is_string()) caption = config["caption"].get<string>();
}
