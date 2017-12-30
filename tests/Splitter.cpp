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
