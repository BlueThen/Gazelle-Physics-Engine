#ifndef pmlink_h
#define pmlink_h
 
#include "ofMain.h"
#include "pointmass.h" 


class PMLink {
public:
	PMLink(); // default
	PMLink(PointMass&, PointMass&, float, float);
	void resolve();

	void stiffness(float);
	float stiffness();

	void distance(float);
	float distance();

private:
	float restDist;
	float stiff;
	PointMass *pmA, *pmB;
};


#endif