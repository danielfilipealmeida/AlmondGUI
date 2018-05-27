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
     \brief Constructor
     */
    Label() ;
    
    /*!
     \brief Destructor
     */
    ~Label();
    
    /*!
     \brief Update the label
     */
    virtual void update();
    
    /*!
     \brief draws the label
     */
    virtual void draw( );
    
    /*!
     \brief Sets ths data of the label
     \param config the configuration in a C++ json variable
     */
    virtual void set(json config);
    
    /*!
     \brief Sets the caption of the label
     \param caption the new caption
     */
    void setCaption(string _caption);
};
#endif /* Label_hpp */
