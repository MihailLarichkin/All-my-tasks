#include <math.h>
#include <stdio.h>

long double func(long double x) {
	long double y = pow(x, 2) + 4 * sin(x) - 2;
	return y;
}
long double d2func(long double x) {
	long double y = 2 - 4 * sin(x);
	return y;
}
int main() {
	long double a;
	long double b;
	int n;
	int i;
	printf("This program considers the integral by the trapezoid method within the specified limits, enter the lower and upper limits and the number of segments of the split interval.");
	scanf_s("%lf %lf %d", &a, &b, &n);
	long double s = 0.5 * ((b - a) / n) * (func(a) + func(b));
	long double ds = fabs(pow((b - a), 3) * d2func(a)/(12 * n * n));
	for (i = 1; i < n; i++) {
		s = s + ((b - a) / n)*(func(a + i * ((b - a) / n)));
		if (d2func(a + i * (b - a) / n) > d2func(a + (i - 1) * (b - a) / n)) {
			ds = fabs(pow((b - a), 3) * d2func(a + i * (b - a) / n) / (12 * n * n));
		}
	}
	printf("%lf\naccuracy: %lf\n", s, ds);
	printf("Press any key to close the program");
	getch();
	return 0;
}