#include "pmlink.h"

PMLink::PMLink() {

}

PMLink::PMLink(PointMass &a, PointMass &b, float stiff, float dist) {
	pmA = &a;
	pmB = &b;
	stiffness(stiff);
	distance(dist);
}

void PMLink::resolve() {
	// find distance between pmA and pmB;
	float diffX = pmA->x - pmB->x;
	float diffY = pmA->y - pmB->y;

	float dist = sqrt(diffX * diffX + diffY * diffY);

	float difference = restDist - dist;

	float scalar = 0.5 * stiff * difference;

	float translationX = (diffX / dist) * scalar;
	float translationY = (diffY / dist) * scalar;

	pmA->x += translationX;
	pmA->y += translationY;

	pmB->x -= translationX;
	pmB->y -= translationY;
}

float PMLink::stiffness() {
	return stiff;
}
void PMLink::stiffness(float amt) {
	stiff = amt;
}

float PMLink::distance() {
	return restDist;
}
void PMLink::distance(float amt) {
	restDist = amt;
}