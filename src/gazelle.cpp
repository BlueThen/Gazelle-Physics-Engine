#include "gazelle.h"

void gazelle::setup(){
	mouseInfluenceSquared = 30 * 30;

	pmouseX = 0;
	pmouseY = 0;
	mouseDrag = false;

	int w = 120;
	int h = 80;
	int rd = 3;

	cout << "initializing pointmasses\n";

	// make a fabric
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			// index = y * w + x
			PointMass *pm = new PointMass(ofGetWindowWidth()/2 - (w * rd)/2 + x * rd, 100 + y * rd);
			pointmasses.push_back(pm);

			// link to x-1 and y-1
			if (x != 0)
				links.push_back(PMLink(*pm, *pointmasses.at(y * w + (x-1)), 1, rd));
			if (y != 0)
				links.push_back(PMLink(*pm, *pointmasses.at((y-1) * w + x), 1, rd));
			else { // pin it
				pm->pinned = true;
				pm->pinX = pm->x;
				pm->pinY = pm->y;
			}
		}
	}

	// make a rope
	//PointMass *pm = new PointMass;
	//pointmasses.push_back(pm);
	//for (int i = 1; i < 50; i++) {
	//	pm = new PointMass;
	//	//*pm = PointMass();
	//	pointmasses.push_back(pm);
	//	links.push_back(PMLink(*pm, *pointmasses.at(pointmasses.size()-2), 1, 3));
	//}

	//for (int i = 0; i < pointmasses.size(); i++) {
	//	pointmasses[i] = PointMass();
	//}
}
 
void gazelle::update(){
	for (int c = 0; c < 7; c++) {
		for (int i = 0; i < links.size(); ++i) { 
			links[i].resolve(); 
		}
		//pointmasses[0]->x = mouseX;
		//pointmasses[0]->y = mouseY;
	}
	for (int i = 0; i < pointmasses.size(); ++i) {

		if (mouseDrag) {
			float distanceSquared = distPointToSegmentSquared(pmouseX, pmouseY, mouseX, mouseY, pointmasses[i]->x, pointmasses[i]->y);
			if (distanceSquared < mouseInfluenceSquared) {
				pointmasses[i]->lastX = pointmasses[i]->x - (mouseX-pmouseX);
				pointmasses[i]->lastY = pointmasses[i]->y - (mouseY-pmouseY);
			}
		}

		pointmasses[i]->accY += 980;

		pointmasses[i]->accelerate(16.0/1000.0);

		pointmasses[i]->inertia();

		//pointmasses[i].update(1, mouseX, mouseY);
	}
	if (ofGetFrameNum() % 120 == 0)
		cout << ofGetFrameRate() << " fps\n";
	pmouseX = mouseX;
	pmouseY = mouseY;
}
 
void gazelle::draw(){
	ofBackground(ofColor::black);
    //ofBackgroundGradient(ofColor::gray,ofColor(30,10,30), OF_GRADIENT_CIRCULAR);
 
    for (int i = 0; i < pointmasses.size(); i++) {
		pointmasses[i]->draw();
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
	mouseDrag = true;
}

//--------------------------------------------------------------
void gazelle::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void gazelle::mouseReleased(int x, int y, int button){
	mouseDrag = false;
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

// Credit to: http://www.codeguru.com/forum/showpost.php?p=1913101&postcount=16
float gazelle::distPointToSegmentSquared (float lineX1, float lineY1, float lineX2, float lineY2, float pointX, float pointY) {
  if (lineX1 == lineX2 && lineY1 == lineY2)
    return pow(pointX - lineX1,2) + pow(pointY - lineY1,2);
  float vx = lineX1 - pointX;
  float vy = lineY1 - pointY;
  float ux = lineX2 - lineX1;
  float uy = lineY2 - lineY1;
  
  float len = ux*ux + uy*uy;
  float det = (-vx * ux) + (-vy * uy);
  if ((det < 0) || (det > len)) {
    ux = lineX2 - pointX;
    uy = lineY2 - pointY;
    return min(vx*vx+vy*vy, ux*ux+uy*uy);
  }
  
  det = ux*vy - uy*vx;
  return (det*det) / len;
}