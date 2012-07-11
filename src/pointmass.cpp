#include "pointmass.h"

PointMass::PointMass(){
    // Set the initial color
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
 
    // Initial x position of the ball
    x = ofRandom( ofGetWindowWidth() ); 
 
    // Initial y position of the ball
    y = ofRandom( ofGetWindowHeight() ); 

	vX = 0;
	vY = 0;
}
 
void PointMass::update(float elapsedTime, vector<PointMass> others, int mouseX, int mouseY){
	// avoid other balls first
	for (int i = 0; i < others.size(); i++) {
		if (&others[i] != this) {
			PointMass other = others[i];

			// avoid it here

		}
	}

	float angle = atan2((float)(mouseY - y), (float)(mouseX - x));

	vX += 2 * cos(angle);
	vY += 2 * sin(angle);

	vX *= 0.99;
	vY *= 0.99;

	x += vX * elapsedTime;
	y += vY * elapsedTime;
}
 
void PointMass::draw(){
    ofSetColor(color);
    ofFill();
    ofCircle( x, y, 2);
}