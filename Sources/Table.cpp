//
//  Table.cpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 15/01/2018.
//

#include "Table.hpp"
#include "GUI.hpp"


Table::Table() {
    className = "Table";
    
    nColumns = 0;
    nRows = 0;
    rowHeight = 0;
    columnWidth = 0;
    allowResize = true;
    
    style.hasBorder = true;
    style.hasBackground = true;
}


Table::~Table() {
    
}

void Table::set(json config) {
    Element::set(config);
    
    if (config["nColumns"].is_number_integer()) {
        nColumns = config["nColumns"].get<int>();
    }
    if (config["nRows"].is_number_integer()) {
        nRows = config["nRows"].get<int>();
    }
    if (config["allowResize"].is_boolean()) {
        allowResize = config["allowResize"].get<Boolean>();
    }
    if (allowResize) {
        if (config["rowHeight"].is_number()) {
            rowHeight = config["rowHeight"].get<float>();
        }
    }
    
    updateInternal();
}

void Table::pushElement(Element* newElement, unsigned int column, unsigned int row) {
    
    if (column >= nColumns || row >= nRows) throw std::invalid_argument("Coordinate outside table dimensions");
    
    elements[column][row] = newElement;
    newElement->setParent(this);
    setElementRect(newElement, column, row);
}

void Table::update() {
    Element::update();
}

void Table::draw() {
    Element::draw( );
    
    // todo: fix
    // draw childs
    //drawChilds();
    
    Element::finishDraw( );
}

void Table::updateInternal() {
    if (allowResize && rowHeight != 0) {
        if (nRows == 0) return;

        rect.height = nRows * rowHeight;
    }
    else {
        if (nRows == 0) return;
        
        rowHeight = rect.height / nRows;
    }
    
    columnWidth = rect.width / nColumns;
    
    updateChilds();
}

void Table::updateChilds() {
    // todo: update rect of all child elements.
    // traverse them all and set (0,0,columnWidth, rowHeight);
    for(unsigned int y = 0; y < nRows; y++) {
        for (unsigned int x = 0; x < nColumns; x++) {
            if (elements[x][y] == NULL) continue;
            
            setElementRect(elements[x][y], x, y);
        }
    }
}

void Table::setElementRect(Element *element, unsigned int cellX, unsigned int cellY)
{
    element->set({
        {"x", cellX * columnWidth + rect.x},
        {"y", cellY * rowHeight + rect.y},
        {"width", columnWidth},
        {"height", rowHeight}
    });
}


json Table::jsonDump() {
    json jsonDump = Element::jsonDump();
    jsonDump["nRows"] = nRows;
    jsonDump["nColumns"] = nColumns;
    jsonDump["rowHeight"] = rowHeight;
    jsonDump["columnWidth"] = columnWidth;
    
    return jsonDump;
}


string Table::dump() {
    return  jsonDump().dump(4);
}

void* Table::add(void *newElement) {
    return NULL;
}
