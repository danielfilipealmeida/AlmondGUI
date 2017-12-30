//
//  VerticalSlider.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 23/09/17.
//
//

// EVIL! transforms private members into public.
// used only for testing
#define protected public

#include <stdio.h>
#include "catch.hpp"
#include "VerticalSlider.hpp"


TEST_CASE("Should set GUI vertical slider properties", "[VerticalSlider::VerticalSlider]") {
    VerticalSlider verticalSlider;
    
    verticalSlider.set({
        {"x", 10},
        {"y", 20},
        {"width", 100},
        {"height", 120},
        {"caption", "vslider"}
    });
    ofRectangle rect = verticalSlider.rect;
    
    REQUIRE(rect.x == 10);
    REQUIRE(rect.y == 20);
    REQUIRE(rect.width == 100);
    REQUIRE(rect.height == 120);
    REQUIRE(verticalSlider.caption.compare("vslider") == 0);
}
