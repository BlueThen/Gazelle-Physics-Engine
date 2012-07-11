#ifndef pointmass_h
#define pointmass_h
 
#include "ofMain.h"
 
class PointMass {
public:
        // Constructor
        PointMass();     
 
        // Methods
		void inertia();
		void accelerate(float);
        void update(float, int, int);
        void draw();
 
        // Properties
        float x;
        float y;

		float lastX;
		float lastY;

		float accX;
		float accY;

        ofColor color;
};
#endif