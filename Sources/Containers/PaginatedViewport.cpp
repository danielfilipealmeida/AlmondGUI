//
//  PaginatedViewport.cpp
//  ofxAlmondGUI
//
//  Created by Daniel Almeida on 05/05/18.
//
//

#include "PaginatedViewport.hpp"


PaginatedViewportElement::PaginatedViewportElement(Element *_element)
{
    element = _element;

}


PaginatedViewportElement::~PaginatedViewportElement()
{
    
}


void PaginatedViewportElement::setPage(unsigned int _page)
{
    page = _page;
}


unsigned int PaginatedViewportElement::getPage()
{
    return page;
}

Element* PaginatedViewportElement::getElement()
{
    return element;
}


PaginatedViewport::PaginatedViewport()
{
    Viewport::Viewport();
    
    className = "PaginatedViewport";
    currentPage = 0;
}

PaginatedViewport::~PaginatedViewport()
{
    
}


/*
 TODO make this work.
 Create a method to get the new element where the rect and the page are set.
 */
void* PaginatedViewport::add(void *newElement)
{
  
    float elementY, width, height;
    ofRectangle newElementRect;
    std::vector<void*> childElements;

    
    Element *lastAddedElement = (Element*) getLastChild();
    
    // todo, make a method that returns the rect and the page.
    if (lastAddedElement != NULL) {
        elementY = lastAddedElement->getRect().y + lastAddedElement->getRect().height + GUI_BORDER;
    }
    else {
        elementY = GUI_BORDER;
    }

    
    if (elementY + ((Element *)newElement)->getRect().height > this->getRect().height) {
        lastPage++;
        elementY = GUI_BORDER;
    }
    
    width = getRect().width - (2 * GUI_BORDER);
    height = ((Element *)newElement)->getHeightForWidth(width);

    ((Element *)newElement)->setParent(this);

    ((Element*) newElement)->set({
        {"x", GUI_BORDER},
        {"y", elementY},
        {"width", width},
        {"height", height},
        {"visible", currentPage == lastPage}
    });
    
    PaginatedViewportElement *newPaginatedElement = new PaginatedViewportElement((Element *)newElement);
    newPaginatedElement->setPage(lastPage);
    paginatedElements.push_back(newPaginatedElement);
    
    
  
    lastChild = (Element*) newElement;
    
    return newElement;


}

void PaginatedViewport::setPage(unsigned int _page) {
    currentPage = _page;
    for (auto element:paginatedElements)
    {
        Boolean isVisible = element->getPage() == currentPage ? TRUE:FALSE;
        element->getElement()->setVisible(isVisible);
    }
    
}


// todo. is this needed?
void PaginatedViewport::calculateChildsLocations()
{
    
}
