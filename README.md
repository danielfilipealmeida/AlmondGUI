# ofxAlmond - a GUI for openFrameworks

2017 Daniel Almeida


AlmondGUI is a Graphic User Interface library for `openFrameworks`.


## Quick Intro

A `GUI` is a group of interface elements inside a window. 
The `GUI` object must be initialized on the `setup` method as well as (ideally) all gui elements.
The `GUI`object besides storing all elements, also serves as a factory object of gui elements.

    void ofApp::setup(){
        gui = new GUI();

        label = gui->add<Label>({
            {"x", 10},
            {"y", 70},
            {"width", 100},
            {"height", GUI_LINE_HEIGHT * 1.5},
            {"caption", "Label"},
        });
    }


The `GUI` also needs to be updated and drawn, like this


    void ofApp::update() {
        gui->update();

    }

    void ofApp::draw() {
        gui->draw();
    }


## Graphic User Elements

### Element

`Element` is the `AlmondGUI` primitive. All different graphic user interface elements derive from here. It gathers all basic functionality needed for an element.

### Label

Use a `Label` to present textual information. Currently, labels only present one line of text. It cannot be pressed, so it cannot produce events.

![Label element](images/label.png)

#### Options

- x
- y
- width
- height
- visible


#### Examples

    label = gui->add<Label>({
        {"x", 10},
        {"y", 70},
        {"width", 100},
        {"height", GUI_LINE_HEIGHT * 1.5},
        {"caption", "Label"},
    });





### Button

`Button` can be pressed and is the basis of a few other elements like `ToggleButton` and `Slider`. It produces the `click` event.

![Button element](images/button.png)


#### Options

- x
- y
- width
- height
- visible


#### Examples

    button = gui->add<Button>({
        {"x", 10},
        {"y", 10},
        {"width", 100},
        {"height", GUI_LINE_HEIGHT * 1.5},
        {"caption", "Button"}
    });




### Toggle Button

This element is also clickable but it changes between two possible states: `pushed` and `not pushed`.


![Toggle element](images/toggle.png)
![Pressed toggle element](images/togglePressed.png)

#### Options

- x
- y
- width
- height
- visible


#### Methods


* `Boolean isPushed();`

> Get the state of the `Toggle Button`.



*`void setPushed(Boolean _pushed);`

> Sets the state of the `Toggle Button`



#### Examples

    toggle = gui->add<ToggleButton>({
        {"x", 10},
        {"y", 100},
        {"width", 100},
        {"height", GUI_LINE_HEIGHT * 1.5},
        {"caption", "Toggle"},
    });




### Button Group and Toggle Group

These elements show a group of buttons or toggles but actually are each one element.


### Slider

A rectangular area that allows the selection of a float value by clicking/dragging inside of it. The minimum and maximum values are user-defined.


![Slider element](images/slider.png)

#### Options

- x
- y
- width
- height
- visible
- value
- minValue
- maxValue


#### Examples

    slider = gui->add<Slider>({
        {"x", 10},
        {"y", 70},
        {"width", 100},
        {"height", GUI_LINE_HEIGHT * 1.5},
        {"caption", "Slider"},
        {"maxValue", 1.0},
        {"minValue", 0.0},
        {"value", 0.5}
    });



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
