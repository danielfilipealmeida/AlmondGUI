//
//  ButtonGroup.cpp
//  Catch Tests
//
//  Created by Daniel Almeida on 07/01/2018.
//

#include <stdio.h>
#include "catch.hpp"
#include "ButtonGroup.hpp"
#include "Viewport.hpp"

TEST_CASE("Should create sub buttons", "") {
    ButtonGroup buttonGroup;
    
    buttonGroup.set({
        {"options", {
            {
                {"caption", "button 1"}
            },
            {
                {"caption", "button 2"}
            }
        }}
    });
    
    REQUIRE(buttonGroup.count() == 2);
}

TEST_CASE("Should calculate buttons width" "getButtonsWidth") {
    ButtonGroup buttonGroup;
    
    buttonGroup.set({
        {"options", {
            {
                {"caption", "button 1"}
            },
            {
                {"caption", "button 2"}
            }
        }},
        {"x", 0},
        {"y", 0},
        {"width", 100},
        {"height", 32}
    });
    
    float buttonWidth = buttonGroup.getButtonsWidth();
    REQUIRE(buttonGroup.getButtonsWidth() == (100 / 2) - GUI_BORDER);
    
    Viewport viewport;
    
    viewport.set({
        {"x", 0},
        {"y", 0},
        {"width", 200},
        {"height", 100}
    });
    viewport.add((Element *) &buttonGroup);
    float buttonsWidth = buttonGroup.getButtonsWidth();
    REQUIRE(buttonsWidth == (200 / 2) - GUI_BORDER * 2);
}

TEST_CASE("Should calculate buttons rect", "getVisibleRectForButton") {
    ButtonGroup buttonGroup;
    
    buttonGroup.set({
        {"options", {
            {
                {"caption", "button 1"}
            },
            {
                {"caption", "button 2"}
            }
        }},
        {"x", 0},
        {"y", 0},
        {"width", 100},
        {"height", 32}
    });
    
    unsigned int x = 0;
    for(unsigned int i = 0; i < buttonGroup.count(); i++) {
        ButtonData data = buttonGroup.getButtonDataAtIndex(i);
        ofRectangle visibleRect = buttonGroup.getVisibleRectForButton(data);
        REQUIRE(visibleRect.width == 46);
        REQUIRE(visibleRect.height == 32);
        REQUIRE(visibleRect.y == 0);
        REQUIRE(visibleRect.x == x);
        x = x + visibleRect.width + GUI_BORDER;
    }
}
