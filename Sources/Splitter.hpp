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

typedef struct {
    Element *element;
    float size;
} SplitterChild;


/*!
 * \brief abstract Divides the area of the parent into several elements
 *
 * Takes the entire area of the parent or the whole screen of no parent. Divides it into the given number of requested zones. each zone needs to define a percentage (float values 0 to 1).
 * the total percentage must be 1.
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
     Constructor
     */
    Splitter();
    
    /*!
     Destructor
     */
    ~Splitter();

    /*!
     Set the Splitter data with a json variable
     */
    void set(json config);
    
    /*!
     Update the Splitter
     */
    void update();
    
    /*!
     Draw the splitter in a given context
     */
    void draw(NVGcontext* vg);
    
    /*!
     Adds a new element to the splitter at the end
     */
    void add(Element* element, float size);
    
    /*!
     Calculate the rectangular areas of the child elements
     */
    void calculateChildsRects();

};
#endif /* Splitter_hpp */
