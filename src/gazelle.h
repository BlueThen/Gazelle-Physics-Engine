#pragma once
 
#include "ofMain.h"
 
#include "pointmass.h"
#include "pmlink.h"
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
 
        vector<PointMass*> pointmasses;
		vector<PMLink> links;

		float mouseInfluenceSquared;
		int pmouseX, pmouseY;

		bool mouseDrag;

		float distPointToSegmentSquared(float,float, float,float, float,float);
};