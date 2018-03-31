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
    
public:
    void setGUI(void *_gui);
    virtual std::vector<void*> getChildElements();
    virtual void drawChilds();
};

#endif /* ContainerBase_hpp */
