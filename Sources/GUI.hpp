//
//  GUI.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#ifndef GUI_hpp
#define GUI_hpp

#include "Macros.hpp"
#include <stdio.h>
#include "Button.hpp"
#include "ToggleButton.hpp"
#include "Slider.hpp"
#include "VerticalSlider.hpp"
#include "Viewport.hpp"
#include "PaginatedViewport.hpp"
#include "Splitter.hpp"
#include "Preview.hpp"
#include "Label.hpp"
#include "ButtonGroup.hpp"
#include "ToggleButtonGroup.hpp"
#include "Table.hpp"
#include "Window.hpp"
#include "ImageMatrix.hpp"

// Decorators
#include "Decorator.hpp"
#include "ResetButtonDecorator.hpp"
#include "SliderDecorator.hpp"


// todo: move fonts somewhere else.
typedef enum  {
    Text = 0,
    Title
} Fonts;

ofTrueTypeFont getFont(Fonts font);

/**
 * \brief Defines a GUI tree
 *
 * Used to gather together common parts of a gui. Defines a tree and takes care of the drawing, update and interaction to that gui tree.
 */
class GUI
{
    
protected:
    
    /*!
     \brief a vector of elements that represent the first layer of a gui. elements can have children and that implements the next layers
     */
    std::vector<Element*> elements; //!<
    
    /*!
     \brief The element that currently has the interface focus. used for situation like textboxes that need to be focused to receive input
     */
    Element *focusedElement;
    
public:
    
    const string DEFAULT_FONT = "OpenSans-Light.ttf";
    
    const string MSG_ERROR_LOADING_FONT = "Error loading font '%s'.";
    
    
    /*!
     \brief Constructor
     */
    GUI();
    
    /*!
     \brief Destructor
     */
    ~GUI();
    
    /*!
     \brief Returns all childs of an element
     */
    std::vector<Element*> getChildsOfElement(void* parentElement);
    
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
     \param fontsPath The absolute path to the fonts. If no path is set, reverts to the Resources folder inside the app bundle
     */
    void loadFonts(string fontsPath = "");
    
    /*!
     \brief returns a working absolute path to a font file or throws an error
     \param filename the filename of the font
     \param path the path of the folder where the file is at
     */
    string getFontPath(string filename, string path = "");
    
    /*!
     \brief Adds an element to the elements list
     \param element the element added to the gui list
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
        
        if (ContainerInterface *guiContainerObject = dynamic_cast<ContainerInterface *>(guiObject)) {
            guiContainerObject->setGUI((void *)this);
        }
        
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
     \brief Checks if a given element has childs
     \param element the element to check if it has childs
     \result returns if the element has childs or not
     */
    Boolean elementHasChilds(Element *element);
    
    
    /*!
     \brief Delete all elements from the gui that belong to a given element
     \param *parentElement the element that will have it's children deleted
     */
    void deleteChildsOfElement(void *parentElement);
    
    
    /*!
     \brief Traverse all elements and updates their visible rect
     */
    void updateVisibleRects();
    
    /*!
     \brief Draws a line of text centered in a given rectangle
     */
    static void drawCenteredText(string caption, ofRectangle rect, Fonts font = Text);
    
    /*!
     \brief Save a texture to a file
     \param file filename
     \param texture texture
     */
    void saveTexture(string file, ofTexture texture);
    
    
    /*!
     \brief sets an element as the focused element
     \param element to focus
     */
    void setFocusedElement(Element *element);

    /*!
     \brief gets the currently focused element
     \return The currently focused element
     */
    Element *getFocusedElement();
    
    /*!
     \brief checks if a given element is currently focused
     \param element The element to check
     \return true or false for the focused condition of the queried element
     */
    Boolean isElementFocused(Element *element);
    
#pragma mark json helpers
    
    /*!
     Returns the dump of a ofRectangle
     \param rect The rectangle to get the dump from
     \return a json variable with the dump
     */
    static json jsonDump(ofRectangle rect);
    
    /*!
     Returns the dump of a ofColor
     \param color The color to get the dump from
     \return a json variable with the dump
     */
    static json jsonDump(ofColor color);
    
};

#endif /* GUI_hpp */
