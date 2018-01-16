//
//  Table.cpp
//  Catch Tests
//
//  Created by Daniel Almeida on 15/01/2018.
//

#define protected public

#include <stdio.h>
#include "catch.hpp"
#include "Table.hpp"
#include "Button.hpp"



TEST_CASE("Table should be properly created", "[Table]") {
    Table *table;
    
    table = new Table();
    table->set({
        {"x", 0},
        {"y", 0},
        {"width", 100},
        {"height", 100},
        {"nColumns", 4},
        {"nRows", 4}
    });
    
    REQUIRE(table->rect.width == 100.0);
    REQUIRE(table->rect.height == 100.0);
    REQUIRE(table->rect.x == 0);
    REQUIRE(table->rect.y == 0);
    REQUIRE(table->nColumns == 4);
    REQUIRE(table->nRows == 4);
    
    delete table;
    
    table = new Table();
    table->set({
        {"x", 0},
        {"y", 0},
        {"width", 100},
        {"height", 100},
        {"nColumns", 4},
        {"nRows", 4},
        {"allowResize", true},
        {"rowHeight", 50.0}
    });
    
    REQUIRE(table->rect.height == 200);
    REQUIRE(table->rect.width == 100);
    REQUIRE(table->allowResize == true);
    REQUIRE(table->rowHeight == 50);
}


TEST_CASE("No column and rows specified will create a table of size 0X0ZX§  X       ", "[Table]") {
    Table *table;
    
    
    table = new Table();
    table->set({
        {"x", 0},
        {"y", 0},
        {"width", 100},
        {"height", 100}
    });
    
    REQUIRE(table->nColumns == 0);
    REQUIRE(table->nRows == 0);
}

TEST_CASE("Push should add elements to the array if proper coordinates are set", "") {
    Table *table;
    
    table = new Table();
    table->set({
        {"x", 0},
        {"y", 0},
        {"width", 100},
        {"height", 100},
        {"nColumns", 4},
        {"nRows", 4}
    });
    
    Button *aButton = new Button();
    table->pushElement(aButton, 0, 0);
    REQUIRE(table->elements[0][0] == aButton);
}

TEST_CASE("Push should throw exception when adding element to invalid table coordinate", "") {
    Table *table;
    
    table = new Table();
    table->set({
        {"x", 0},
        {"y", 0},
        {"width", 100},
        {"height", 100},
        {"nColumns", 4},
        {"nRows", 4}
    });
    
    Button *aButton = new Button();
    REQUIRE_THROWS(table->pushElement(aButton, 4, 4));
    REQUIRE_THROWS(table->pushElement(aButton,5, 5));
    REQUIRE_NOTHROW(table->pushElement(aButton, 3, 3));
    
}
