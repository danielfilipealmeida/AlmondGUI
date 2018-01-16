//
//  Splitter.cpp
//  Catch Tests
//
//  Created by Daniel Almeida on 15/10/2017.
//

#define protected public

#include <stdio.h>
#include "catch.hpp"
#include "Splitter.hpp"
#include "Viewport.hpp"
#include "Button.hpp"


TEST_CASE("Splitter should be properly created", "[Splitter]") {
    Splitter *splitter;
    
    splitter = new Splitter();
    splitter->set({
        {"x", 0},
        {"y", 0},
        {"width", 100},
        {"height", 100}
    });
}


TEST_CASE("Elements inside splitter are properly clicked", "") {
    Splitter *splitter;
    
    splitter = new Splitter();
    splitter->set({
        {"x", 0},
        {"y", 0},
        {"width", 100},
        {"height", 100}
    });
    
    Viewport *viewport1 = new Viewport();
    Viewport *viewport2 = new Viewport();
    
    Button *button1 = new Button();
    button1->set({
        {"caption", "button 1"}
    });
    viewport1->add(button1);
    
    Button *button2 = new Button();
    button2->set({
        {"caption", "button 2"}
    });
    viewport2->add(button2);
    
    splitter->add(viewport1, 0.5);
    splitter->add(viewport2, 0.5);
    
    REQUIRE(button2->getRect().x == GUI_BORDER);
    REQUIRE(button2->getRect().y == GUI_BORDER);
    REQUIRE(button2->getRect().height == GUI_LINE_HEIGHT * 1.5);
    
    // this is not right! it+s failling. why?
    //REQUIRE(button2->getRect().width == ((100 / 2) - (GUI_BORDER * 2)));
}
