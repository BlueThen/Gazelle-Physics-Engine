#ifndef pointmass_h
#define pointmass_h
 
#include "ofMain.h"
 
class PointMass {
public:
        // Constructor
        PointMass();     
 
        // Methods
        void update(float, vector<PointMass>, int, int);
        void draw();
 
        // Properties
        int x;
        int y;
		float vX;
		float vY;
        ofColor color;
};
#endif