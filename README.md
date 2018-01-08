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


## Usage

The `GUI` singleton and factory object is used when creating a Graphic User Interface with Almond. All elements are created with it.

The following exemplifies how to create a simple button and set behaviour to it's click event:


    Button *button = GUI::getInstance().add<Button>({
        {"caption", "Click me!"}
    });

    button->setOnClick([label1](Button *button) {
        cout << "Button clicked!" << endl;
    });

The factory method add uses C++ templating to generate each type of elements. It always receives the needed information in a JSON-like variable. The content of this varies according to the type of element.


## Examples

### Hello World

This example present a brief usage of most of the Elements.

### Viewport

Shows how to use the viewport element can contain other elements and have a slider to scroll the content.

## Todo

-  generate gui tree for debugging (text)
- changes the sequence of drawing (gui draws only what has null parents. then each element draws it's children)
