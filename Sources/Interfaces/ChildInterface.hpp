//
//  ChildInterface.h
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 04/03/2018.
//

#ifndef ChildInterface_hpp
#define ChildInterface_hpp


class ChildInterface {
public:
    
    /*!
     \brief Sets the element that will contain this element
     \param _parent the parent
     */
    virtual void setParent(void *_parent) = 0;
    
    /*!
     \brief Returns the parent
     \returns the element this element is child of
     */
    virtual void* getParent() = 0;
    
};

#endif /* ChildInterface_h */
