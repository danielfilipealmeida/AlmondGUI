//
//  ButtonGroup.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#ifndef ButtonGroup_hpp
#define ButtonGroup_hpp

#include <stdio.h>
#include "Button.hpp"




/*!
\brief Implements a a group of buttons
*/
class ButtonGroup : public Element
{
protected:
    string caption;
    std::vector<ButtonData> buttons;
    json options;
    ButtonData selectedButtonData;
    unsigned long nButtons;
    float buttonsWidth, currentX;
    unsigned int value;
    
    std::function<void(ButtonGroup *buttonGroup)> onClick = NULL;
    
public:
    
    /*!
     ...
     */
    ButtonGroup() ;
    
    /*!
     ...
     */
    ~ButtonGroup();
    
    /*!
     ...
     */
    virtual void update();
    
    /*!
     ...
     */
    virtual void draw( );
    
    /*!
     ...
     */
    virtual void set(json config);
    
    /*!
     ...
     */
    virtual void createButtons();
    
    /*!
     ...
     */
    virtual void addButton(json::iterator it);

    /*!
     \brief Returns a json with the data of the last clicked button
     */
    ButtonData getLastClickedButtonData();
    
    /*!
     ...
     */
    void setOnClick(std::function<void(ButtonGroup *buttonGroup)> _onClick);
    
    
    /*!
     \brief Returns the width of the buttons, according to the total width and the number of buttons to display.
     
     This method takes into consideration the margin between the buttons
     */
    float getButtonsWidth();
    
    /*!
     \brief Sets the element that will contain this element
     */
    void setParent(Element *_parent);
    
    /*!
     \brief handles resizing (not sure if this is needed)
     */
    virtual void resize(ofRectangle newRect);
    
    /*!
     \brief Returns the button rect inside the parent or the window if parent is NULL
     */
    ofRectangle getRectForButton(ButtonData button);
    
    /*!
     \brief returns the button rect inside the window
     */
    ofRectangle getVisibleRectForButton(ButtonData button);
    
    /*!
     \brief returns the value of the currently selected button
     */
    virtual unsigned int getValue();
    
    /*!
     \brief Get the number of buttons on the Buttons Group
     
     \return the number of buttons
     */
    unsigned int count();
    
    /*!
     \brief Apply a lambda to all buttons in a button group
     */
    void forEach(std::function<void (ButtonData)> lambda);
    
    /*
     \brief Get the data of a button at the given index
     \param the index of the button, from 0 to count-1
     \return a structure with the data needed for the button
     */
    ButtonData getButtonDataAtIndex(unsigned int index);
};
#endif /* ButtonGroup_hpp */
