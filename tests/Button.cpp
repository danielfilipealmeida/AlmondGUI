//
//  Button.cpp
//  Arbutus - CatchCpp Unit Tests
//
//  Created by Daniel Almeida on 29/08/17.
//
//

// EVIL! transforms private members into public.
// used only for testing
#define protected public

#include <stdio.h>
#include "catch.hpp"
#include "Button.hpp"


TEST_CASE("Should create GUI button", "[Element::Element]") {
    Button button;
    
    REQUIRE(button.pushed == FALSE);
    REQUIRE(button.caption.compare("") == 0);
}

TEST_CASE("Should set GUI button properties", "[Element::Element]") {
    Button button;
    
    button.set({
        {"x", 10},
        {"y", 20},
        {"width", 100},
        {"height", 120},
        {"caption", "button"}
    });
    ofRectangle rect = button.rect;

    REQUIRE(rect.x == 10);
    REQUIRE(rect.y == 20);
    REQUIRE(rect.width == 100);
    REQUIRE(rect.height == 120);
    REQUIRE(button.caption.compare("button") == 0);
}
