//
//  ToggleButtonGroup.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#ifndef ToggleButtonGroup_hpp
#define ToggleButtonGroup_hpp

#include <stdio.h>
#include "ButtonGroup.hpp"
#include "ToggleButton.hpp"

class ToggleButtonGroup : public ButtonGroup
{
    std::function<void(ToggleButtonGroup *toggleButtonGroup)> onClick = NULL;
 public:
    
    /*!
     ...
     */
    virtual void addButton(json::iterator it);

    /*!
     ...
     */
    virtual void update();
    
    /*!
     ...
     */
    void draw(NVGcontext* vg);
    
    /*!
     ...
     */
    void setOnClick(std::function<void(ToggleButtonGroup *toggleButtonGroup )> _onClick);
};
#endif /* ToggleButtonGroup_hpp */
