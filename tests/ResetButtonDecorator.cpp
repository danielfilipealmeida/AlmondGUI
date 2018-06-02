//
//  ResetButtonDecorator.cpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 01/06/18.
//
//

// EVIL! transforms private members into public.
// used only for testing
#define protected public

#include <stdio.h>
#include "catch.hpp"
//#include "ResetButtonDecorator.hpp"
#include "GUI.hpp"

/**
 This test places a slider with a reset button decorator inside a viewport
 and checks if it handles currectly the hover and click and slide
 */
TEST_CASE("Slider with reset button decorator inside viewport should work properly") {
    Viewport *viewport;
    Slider *slider;
    ResetButtonDecorator *decorator;
    GUI *gui;
    
    
    gui = new GUI();
    
    viewport = gui->add<Viewport>({
        {"x", 200},
        {"y", 200},
        {"width", 200},
        {"height", 200}
    });
    
    slider = new Slider();
    decorator = new ResetButtonDecorator(slider);
    decorator->set({
        {"value", 0.5},
        {"minValue", 0.0},
        {"maxValue", 1.0}
    });
    gui->add(decorator);
    viewport->add(decorator);
    
    ofRectangle rect = slider->rect;
    
    ofRectangle visibleRect = slider->calculateVisibleRect();
    
    REQUIRE(visibleRect.x == 200 + 4 + 4);
    REQUIRE(visibleRect.y == 200 + 4 + 4);
    
    
    delete gui;
    
}
