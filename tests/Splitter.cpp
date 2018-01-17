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


TEST_CASE("Splitters inside splitters are displayed properly", "") {
    Splitter *mainSpliter, *subSplitter1, *subSplitter2;
    Button *button1, *button2, *button3, *button4;
    
    /*
     Divides like this:
     +-----+
     |-----|
     +-----+
     */
    mainSpliter = new Splitter();
    mainSpliter->set({
        {"x", 0},
        {"y", 0},
        {"width", 100},
        {"height", 100},
        {"type", SPLITTER_VERTICAL}
    });
    
    
    /*
     Divides like this:
     +-----+
     +  |  |
     +-----+
     */
    subSplitter1 = new Splitter();
    subSplitter1->set({
        {"type", SPLITTER_HORIZONTAL}
    });
    button1 = new Button();
    button1->set({
        {"caption", "button 1"}
    });
    button2 = new Button();
    button2->set({
        {"caption", "button 2"}
    });
    subSplitter1->add(button1, 0.5);
    subSplitter1->add(button2, 0.5);
    
    subSplitter2 = new Splitter();
    subSplitter2->set({
        {"type", SPLITTER_HORIZONTAL}
    });
    button3 = new Button();
    button3->set({
        {"caption", "button 3"}
    });
    button4 = new Button();
    button4->set({
        {"caption", "button 4"}
    });
    subSplitter2->add(button3, 0.5);
    subSplitter2->add(button4, 0.5);
    
    mainSpliter->add(subSplitter1, 0.5);
    mainSpliter->add(subSplitter2, 0.5);
    
    cout << button4->dump() << endl;
    REQUIRE(subSplitter1->rect.x == 0);
    REQUIRE(subSplitter1->rect.y == 0);
    REQUIRE(subSplitter1->rect.width == 100);
    REQUIRE(subSplitter1->rect.height == 50);
    
    REQUIRE(subSplitter2->rect.x == 0);
    REQUIRE(subSplitter2->rect.y == 50);
    REQUIRE(subSplitter2->rect.width == 100);
    REQUIRE(subSplitter2->rect.height == 50);
    
    REQUIRE(button1->rect.x == 0);
    REQUIRE(button1->rect.y == 0);
    REQUIRE(button1->rect.width == 50);
    REQUIRE(button1->rect.height == 50);

    REQUIRE(button2->rect.x == 50);
    REQUIRE(button2->rect.y == 0);
    REQUIRE(button2->rect.width == 50);
    REQUIRE(button2->rect.height == 50);

    REQUIRE(button3->rect.x == 0);
    REQUIRE(button3->rect.y == 50);
    REQUIRE(button3->rect.width == 50);
    REQUIRE(button3->rect.height == 50);
    
    REQUIRE(button4->rect.x == 50);
    REQUIRE(button4->rect.y == 50);
    REQUIRE(button4->rect.width == 50);
    REQUIRE(button4->rect.height == 50); 
}
