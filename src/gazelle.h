#pragma once
 
#include "ofMain.h"
 
#include "pointmass.h" // Add this
#include <vector>

class gazelle : public ofBaseApp {
public:
        void setup();
        void update();
        void draw();
 
        void keyPressed (int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
 
        vector<PointMass> pointmasses;   // Replaces the previous variables 
                        // with a new object that contains 
                        // the previous information
};