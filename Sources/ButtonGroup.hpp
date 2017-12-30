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
@class ButtonGroup
@abstract Implements a a group of buttons
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
    virtual void draw(NVGcontext* vg);
    
    /*!
     ...
     */
    virtual void set(json config);
    
    virtual void createButtons();
    
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
     \brief Calculate each buttons width, according to the total width and the number of buttons to display.
     
     This method takes into consideration the margin between the buttons
     */
    float calculateButtonsWidth();
    
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
    

};
#endif /* ButtonGroup_hpp */
