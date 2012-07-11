#include "gazelle.h"

void gazelle::setup(){
    // Smooth edges
    //ofEnableSmoothing();
 
    // Fixed framerate
    ofSetFrameRate(60);
	
	cout << "resizing pointmasses\n";
	pointmasses.resize(1000);

	cout << "initializing pointmasses\n";

	for (int i = 0; i < pointmasses.size(); i++) {
		pointmasses[i] = PointMass();
	}
}
 
void gazelle::update(){
	for (int i = 0; i < pointmasses.size(); i++) {
		pointmasses[i].update(1, pointmasses, mouseX, mouseY);

		//pointmasses[i].vX *= 0.95;
		//pointmasses[i].vY *= 0.95;

		//pointmasses[i].x += pointmasses[i].vX;   
		//pointmasses[i].y += pointmasses[i].vY;
	}
}
 
void gazelle::draw(){
	ofBackground(ofColor::black);
    //ofBackgroundGradient(ofColor::gray,ofColor(30,10,30), OF_GRADIENT_CIRCULAR);
 
    for (int i = 0; i < pointmasses.size(); i++) {
		pointmasses[i].draw();
	}
}
//--------------------------------------------------------------
void gazelle::keyPressed(int key){

}

//--------------------------------------------------------------
void gazelle::keyReleased(int key){

}

//--------------------------------------------------------------
void gazelle::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void gazelle::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void gazelle::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void gazelle::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void gazelle::windowResized(int w, int h){

}

//--------------------------------------------------------------
void gazelle::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void gazelle::dragEvent(ofDragInfo dragInfo){ 

}