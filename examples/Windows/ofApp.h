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
    Window *secondWindow;
    GUI *gui;
    
	public:
    
    static ofApp* getInstance();
    
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
