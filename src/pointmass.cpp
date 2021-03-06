#include "pointmass.h"

PointMass::PointMass(){
	init(ofGetWindowWidth(), ofGetWindowHeight());
}
PointMass::PointMass(float posX, float posY) {
	init(posX,posY);

}
void PointMass::init(float posX, float posY) {
		// Set the initial color
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
 
    x = posX; 
    y = posY; 

	lastX = x-ofRandom(-100,100);
	lastY = y-ofRandom(-100,100);

	pinned = false;
}
void PointMass::inertia() {
	if (!pinned) {
		float vX = x - lastX;
		float vY = y - lastY;

		vX *= 0.995;
		vY *= 0.995;

		float newX = x + vX;
		float newY = y + vY;

		lastX = x;
		lastY = y;

		x = newX;
		y = newY;
	}
	else {
		x = pinX;
		y = pinY;
	}
}
void PointMass::accelerate(float elapsedTime) {
	if (!pinned) {
		//accY += 980; // gravity

		x += 0.5 * accX * elapsedTime * elapsedTime;
		y += 0.5 * accY * elapsedTime * elapsedTime;

		accX = 0;
		accY = 0;
	}
	else {
		x = pinX;
		y = pinY;
	}
}

void PointMass::update(float elapsedTime, int mouseX, int mouseY){
	//// avoid other balls first
	//for (int i = 0; i < others.size(); i++) {
	//	if (&others[i] != this) {
	//		PointMass other = others[i];

	//		// avoid it here

	//	}
	//}

	float angle = atan2((float)(mouseY - y), (float)(mouseX - x));

	lastX -= 1 * cos(angle);
	lastY -= 1 * sin(angle);

	//vX += 2 * cos(angle);
	//vY += 2 * sin(angle);

	//vX *= 0.99;
	//vY *= 0.99;

	//x += vX * elapsedTime;
	//y += vY * elapsedTime;
}
 
void PointMass::draw(){
    ofSetColor(color);
    ofFill();
    //ofStroke();
	ofRect((int)x, (int)y,1,1);
	//ofCircle((int)x, (int)y, 2);
}