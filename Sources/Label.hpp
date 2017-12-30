//
//  Label.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 01/11/2017.
//

#ifndef Label_hpp
#define Label_hpp

#include <stdio.h>
#include "Element.hpp"

/*!
 @class Label
 @abstract Implements a simple label
 */
class Label : public Element
{
protected:
    string caption;
    
public:
    
    /*!
     ...
     */
    Label() ;
    
    /*!
     ...
     */
    ~Label();
    
    /*!
     ...
     */
    virtual void update();
    
    /*!
     ...
     */
    virtual void draw(NVGcontext* vg);
    
    /*!
     ...
     */
    virtual void set(json config);
};
#endif /* Label_hpp */
