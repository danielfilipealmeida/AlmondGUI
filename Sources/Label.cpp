//
//  Label.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#include "Label.hpp"
#include "GUIStyle.hpp"
#include "GUI.hpp"


Label::Label()
{
    className = "Label";
	caption = "";
}


Label::~Label()
{
}

void Label::update()
{
}

void Label::draw( ){
    if (visible == FALSE) return;
    
    Element::draw( );
    
    ofSetColor(style.getCaptionColor());
    GUI::drawCenteredText(caption, rect);
    
    Element::finishDraw();
}

void Label::set(json config)
{
    Element::set(config);
    if (config["caption"].is_string()) caption = config["caption"].get<string>();
}

void Label::setCaption(string _caption)
{
    caption = _caption;
}
