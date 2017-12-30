//
//  GUI.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "ofMain.h"

#include "Primitives.hpp"
#define NANOVG_GL2_IMPLEMENTATION
#include "nanovg_gl.h"
#include "GUI.hpp"



struct NVGcontext* vg;

/*!
 Creates the GUI
 */
GUI::GUI()
{
    vg = nvgCreateGL2(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);

    loadFonts();

}

/*!
 Destroys the GUI
 */
GUI::~GUI()
{
    free(vg);
}

GUI& GUI::getInstance() {
    static GUI instance;
    
    return instance;
}

void GUI::add(Element *element) {
     elements.push_back(element);
}

void GUI::loadFonts() {
    fontIcons = nvgCreateFont(vg, "icons", "../Resources/entypo.ttf");
    if (fontIcons == -1) throw ("Could not add font icons");
    
    fontNormal = nvgCreateFont(vg, "sans", "../Resources/Roboto-Regular.ttf");
    if (fontNormal == -1) throw("Could not add font italic.");
    
    fontBold = nvgCreateFont(vg, "sans-bold", "../Resources/Roboto-Bold.ttf");
    if (fontBold == -1) throw("Could not add font bold");
    
    fontEmoji = nvgCreateFont(vg, "emoji", "../Resources/NotoEmoji-Regular.ttf");
    if (fontEmoji == -1) throw("Could not add font emoji");

    nvgAddFallbackFontId(vg, fontNormal, fontEmoji);
    nvgAddFallbackFontId(vg, fontBold, fontEmoji);
}




void GUI::draw()
{
        nvgBeginFrame(vg, ofGetWidth(), ofGetHeight(), 1);
    /*
    nvgBeginPath(vg);
    nvgRect(vg, 100,100, 120,30);
    nvgFillColor(vg, nvgRGBA(255,192,0,255));
    nvgFill(vg);
    
    drawSlider(vg, 0.5, 400, 430, 100, 20);

    testButton.draw(vg);
   */
    
    for(auto element:elements) {
         element->draw(vg);
    }
    nvgEndFrame(vg);
    
}

void GUI::update()
{

    for(auto element:elements) {
        element->update();
    }
}


void GUI::forEach(std::function<void (Element *)> lambda) {
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
