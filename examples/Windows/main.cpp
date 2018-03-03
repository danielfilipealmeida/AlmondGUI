#include "ofMain.h"
#include "ofApp.h"


//========================================================================
int main( ){
    ofGLFWWindowSettings settings;
    settings.width = 600;
    settings.height = 600;
    settings.setPosition(ofVec2f(300,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    
    
    //ofSetupOpenGL(1024,768, OF_WINDOW);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}
