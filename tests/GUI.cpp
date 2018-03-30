//
//  GUI.cpp
//  Catch Tests
//
//  Created by Daniel Almeida on 30/03/2018.
//

#include <stdio.h>
#include "catch.hpp"
#include "GUI.hpp"

TEST_CASE("GUI can get child elements of container element", "[GUI::getChildsOfElement]") {
    
    GUI *gui = new GUI();
    
    Viewport *viewport = gui->add<Viewport>({});
    Button *button1, *button2, *button3;
    
    button1 = gui->add<Button>({
        {"caption", "button 1"}
    });
    button2 = gui->add<Button>({
        {"caption", "button 2"}
    });
    button3 = gui->add<Button>({
        {"caption", "button 3"}
    });
    viewport->add(button1);
    viewport->add(button2);
    viewport->add(button3);
    
    std::vector<Element *> childs;
    
    childs = gui->getChildsOfElement(viewport);
    
    REQUIRE(childs.size() == 3);
    
    Button *button4;
    button4 = gui->add<Button>({
        {"caption", "button 4"}
    });
    
    childs = gui->getChildsOfElement(viewport);
    
    REQUIRE(childs.size() == 3);
    
    delete gui;
}
