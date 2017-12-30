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

class ToggleButton : public Button
{
    std::function<void(ToggleButton *toggleButton)> onClick = NULL;
    
public:
    void update();
    
    void draw(NVGcontext* vg);
    
    /*!
     ...
     */
    void setOnClick(std::function<void(ToggleButton *toggleButton)> _onClick);
    
    Boolean isPushed();
    
    void setPushed(Boolean _pushed);
    
    static ofColor getBackgroundColor(Boolean isHover, Boolean isPressed, Boolean isPushed);
};

#endif /* ToggleButton_hpp */
