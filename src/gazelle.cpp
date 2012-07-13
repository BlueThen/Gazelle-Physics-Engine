#include "gazelle.h"

void gazelle::setup(){
	cout << "resizing pointmasses\n";
	pointmasses.resize(6000);
	links.resize(5999);
	cout << "initializing pointmasses\n";

	pointmasses[0] = PointMass();
	for (int i = 1; i < 6000; i++) {
		pointmasses[i] = PointMass();
		links[i-1] = PMLink(pointmasses[i], pointmasses[i-1], 1, 1);
	}

	//for (int i = 0; i < pointmasses.size(); i++) {
	//	pointmasses[i] = PointMass();
	//}
}
 
void gazelle::update(){
	for (int c = 0; c < 3; c++) {
		for (int i = 0; i < links.size(); i++) {
			links[i].resolve();
		}
		pointmasses[0].x = mouseX;
		pointmasses[0].y = mouseY;
	}
	for (int i = 0; i < pointmasses.size(); i++) {
		//pointmasses[i].accelerate(1);

		pointmasses[i].inertia();

		//pointmasses[i].update(1, mouseX, mouseY);
	}
	cout << ofGetFrameRate() << " fps\n";
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