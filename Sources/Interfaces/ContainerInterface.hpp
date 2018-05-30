//
//  ContainerInterface.hpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 04/03/2018.
//

#ifndef ContainerInterface_h
#define ContainerInterface_h

#include "ChildInterface.hpp"
#include "Element.hpp"


class ContainerInterface {
    
public:

    /*!
     \brief Adds a child element to this container
     \param newElement the new element to add.
     */
    virtual void* add(void *newElement) = 0;
   
    /*!
     \brief return all child elements
     \return std::vector<ChildInterface*>
     */
    virtual std::vector<void*> getChildElements() = 0;
   
    /*!
     \brief Set internally the gui where this container is at.
     This is needed to be able to gain access to the gui's methods that handle it's elements
     \param _gui the gui
     */
    virtual void setGUI(void *_gui) = 0;
    
    /*!
     \brief Draws all elements that are children of this container
     */
    virtual void drawChilds() = 0;
    
    /*!
     \brief Removes all child elements
     */
    virtual void empty() = 0;
};


#endif /* ContainerInterface_h */
