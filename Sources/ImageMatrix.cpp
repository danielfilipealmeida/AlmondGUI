//
//  ImageMatrix.cpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 03/06/18.
//
//

#include "ImageMatrix.hpp"


ImageMatrix::ImageMatrix()
{
    className = "ImageMatrix";
    style.hasBorder = true;
    style.hasBackground = true;
    lastPressedCell = std::make_pair(-1, -1);
}

ImageMatrix::~ImageMatrix()
{
    
}

void ImageMatrix::update()
{
    Boolean previousPressed = pressed;
    
    Element::update();
    if (visible == FALSE) return;
    
    if (pressed == FALSE && previousPressed != pressed) {
        if (!visibleRect.inside(ofGetMouseX(), ofGetMouseY())) return;
            
        lastPressedCell = getCellUnderMousePointer();
        onClick(this);
    }
}


std::pair<int, int> ImageMatrix::getCellUnderMousePointer()
{
    float x, y;
    
    x = ofGetMouseX() - visibleRect.x;
    y = ofGetMouseY() - visibleRect.y;
    
    // todo: test if its outside and return -1, -1
    
    return std::make_pair((int) floor(x / cellWidth),
                          (int) floor(y / cellHeight));
    
}



void ImageMatrix::draw()
{
    if (visible == FALSE) return;
    
    style.backgroundColor = style.addAlphaToColor(GUIStyle::getInstance().getBackgroundColor());
    Element::draw( );

    for (auto imageData:images) {
        std::pair<unsigned int, unsigned int> location = imageData.first;
        ofImage *image = imageData.second;
        
        unsigned int row = location.second;
        unsigned int column = location.first;
        
        if (column >= columns) continue;
        if (row >= rows) continue;
        
        
        // todo make this a method
       image->draw(getImageRect(column, row));
       
        // todo: finish this. draw a cropped part in the cell
        /*
        ofRectangle imageRect = getImageRect(column, row);
        ofRectangle drawRect;
        float imageAspectRatio = image->rect.w / image->rect.h;
        float cellAspectRatio = cellWidth / cellHeight;
        float factor = image->rect.h / cellHeight;
    
        if (imageAspectRatio > cellAspectRatio) {
            
        } else {
            
        }
        
        image->drawSubsection(imageRect.x, imageRect.y, imageRect.width, imageRect.height,
                              drawRect.x, drawRect.y, drawRect.width, drawRect.height);
        */
        
   }
    
    drawClickedCell();
    
    Element::finishDraw( );
}


void ImageMatrix::set(json config)
{
    Element::set(config);
    
    if (config["columns"].is_number_integer()) {
        columns = config["columns"].get<int>();
    }
    if (config["rows"].is_number_integer()) {
        rows = config["rows"].get<int>();
    }
    
    calculateCellsDimensions(columns, rows);
}

void ImageMatrix::setOnClick(std::function<void(ImageMatrix *imageMatrix)> _onClick)
{
    onClick = _onClick;
}

string ImageMatrix::getClass()
{
    return className;
}

std::pair<int, int> ImageMatrix::getLastPressedCell()
{
    return lastPressedCell;
}

void ImageMatrix::addImage(ofImage* pixels, unsigned int column, unsigned int row)
{
    if (column >= columns) return;
    if (row >= rows) return;
    
    images[std::make_pair(column, row)] = pixels;
    
}

ofRectangle ImageMatrix::getImageRect(unsigned int column, unsigned int row)
{
    return ofRectangle(
                       rect.x + (column * cellWidth),
                       rect.y + (row * cellHeight),
                       cellWidth,
                       cellHeight
                       );
}

void ImageMatrix::calculateCellsDimensions(unsigned int columns, unsigned int rows)
{
    cellWidth = rect.width / (float) columns;
    cellHeight = rect.height / (float) rows;
}

void ImageMatrix::drawClickedCell()
{
    int column = lastPressedCell.first;
    int row = lastPressedCell.second;
    
    if (column < 0) return;
    if (row < 0) return;
    
    ofSetColor(ofColor::white);
    ofSetLineWidth(2);
    ofNoFill();
    ofRect(getImageRect(column, row));
}

