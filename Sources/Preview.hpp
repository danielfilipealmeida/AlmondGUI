//
//  Preview.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 17/10/2017.
//

#ifndef Preview_hpp
#define Preview_hpp

#include <stdio.h>
#include "Element.hpp"

/*!
 \brief An Element for displaying FBO's
 
 The Preview is used for displaying content stored in fbo's like playing videos, animations, compositions or other graphic elements
 */
class Preview : public Element {
    ofFbo *fbo;
    string caption;
    
public:
    /*!
     Constructor
     */
    Preview();
    
    /*!
     Destructor
     */
    ~Preview();
    
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
    void draw( );
    
    /*!
     Fbo Setter
     */
    void setBuffer(ofFbo *_fbo);
    
    /*!
     \brief todo
     */
    float getHeightForWidth(float _width);
};

#endif /* Preview_hpp */
