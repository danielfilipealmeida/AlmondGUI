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
    void setOnClick(std::function<void(Button *button)> _onClick);

    /*!
     ...
     */
    virtual string getClass() { return "Button";}
    
    /*!
     ...
     */
    static ofColor getBackgroundColor(Boolean isHover, Boolean isPressed);

};

#endif /* Button_hpp */
