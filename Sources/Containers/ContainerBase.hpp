//
//  ContainerBase.hpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 09/03/2018.
//

#ifndef ContainerBase_hpp
#define ContainerBase_hpp

#include <stdio.h>
#include "Element.hpp"
#include "ContainerInterface.hpp"


class ContainerBase : public Element, public ContainerInterface {
protected:
    void *gui;
    void *lastChild;
    
public:
    
    ContainerBase();
    
    /*!
     \brief Sets to what gui this container belongs to
     */
    void setGUI(void *_gui);

    /*!
     \brief Gets all the child elements
     */
    virtual std::vector<void*> getChildElements();
   
    /*!
     \brief Gets the last child element
     */
    virtual void* getLastChild();
    
    /*!
     \brief Draws all child elements
     */
    virtual void drawChilds();
};

#endif /* ContainerBase_hpp */
