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
 \brief Implements a simple label element
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
    virtual void draw( );
    
    /*!
     ...
     */
    virtual void set(json config);
};
#endif /* Label_hpp */
