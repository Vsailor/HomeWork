struct Segment {
	double a;
	double b;
	bool isNotEmpty;
};

extern void setEmpty(Segment &t);
extern bool isNotEmpty(Segment t);
extern void setSegmentLength(Segment &t, double leftBorder, double rightBorder);
extern void setIntersectionLength(Segment &t, Segment t1, Segment t2);