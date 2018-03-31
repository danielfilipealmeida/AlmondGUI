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

TEST_CASE("GUI can filter", "[GUI::filter]") {
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
    
    string allTitles;
    
    std::vector<Element*> filterResults1 = gui->filter([](Element *element){
        return true;
    });
    
    REQUIRE(filterResults1.size() == 4);
    
    std::vector<Element*> filterResults2 = gui->filter([](Element *element){
        return false;
    });
    
    REQUIRE(filterResults2.size() == 0);
    
    std::vector<Element*> filterResults3 = gui->filter([](Element *element){
        return (element->getClass().compare("Button") == 0);
    });
        
    REQUIRE(filterResults3.size() == 3);
    

    std::vector<Element*> filterResults4 = gui->filter([](Element *element){
        if (element->getClass().compare("Button") != 0) return false;
        
        return ((Button*)element)->getCaption().compare("button 2") == 0;
    });
    
    REQUIRE(filterResults4.size() == 1);
    

}
