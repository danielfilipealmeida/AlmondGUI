//
//  ImageMatrix.hpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 03/06/18.
//
//

#ifndef ImageMatrix_hpp
#define ImageMatrix_hpp

#include <stdio.h>
#include "Element.hpp"


/*!
 \brief A element that displays a matrix of images
 */
class ImageMatrix : public Element
{
    unsigned int rows, columns;
    float cellHeight, cellWidth;
    std::function<void(ImageMatrix *imageMatrix)> onClick = NULL;
    std::map<std::pair<unsigned int, unsigned int>, ofImage*> images;
    std::pair<int, int> lastPressedCell;
    

public:
    
    /*!
     \brief Constructor
     */
    ImageMatrix();

    /*!
     \brief Destructor
     */
    ~ImageMatrix();
    
    /*!
     \brief Handles update event on the Image Matrix
     */
    virtual void update();
    
    /*!
     \brief draws the button
     */
    virtual void draw();
    
    /*!
     \brief Sets up the Image Matrix information
     \param config input configuration in a json objects
     
     */
    virtual void set(json config);
    
    /*!
     \brief Sets the lambda to be executed on click event
     */
    void setOnClick(std::function<void(ImageMatrix *imageMatrix)> _onClick);
    
    /*!
     \brief Returns a string with the name of the element
     */
    string getClass();
    
    /*!
     \brief adds a new image to the Image Matrix
     \param newImage the image to add to the Image Matrix
     \param column the column of the matrix (y coordinate)
     \param row the row of the matrix (x coordinate)
     */
    void addImage(ofImage* newImage, unsigned int column, unsigned int row);
    
    /*!
     \brief Returns the coordinates of the last clicked cell
     \returns std::pair<int, int>
     */
    std::pair<int, int> getLastPressedCell();
    
private:
    
    /*!
     \brief Calculates the rectangular area a image if the matrix will take when drawing
     \param column  column index
     \param row row index
     */
    ofRectangle getImageRect(unsigned int column, unsigned int row);

    /*!
     \brief Calculates the width and height of the cells of the matrix
     \param columns  column index
     \param rows row index
     */
    void calculateCellsDimensions(unsigned int columns, unsigned int rows);

    /*!
     \brief calculate what cell is currently under the mouse
     \return a pair with the column and row where the mouse is corrently located
     */
    std::pair<int, int> getCellUnderMousePointer();
    
    /*!
     \brief Draw the currently selected cell
     */
    void drawClickedCell();
};



#endif /* ImageMatrix_hpp */
