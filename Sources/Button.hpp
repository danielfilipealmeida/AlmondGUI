//
//  Button.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 10/09/17.
//
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>
#include "Element.hpp"


/*!
 \brief a structure so store data that can be used to define a button when a button class isn't needed
 */
typedef struct ButtonData {
    string caption;
    unsigned int value;
    ofRectangle rect;
    Boolean pressed;
    Boolean pushed;
    Boolean hover;
} ButtonData;

/*!
 \brief Implements a simple button GUI element
 
 The button have a caption and an associated lambda to be executed whenever it's pushed.
 */
class Button : public Element
{
protected:
    Boolean pushed;
    string caption;
    std::function<void(Button *button)> onClick = NULL;
    
public:
    
    /*!
     \brief Constructor
     */
    Button() ;
    
    /*!
     \brief Destructor
     */
    ~Button();
    
    /*!
     \brief Handles update event on the Button
     */
    virtual void update();
    
    /*!
     \brief draws the button
     */
    virtual void draw();
    
    /*!
     \brief Sets up the Slider information
     
     Available options:
        - x
        - y
        - width
        - height
        - visible
     
     \param config input configuration in a json objects
     
     */
    virtual void set(json config);

    /*!
     \brief Sets the lambda to be executed on click event
     */
    void setOnClick(std::function<void(Button *button)> _onClick);

    /*!
     \brief Returns a string with the name of the element
     */
    string getClass();
    
    /*!
     \brief returns the color for the given conditions of hover and press
     \param isHover if the element is hovered
     \param isPressed if the element is pressed
     \returns the color for the given conditions
     */
    static ofColor getBackgroundColor(Boolean isHover, Boolean isPressed);
    
    /*!
     \brief Returns the caption
     */
    string getCaption();

};

#endif /* Button_hpp */
