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

// Decorators
#include "Decorator.hpp"
#include "ResetButtonDecorator.hpp"
#include "SliderDecorator.hpp"



/**
 * \brief Defines a GUI tree
 *
 * Used to gather together common parts of a gui. Defines a tree and takes care of the drawing, update and interaction to that gui tree.
 */
class GUI
{
    
protected:
    int fontNormal; //!< the normal font id
    int fontBold;   //!< the bold font id
    int fontIcons;  //!< the font icons id
    int fontEmoji;  //!< the emoji font id

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
    void loadFonts();
    
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
};

#endif /* GUI_hpp */
