#include <iostream>
#include <math.h>

using namespace std;

struct Pos {
	double x;
	double y;
};

double g(Pos pos) {
	return sqrt(pow(pos.x,2)+pow(pos.y,2));
}

Pos centreOfGravity (Pos *points, int n) {
	double topXSum = 0;
	double bottomSum = 0;
	double topYSum = 0;
	for (int i=0; i<n; i++) {
		topXSum += g(points[i])*points[i].x;
		bottomSum += g(points[i]);
		topYSum += g(points[i])*points[i].y;
	}
	Pos result;
	result.x = topXSum/bottomSum*1.0;
	result.y = topYSum/bottomSum*1.0;
	return result;
}

Pos *input(int n) {
	Pos *points = new Pos[n];
	cout << "Enter coordinates" << endl;
	for (int i=0; i<n; i++) {
		cout << "M[" << i << "]:" << endl << "x = ";
		cin >> points[i].x;
		cout << "y = ";
		cin >> points[i].y;
	}
	return points;
}

void main() {
	cout << "How many points do you want?" << endl;
	int n;
	cin >> n;

	Pos *(*p)(int) = NULL;
	p = *input;
	Pos *points = p(n);

	Pos (*s)(Pos*,int) = NULL;
	s = centreOfGravity;
	Pos result = s(points, n);

	cout << "Mass center: x = " << result.x << "; y = " << result.y << endl; 
	system("pause");
}

