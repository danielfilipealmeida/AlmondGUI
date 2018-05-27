//
//  ToggleButton.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#ifndef ToggleButton_hpp
#define ToggleButton_hpp

#include <stdio.h>
#include "ButtonGroup.hpp"

/*!
 \brief Implements a Toggle Button from the Button element
 TODO: create a mode for drawing a checkbox instead of a toggle button
 */
class ToggleButton : public Button
{
    std::function<void(ToggleButton *toggleButton)> onClick = NULL;
    
    Boolean isCheckbox;
    
public:
    
    /*!
     \brief todo
     */
    void update();
    
    /*!
     \brief todo
     */
    void draw( );
    
    /*!
     \brief todo
     */
    void setOnClick(std::function<void(ToggleButton *toggleButton)> _onClick);
    
    /*!
     \brief todo
     */
    Boolean isPushed();
    
    /*!
     \brief todo
     */
    void setPushed(Boolean _pushed);
    
    /*!
     \brief todo
     */
    static ofColor getBackgroundColor(Boolean isHover, Boolean isPressed, Boolean isPushed);
};

#endif /* ToggleButton_hpp */
