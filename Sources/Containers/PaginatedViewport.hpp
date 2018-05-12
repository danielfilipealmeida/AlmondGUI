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
    
    /*!
     \brief Constructor
     */
    PaginatedViewportElement(Element *_element);
    
    /*!
     \brief Destructor
     */
    ~PaginatedViewportElement();
    
    /*!
     \brief Sets the page of this element inside the paginated viewport
     */
    void setPage(unsigned int _page);
    
    /*!
     \brief Gets the page the element is in in the paginated viewport
     \returns the current page the element is in
     */
    unsigned int getPage();
    
    /*!
     \brief Gets the element
     \returns Element* The stored element
     */
    Element* getElement();
    
};

class PaginatedViewport: public Viewport
{
protected:
    unsigned int lastPage, currentPage;
    
    std::vector<PaginatedViewportElement *> paginatedElements;
    
    /*!
     \brief Calculate the rect of the new element being added to the paginated viewport
     \param [Element*] element the new element
     \return ofRectangle the rectangle definition of the area took by the new element
     */
     ofRectangle getNewElementRect(Element *element);
public:
    
    /*!
     \brief Contructor
     */
    PaginatedViewport();
    
    /*!
     \brief Destructor
     */
    ~PaginatedViewport();
    
    /*!
     \brief Add a new element to the viewport
     \param [void*] newElement the new Element
     */
    void* add(void *newElement);
    
    
    /*!
     Go through all child elements, and calculate their position on the viewport
     and in which page they are at.
     */
    void calculateChildsLocations();
    
    
    /*!
     \brief sets the current page of the Paginated Viewport
     \param [unsigned int] _page page
     */
    void setPage(unsigned int _page);
};

#endif /* PaginatedViewport_hpp */
