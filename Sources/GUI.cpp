//
//  GUI.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "ofMain.h"

#include "GUI.hpp"


/*!
 Creates the GUI
 */
GUI::GUI(string fontsPath)
{
    ofBackground(0,0,0);
    ofDisableSmoothing();
    ofDisableAlphaBlending();
    ofTrueTypeFont::setGlobalDpi(72);
    loadFonts(fontsPath);
}

/*!
 Destroys the GUI
 */
GUI::~GUI()
{
}

GUI& GUI::getInstance()
{
    static GUI instance;
    
    return instance;
}

void GUI::add(Element *element)
{
     elements.push_back(element);
}


void GUI::draw()
{
    for(auto element:elements)
    {
         if (!element->getParent()) element->draw();
    }
    ofSetColor(255,255,255,255);
}

void GUI::update()
{
    for(auto element:elements)
    {
        element->update();
    }
}


void GUI::forEach(std::function<void (Element *)> lambda)
{
    for(auto element:elements) {
        lambda(element);
    }
}

std::vector<Element*> GUI::filter(std::function<bool (Element *)> lambda) {
    std::vector<Element*> result;
    
    for(auto element:elements) {
        if (lambda(element) == true) {
            result.push_back(element);
        }
    }
    
    return result;
}

void GUI::updateVisibleRects()
{
    forEach([this](Element *element) {
        element->visibleRect = element->calculateVisibleRect();
    });
}

void GUI::loadFonts(string fontsPath)
{
    textFont.load(fontsPath + "OpenSans-Light.ttf", 13, true, true);
    textFont.setLineHeight(10);
}

ofTrueTypeFont GUI::getFont(Fonts font)
{
    ofTrueTypeFont result;
    
    switch (font) {
        case Text:
            result = textFont;
            break;
            
        default:
            result = textFont;
            break;
    }
    
    return result;
}

void GUI::drawCenteredText(string caption, ofRectangle rect, Fonts font)
{
    ofTrueTypeFont ttfont = getFont(font);
    ofRectangle stringRect = ttfont.getStringBoundingBox(caption, 0,0);
    float x, y;
    
    x = (rect.width - stringRect.width) / 2.0 + rect.x;
    y = (rect.height - stringRect.height ) / 2.0 + rect.y + ttfont.getLineHeight();
    ttfont.drawString(caption,x, y);
    
}



void GUI::saveTexture(string file, ofTexture texture)
{
    ofPixels pixels;
    
    texture.readToPixels(pixels);
    ofSaveImage(pixels, file);
}
