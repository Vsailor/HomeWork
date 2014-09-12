struct Complex {
	double a;
	double b;
};
struct ComplexInTrigonomForm {
	double angle;
	double r;
};

extern void input(Complex &z);
extern void show(Complex z);
extern bool isTheSame(Complex a, Complex b);
extern Complex sum(Complex a, Complex b);
extern Complex sub(Complex a, Complex b);
extern Complex mult(Complex a, Complex b);
extern Complex div(Complex a, Complex b);
extern ComplexInTrigonomForm sqrt(Complex a, int n);
extern double abs(Complex z);
extern Complex pow(Complex a, int n);
extern Complex mult(Complex a, double b);
extern Complex toAlgForm(ComplexInTrigonomForm a);
extern ComplexInTrigonomForm toTrigonomForm(Complex z);
