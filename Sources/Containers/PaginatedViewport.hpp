//
//  PaginatedViewport.hpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 05/05/18.
//
//

#ifndef PaginatedViewport_hpp
#define PaginatedViewport_hpp

#include <stdio.h>
#include "Viewport.hpp"


/*!
 \brief Object used for managing the information of a child element of the Paginated Viewport
 */
class PaginatedViewportElement {
private:
    unsigned int page;
    Element* element;
public:
    PaginatedViewportElement(Element *_element);
    ~PaginatedViewportElement();
    
    void setPage(unsigned int _page);
    unsigned int getPage();
    
    Element* getElement();
};

class PaginatedViewport: public Viewport
{
protected:
    unsigned int lastPage, currentPage;
    
    std::vector<PaginatedViewportElement *> paginatedElements;
    
    
    
public:
    
    /*!
     
     */
    PaginatedViewport();
    
    /*!
     
     */
    ~PaginatedViewport();
    
    /*!
     Add a new element to the viewport
     */
    void* add(void *newElement);
    
    
    /*!
     Go through all child elements, and calculate their position on the viewport
     and in which page they are at.
     */
    void calculateChildsLocations();
    
    
    /*!
     \brief sets the current page of the Paginated Viewport
     \param [unsigned int] the page
     */
    void setPage(unsigned int _page);
};

#endif /* PaginatedViewport_hpp */
