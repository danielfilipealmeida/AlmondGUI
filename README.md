# ofxAlmond - a GUI for openFrameworks

2017 Daniel Almeida


AlmondGUI is a Graphic User Interface library built to be used with  `openFrameworks` and uses the `nanovg` library.


## Graphic User Elements

### Element

`Element` is the `AlmondGUI` primitive. All different graphic user interface elements derive from here. It gathers all basic functionality needed for an element.

### Label

Use a `Label` to present textual information. Currently, labels only present one line of text. It cannot be pressed, so it cannot produce events.


### Button

`Button` can be pressed and is the basis of a few other elements like `ToggleButton` and `Slider`. It produces the `click` event.


### Toggle Button

This element is also clickable but it changes between two possible states: `pushed` and `not pushed`.


### Button Group and Toggle Group

These elements show a group of buttons or toggles but actually are each one element.


### Slider

A rectangular area that allows the selection of a float value by clicking/dragging inside of it. The minimum and maximum values are user-defined.


### Preview

Draws a FBO inside a rect. Can be used to display pictures or videos.


## Containers


### Viewport

This is the most simple contaniner and it's used to gather elements inside. It can be scrollable.


### Table

Splits an area into a table, with a predifined amount of columns and rows, set on setup. each cell receives only one interface element which can be a `viewport`, including this way more elements

### Splitter

Splits a rectangle horizontaly or vertically into several sub rectangles. Each split can have it's own split amount. A splitter isn't an actual container. It just defines an area and each
cell has an `element` but those elements aren't really treated as GUI childs, they remain childless, thus they are toplevel elements. This needs to be addressed a fixed because
it's not a propper mechanism.


### Window

Creates a new windows with it's own user interface. This is work in progress and currently it isn't working at all.



## Usage

`Almond` uses  `GUI` objects for create Graphic User Interface structures. It was intended to exist one one `GUI` object per window and all 
other elements are created using that object's creator template method `add`. 

The following exemplifies how to create a simple button and set behaviour to it's click event:

    GUI *gui = new GUI();

    Button *button = gui->add<Button>({
        {"caption", "Click me!"}
    });

    button->setOnClick([label1](Button *button) {
        cout << "Button clicked!" << endl;
    });

The factory method `add` uses C++ templating to generate each type of elements. It always receives the needed information in a JSON-like variable. The content of this varies according to the type of element.


## Examples

### Hello World

This example present a brief usage of most of the Elements.


### Viewport

Shows how to use the viewport element can contain other elements and have a slider to scroll the content.


### Table

Example of how to use a table for composing interfaces.


### Splitters

Example not working. Needs to be fixed.


### Splitter in spitter

Simple example that has splitters inside of splitters for dividing the screen into a 4x4 table. each splitter cell has a button.


### Viewport in splitter

Example not working.


### Windows

Shows two windows with their own GUI. Currently not working.

## Todo

- Transparency
- Multi windows (started. not finished)
- List (will display an array of elements)
- generate gui tree for debugging (text)
- changes the sequence of drawing (gui draws only what has null parents. then each element draws it's children)
- Properly implement Interfaces. Only have method definitions. no implementations and no attributes. (started. not finished)
- Rewrite Splitter. not working properly
- unit test
- Example with all GUI elements. a GUI elements gallery
- Fix `Viewport in Splitter` example. Not drawing the gui elements. why?

### Multi windows todo

- a window is not part of the GUI. It's a stand alone object that is used for creating windows before running the main loop
- all needed windows must be created at start time?
- try to find a work around for this.
