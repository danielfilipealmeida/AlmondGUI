//
//  VerticalSlider.hpp
//  Arbutus
//
//  Created by Daniel Almeida on 23/09/17.
//
//

#ifndef VerticalSlider_hpp
#define VerticalSlider_hpp

#include <stdio.h>
#include "Slider.hpp"

/*!
 \brief A vertical oriented slider without caption (only because I haven't figured out how to rotate the text. this should be changed soon!)
 */
class VerticalSlider : public Slider {
public:
    /*!
     \brief todo
     */
    VerticalSlider();
    
    /*!
     \brief todo
     */
    ~VerticalSlider();
    
    /*!
     \brief todo
     */
    void update();
    
    /*!
     \brief todo
     */
    void draw( );
    
    /*!
     \brief todo
     */
    void set(json config);

    /*!
     \brief todo
     */
    virtual string getClass() { return "VerticalSlider";}
};
#endif /* VerticalSlider_hpp */
