#include "segment.h"
#include <iostream>
#include <math.h>

using namespace std;

void setEmpty(Segment &t) {
	t.a = NULL;
	t.b = NULL;
	t.isNotEmpty = false;
}

bool isEmpty(Segment t) {
	if (t.isNotEmpty) {
		return false;
	}
	else {
		return true;
	}
}

void setSegmentLength(Segment &t, double leftBorder, double rightBorder) {
	t.a = leftBorder;
	t.b = rightBorder;
}

void setIntersectionLength(Segment &t, Segment t1, Segment t2) {
	if ((t1.a > t2.a && t1.a < t2.b) || (t1.b > t2.a && t1.b < t2.b)) {
		if ((t1.a > t2.a && t1.a < t2.b) && (t1.b > t2.a && t1.b < t2.b)) {
			t.a = t1.a;
			t.b = t1.b;
		} else if ((t1.a > t2.a && t1.a < t2.b)) {
			t.b = t2.b;
			t.a = t1.a;
		} else if ((t1.b > t2.a && t1.b < t2.b)) {
			t.b = t1.b;
			t.a = t2.a;
		}
		
	}
	else if (t1.a == t2.a && t1.b == t2.b) {
		t.a = t1.a;
		t.b = t1.b;
	}
	else {
		setEmpty(t);
	}

}