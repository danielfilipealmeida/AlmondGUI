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



ofRectangle PaginatedViewport::getNewElementRect(Element *element) {
    float elementY, width, height;
    Element *lastAddedElement;
    
    lastAddedElement = (Element*) getLastChild();
    elementY = GUI_BORDER;
    if (lastAddedElement != NULL)
    {
        elementY += lastAddedElement->getRect().y +
            lastAddedElement->getRect().height;
    }
    
    // checks if adding the new element overflows
    if (elementY + ((Element *)element)->getRect().height > this->getRect().height)
    {
        lastPage++;
        elementY = GUI_BORDER;
    }
    
    width = getRect().width - (2 * GUI_BORDER);
    height = ((Element *)element)->getHeightForWidth(width);
    
    return ofRectangle(GUI_BORDER,
                       elementY,
                       width,
                       height);
}


void* PaginatedViewport::add(void *newElement)
{
    ofRectangle newElementRect;
    std::vector<void*> childElements;
    PaginatedViewportElement *newPaginatedElement;

    newElementRect = getNewElementRect(((Element *)newElement));
    ((Element *)newElement)->setParent(this);
    ((Element*) newElement)->set({
        {"x", newElementRect.x},
        {"y", newElementRect.y},
        {"width", newElementRect.width},
        {"height", newElementRect.height},
        {"visible", currentPage == lastPage}
    });
    
    newPaginatedElement = new PaginatedViewportElement((Element *)newElement);
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
