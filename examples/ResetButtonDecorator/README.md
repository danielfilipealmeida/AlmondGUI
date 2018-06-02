# Windows Example

Shows how to have more than one window with it's own Graphic User Interface

## Issues found while developing

* GUI cannot be a singleton. Each window should have it's own GUI.
* A Window cannot be a GUI Element
* TrueType fonts do not work properly on second window. why?
* Click handling on the GUI not working. Why?
* drawing is working
* windows should receive lambdas for handling events


## TODO

* GUI no longer uses the singleton pattern. there can be several GUIs
* a Window no longer an element. it has it's own GUI.
*Interfaces should only define methods and not implement code.
* code that is re-used, should be implemented on new classes like ElementBase and ContainerBase
* everything related to containers must be moved out of the element class
