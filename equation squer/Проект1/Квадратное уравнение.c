#include <math.h>
#include <stdio.h>

int main() {
	printf("You are welcome! Input the coefficients a, b and c in the appropriate order, please\n");
	int g;
	do {
		float a, b, c, discriminant;
		scanf_s("%f %f %f", &a, &b, &c);
		discriminant = b * b - 4 * a * c;
		if (a == 0 && b == 0) {
			printf("This is not a quadratic equation\n");
		}
		else if (a == 0) {
			double x;
			x = -c / b;
			printf("%f\n", x);
		}
		else if (discriminant > 0) {
			double x1, x2;
			x1 = (-b + sqrt(discriminant)) / (2 * a);
			x2 = (-b - sqrt(discriminant)) / (2 * a);
			printf("%f\n%f", x1, x2);
		}
		else if (discriminant == 0) {
			double x;
			x = -b / (2 * a);
			printf("%f\n", x);
		}
		else if (discriminant < 0) {
			printf("%f + i * %f\n%f - i * %f\n", (-b) / (2 * a), sqrt((-1)*discriminant) / (2 * a), (-b) / (2 * a), sqrt((-1)*discriminant) / (2 * a));
		}
		
		printf("Press '1' to repeat programm\n");
		scanf_s("%d", &g);
	} while (g == 1 || g == 1);
	return 0;
}