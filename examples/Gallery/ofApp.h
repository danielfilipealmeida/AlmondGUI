#ifndef __OF_APP__
#define __OF_APP__

#include "ofMain.h"
#include "GUI.hpp"


/*!
 @class ofApp
 @abstract ...
 @discussion ...
 */
class ofApp : public ofBaseApp {
    ofFbo fbo;
    ofVideoPlayer video;
    GUI *gui;
    Button *button;
    Slider *slider;
    Label *label;
    ToggleButton *toggle, *togglePressed;
    
    Slider *slider2;
    ResetButtonDecorator *sliderWithDecorator;
    
    Boolean firstDraw;
    
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    


};



#endif
