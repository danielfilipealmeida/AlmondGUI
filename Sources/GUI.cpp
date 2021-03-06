//
//  GUI.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#include "ofMain.h"

#include "GUI.hpp"


/* TODO: move fonts to a new class called FontsManager */
ofTrueTypeFont textFont;

ofTrueTypeFont getFont(Fonts font)
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





/*!
 Creates the GUI
 */
GUI::GUI()
{
    ofBackground(0,0,0);
    ofDisableSmoothing();
    ofDisableAlphaBlending();
    ofTrueTypeFont::setGlobalDpi(72);
    loadFonts();
}

/*!
 Destroys the GUI
 */
GUI::~GUI()
{
}

void GUI::add(Element *element)
{
     elements.push_back(element);
}


void GUI::draw()
{
    for(auto element:elements)
    {
        if (!element->getParent()) {
            element->draw();
        }
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

Boolean  GUI::elementHasChilds(Element *element) {
    Boolean result = FALSE;

    for (auto el:elements) {
        if (el->getParent() == element) {
            result = TRUE;
            break;
        }
    }
    
    return result;
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

// todo: finish this
void GUI::forEachChildOf(Element *parent, std::function<void (Element *)> lambda) {
    /*
    for(auto element:parent->getChildElements()) {
        lambda(element);
    }
     */
}


std::vector<Element*> GUI::getChildsOfElement(void* parentElement){
    std::vector<Element *> result;
    
    for(auto element:elements) {
        Element *currentElementParent = (Element*) element->getParent();
        if (currentElementParent == NULL) continue;
        
        if (currentElementParent == parentElement) {
            result.push_back(element);
        }
    }
    
    return result;
}


void GUI::updateVisibleRects()
{
    forEach([this](Element *element) {
        element->setVisibleRect(element->calculateVisibleRect());
    });
}


string GUI::getFontPath(string filename, string path)
{
    
    string fullPath = path + "/" + filename;
    if (ofFile::doesFileExist(fullPath)) {
        return fullPath;
    }
        
    fullPath = ofFilePath::getCurrentExeDir() + " /../Resources/" + "/" + filename;
    if (ofFile::doesFileExist(fullPath)) {
        return fullPath;
    }
    
    throw new std::runtime_error(SPRINTF(MSG_ERROR_LOADING_FONT, filename.c_str()));
}


void GUI::loadFonts(string fontsPath)
{
    if (fontsPath.empty()) {
        //fontsPath = ofFilePath::getCurrentExePath() + "/../Resources/";
        fontsPath = ofFilePath::getCurrentExeDir() + "../Resources/";
    }
    textFont.load(fontsPath + DEFAULT_FONT, 13, true, true);
    textFont.setLineHeight(10);
}


void GUI::drawCenteredText(string caption, ofRectangle rect, Fonts font)
{
    ofTrueTypeFont ttfont = getFont(font);
    if (!ttfont.isLoaded()) return;
    
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


json GUI::jsonDump(ofRectangle rect)
{
    return {
        {"x", rect.x},
        {"y", rect.y},
        {"width", rect.width},
        {"height", rect.height}
    };
}

json GUI::jsonDump(ofColor color)
{
    return {
        {"red", color.r},
        {"green", color.g},
        {"blue", color.b}
    };
}


void GUI::setFocusedElement(Element *element)
{
    focusedElement = element;
}

Element *GUI::getFocusedElement() {
    return focusedElement;
}


Boolean GUI::isElementFocused(Element *element)
{
    return element == focusedElement;
}

void GUI::deleteChildsOfElement(void *parentElement)
{
    std::vector<unsigned int> indexesOfElementsToDelete;
    
    unsigned int count = 0;
    for(auto element:elements) {
        if ((void *) element->getParent() == parentElement) {
            indexesOfElementsToDelete.push_back(count);
        }
        count++;
    }
    
    for (std::vector<unsigned int>::reverse_iterator i = indexesOfElementsToDelete.rbegin();
         i != indexesOfElementsToDelete.rend();
         i++) {
        elements.erase(elements.begin() + (*i));
    }
}
