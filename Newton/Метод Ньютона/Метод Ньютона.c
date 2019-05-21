#include <math.h>
#include <stdio.h>

long double func(long double x) {
	long double y = pow(x, 2) + 4*sin(x) -2;
	return y;
}
long double d_func(long double x) {
	long double y = 2*x + 4*cos(x);
	return y;
}

int main() { 
	long double x0;
	int n;
	printf("This is a program for finding the roots of functions by the Newton method. Enter the initial approximation and calculation accuracy");
	scanf_s("%lf %d", &x0, &n);
	while (fabs(func(x0)/d_func(x0)) > pow(10, (-1) * (2 * n))) {
		x0 = x0 - func(x0) / d_func(x0);
	}
	printf("%.*lf\n", n, x0);
	printf("Press any key to close the program");
	getch();
	return 0;
}

