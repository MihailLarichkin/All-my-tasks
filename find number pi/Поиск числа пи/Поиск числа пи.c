#include <math.h>
#include <stdio.h>

int main() {
	int n;
	int i = 1;
	long double pi;
	pi = 0;
	printf("This is a program for calculating pi, enter the number of the decimal place, before which you want to get the value of pi");
	scanf_s("%d", &n);
	while ((long double)4 / (long double)((2 * i) - 1) > pow(10, (-1) * n)) {
		pi = pi + (long double)(4 * pow(-1, i + 1)) / (long double)(2 * i - 1);
		i++;
	}
	printf("%.*lf\n", n, pi);
	printf("Press any key to close the program");
	getch();
	return 0;
}