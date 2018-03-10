//
//  Table.hpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 15/01/2018.
//

#ifndef Table_hpp
#define Table_hpp

#include <stdio.h>
#include "ContainerBase.hpp"


/*!
 \brief Implements a table containing a group of elements.
 
 TODO:
 change the way this is done and make the number or rows and columns to be
 fully configurable.
 Data won't be defined on a vector but on a map!
 */
class Table : public ContainerBase
{
protected:
    unsigned int nRows, nColumns;
    float rowHeight, columnWidth;
    
    /*!
     \brief Variable that controls if the height of the cells are fixed. This will result on the resize (true) or not (false) of the table
     */
    Boolean allowResize;
    
    std::map<unsigned int, std::map<unsigned int, Element*>> elements;
    
    /*!
    \brief Updates internal data such as number of rows and height
     */
    void updateInternal();
    
    /*!
     \brief Updates the rects of the childs
     */
    void updateChilds();
    
    /*!
     \brief Sets the recto of a child according to it's position on the table
     */
    
    void setElementRect(Element *element, unsigned int cellX, unsigned int cellY);
    
public:
    /*!
     \brief Constructor
     */
    Table();
 
    /*!
     \brief Destructor
     */
    ~Table();
    
    /*!
     \brief Sets the table data
     \param config a json variable with the needed configuration such as: width, ...
     */
    void set(json config);
    
    /*!
     \brief adds an element to the table
     
     \param newElement the GUI element to add to the list of elements
     */
    void pushElement(Element* newElement, unsigned int column, unsigned int row);
  
    /*!
     \brief Updates the state of the table
     */
    void update();

    /*!
     \brief Draws the table
     */
    void draw();
    
    /*!
     \brief gets a dump of the state of the element in json format
     
     This will be used to generate the string dump
     */
    json jsonDump();
    
    /*!
     \brief Get a dump of all data of the element
     
     \return a string representing the state of the element
     */
    string dump();
};



#endif /* Table_hpp */
