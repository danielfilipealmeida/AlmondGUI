//
//  Splitter.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 04/10/17.
//
//

#ifndef Splitter_hpp
#define Splitter_hpp

#include <stdio.h>
#include "Element.hpp"

typedef enum {
    SPLITTER_HORIZONTAL = 0,
    SPLITTER_VERTICAL
} SplitterType;

/*
 \brief configuration of a child of the splitter.
 
 Stores the element in the splitter section and the percentage of that section
 */
typedef struct {
    Element *element;
    float size;
} SplitterChild;


/*!
 \brief abstract Divides the area of the parent into several elements
 
 Takes the entire area of the parent or the whole screen of no parent. Divides it into the given number of requested zones. each zone needs to define a percentage (float values 0 to 1). The total percentage must be 1.
 
 A Splitter will split a rect into slices. All childs will get an absolute part of the splited rect. this sub-rect wont be scrollable. for that, use a Viewport.
 
 Example:
 
 Spliting the vertically the rect (0,0 100x100) will return the following two sub-rects
 (0x0 100x50)
 (0,50 100x50)
 */
class Splitter : public Element {
protected:
    SplitterType type;                  //!< the type of spliter (vertical/horizontal)
    std::vector<SplitterChild> childs; //!< a vector with all the splitter childs
    
    /*!
     Calculate the splitter rect
     */
    void calculateRect();
    
public:
    
    /*!
     \brief Constructor
     */
    Splitter();
    
    /*!
     \brief Destructor
     */
    ~Splitter();

    /*!
     \brief Set the Splitter data with a json variable
     \param json
     
     Available parameters:
     
     `x`, `y`, `width`, `height`: (float) sets the rect area. If they are not specified, uses the screen dimensions. (TODO: CONFIRM THIS!)
     
     `type`: can be SPLITTER_VERTICAL and SPLITTER_HORIZONTAL. sets how the splitter rect will be divided. Example:
     
     SPLITTER_VERTICAL divides like this:
     ```
     +-----+
     |-----|
     +-----+
     ```
     SPLITTER_HORIZONTAL divides like this:
     ```
     +-----+
     +  |  |
     +-----+
     ```
     
     */
    void set(json config);
    
    /*!
     \brief Update the Splitter
     */
    void update();
    
    /*!
     \brief Draw the splitter in a given context
     */
    void draw( );
    
    /*!
     \brief Resizes the Splitter and all it's child elements
     \param newRect the definition of the rect.
     */
    void resize(ofRectangle newRect);
    
    /*!
     \brief Adds a new element to the splitter at the end
     \param element
     \param size
     */
    void add(Element* element, float size);
    
    /*!
     \brief Calculate the rectangular areas of the child elements
     */
    void calculateChildsRects();

};
#endif /* Splitter_hpp */
