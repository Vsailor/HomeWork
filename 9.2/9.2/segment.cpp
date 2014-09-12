#include "segment.h"
#include <iostream>
#include <math.h>

using namespace std;

void setEmpty(Segment &t) {
	t.a = NULL;
	t.b = NULL;
	t.empty = true;
}

bool isEmpty(Segment t) {
	if (t.empty) {
		return true;
	}
	else {
		return false;
	}
}

void setSegmentLength(Segment &t, double leftBorder, double rightBorder) {
	t.a = leftBorder;
	t.b = rightBorder;
}

void setIntersectionLength(Segment &t, Segment t1, Segment t2) {
	if (t1.a < t2.a) {
		t.a = t2.a;
	}
	else {
		t.a = t1.a;
	}

	if (t2.b > t1.b) {
		t.b = t1.b;
	}
	else {
		t.b = t2.b;
	}
}