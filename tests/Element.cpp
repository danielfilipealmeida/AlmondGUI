//
//  Element.cpp
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
#include "Element.hpp"
#include "Viewport.hpp"


TEST_CASE("Should create GUI element", "[Element::Element]") {
    Element element;
    
    REQUIRE(element.hover == FALSE);
    REQUIRE(element.pressed == FALSE);
    REQUIRE(element.entered == FALSE);
    REQUIRE(element.exited == FALSE);
    
}

TEST_CASE("GUI element should throw when set data invalid json", "[Element::Element]") {
    Element element;

    REQUIRE_THROWS(element.set({}));
    
    REQUIRE_THROWS(element.set({{'a','b'}}));
    REQUIRE_THROWS(element.set({
        {"y", 20},
        {"width", 100},
        {"height", 120}
    }));
    REQUIRE_THROWS(element.set({
        {"x", 10},
        {"width", 100},
        {"height", 120}
    }));
    REQUIRE_THROWS(element.set({
        {"x", 10},
        {"y", 20},
        {"height", 120}
    }));
    REQUIRE_THROWS(element.set({
        {"x", 10},
        {"y", 20},
        {"width", 100}
    }));
}

TEST_CASE("GUI element should properly set data", "[Element::Element]") {
    Element element;
    
    element.set({
        {"x", 10},
        {"y", 20},
        {"width", 100},
        {"height", 120}
    });
   
    ofRectangle rect = element.rect;
    
    REQUIRE(rect.x == 10);
    REQUIRE(rect.y == 20);
    REQUIRE(rect.width == 100);
    REQUIRE(rect.height == 120);
}

// TODO
TEST_CASE("Test Element's visible rect without a parent","[calculateVisibleRect]") {
    Element element;
    
    element.set({
        {"x", 10},
        {"y", 10},
        {"width", 100},
        {"height", 100}
    });
    
    ofRectangle visibleRect = element.calculateVisibleRect();
    REQUIRE(visibleRect.x == 10);
    REQUIRE(visibleRect.y == 10);
    REQUIRE(visibleRect.width == 100);
    REQUIRE(visibleRect.height == 100);
}

TEST_CASE("Test Element's visible rect with a parent that do not cut the child element","[calculateVisibleRect]") {
    Element element, parentElement;
    
    element.set({
        {"x", 10},
        {"y", 10},
        {"width", 100},
        {"height", 100}
    });
    
    parentElement.set({
        {"x", 10},
        {"y", 10},
        {"width", 120},
        {"height", 120}
    });
    element.setParent(&parentElement);
    parentElement.update();
    element.update();
    
    ofRectangle visibleRect = element.calculateVisibleRect();
    REQUIRE(visibleRect.x == 20);
    REQUIRE(visibleRect.y == 20);
    REQUIRE(visibleRect.width == 100);
    REQUIRE(visibleRect.height == 100);
    
}

TEST_CASE("Test Element's visible rect with a parent that cut the child element","[calculateVisibleRect]") {
    Element element, parentElement;
    
    element.set({
        {"x", 10},
        {"y", 10},
        {"width", 100},
        {"height", 100}
    });
    
    parentElement.set({
        {"x", 10},
        {"y", 10},
        {"width", 90},
        {"height", 90}
    });
    element.setParent(&parentElement);
    parentElement.update();
    element.update();
    
    ofRectangle visibleRect = element.calculateVisibleRect();
    REQUIRE(visibleRect.x == 20);
    REQUIRE(visibleRect.y == 20);
    REQUIRE(visibleRect.width == 80);
    REQUIRE(visibleRect.height == 80);
    
}

TEST_CASE("Test Element's visible rect with a viewport parent","[calculateVisibleRect]") {
    
    Viewport viewport;
    Element element;
    
    viewport.set({
        {"x", 10},
        {"y", 10},
        {"width", 100},
        {"height", 100},
        {"totalWidth", 200},
        {"totalHeight", 200}
    });
    
    element.set({
        {"x", 50},
        {"y", 50},
        {"width", 100},
        {"height", 100}
    });
    element.setParent(&viewport);
    viewport.setScrollPositionY(1.0);
    viewport.update();
    element.update();
    
    ofRectangle visibleRect = element.calculateVisibleRect();
}
