//
//  GUI.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#ifndef GUI_hpp
#define GUI_hpp

#include <stdio.h>
#include "Button.hpp"
#include "ToggleButton.hpp"
#include "Slider.hpp"
#include "VerticalSlider.hpp"
#include "Viewport.hpp"
#include "Splitter.hpp"
#include "Preview.hpp"
#include "Label.hpp"
#include "ButtonGroup.hpp"
#include "ToggleButtonGroup.hpp"
#include "Table.hpp"

// Decorators
#include "Decorator.hpp"
#include "ResetButtonDecorator.hpp"
#include "SliderDecorator.hpp"

typedef enum  {
    Text = 0,
    Title
} Fonts;

/**
 * \brief Defines a GUI tree
 *
 * Used to gather together common parts of a gui. Defines a tree and takes care of the drawing, update and interaction to that gui tree.
 */
class GUI
{
    
protected:
    ofTrueTypeFont textFont;
    
    std::vector<Element*> elements; //!< a vector of elements that represent the first layer of a gui. elements can have children and that implements the next layers
    
    GUI();  //!< Protected constructor
    ~GUI(); //!< protected destructor
public:
    
    static GUI& getInstance();  //!< the instance getter
    GUI(GUI const&) = delete;   //!< deletes the constructor by reference copy
    void operator=(GUI const&) = delete; //!< destroy constructor by equal sign
    
    /*!
     Updates all elements of the GUI
     */
    void update();
    
    /*!
     Draws all visible elements of the GUI
     */
    void draw();
    
    /*!
     \brief Load all needed fonts
     */
    void loadFonts(string fontsPath = "");
    
    /*!
     \brief Returns a configured font
     */
    ofTrueTypeFont getFont(Fonts font);
    
    /*!
     \brief Adds an element to the elements list
     */
    void add(Element *element);

    /*!
     \brief Template for creating, setting and storing new elements
     */
    template<class guiClass>
    guiClass* add(json data) {
        guiClass* guiObject;
        
        guiObject = new guiClass();
        guiObject->set(data);
        elements.push_back(guiObject);
        
        return guiObject;
    };
    
    /*!
     \brief Apply a lambda to all elements in the GUI
     */
    void forEach(std::function<void (Element *)> lambda);
    
    /*!
     \brief Apply a lambda to filter from all elements of the GUI
     */
    std::vector<Element*> filter(std::function<bool (Element *)> lambda);
    
    /*!
     \brief Apply a lambda to all child elements of an element
     \param parent the parent element
     \param lambda the function to apply to each child element
     */
    void forEachChildOf(Element *parent, std::function<void (Element *)> lambda);
    
    /*!
     \brief Traverse all elements and updates their visible rect
     */
    void updateVisibleRects();
    
    /*!
     \brief Draws a line of text centered in a given rectangle
     */
    void drawCenteredText(string caption, ofRectangle rect, Fonts font = Text);
    
    /*!
     \brief Save a texture to a file
     
     \param file filename
     \param texture texture
     */
    void saveTexture(string file, ofTexture texture);
    
    
#pragma mark json helpers
    
    /*!
     Returns the dump of a ofRectangle
     \param ofRectangle rect to get the dump from
     \return a json variable with the dump
     */
    static json jsonDump(ofRectangle rect);
    
    /*!
     Returns the dump of a ofColor
     \param ofColor color to get the dump from
     \return a json variable with the dump
     */
    static json jsonDump(ofColor color);
    
};

#endif /* GUI_hpp */
