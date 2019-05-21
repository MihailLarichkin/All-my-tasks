#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void SCANF(int* array, int n) {
	printf("Input array from %d elements: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &array[i]);
	}
}

int MAXF(int* array, int n) {
	int max = array[0];
	for (int i = 0; i < n; i++) {
		if (array[i] > max)		max = array[i];
	}
	return max;
}

int MINF(int* array, int n) {
	int min = array[0];
	for (int i = 0; i < n; i++) {
		if (array[i] < min)		min = array[i];
	}
	return min;
}

float MEAN(int* array, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += array[i];
	}
	return sum / n;
}

float RMS(int* array, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pow(array[i] - MEAN(array, n), 2);
	}
	return pow(sum / n, 0.5);
}

int main() {
	int g;
	do {
	int n;
	printf("Enter size : ");
	while (1)
	{
		scanf_s("%d", &n);
		if (n > 0) {
			break;
		}
		printf("Enter size again : ");
	}
	int* ArrofNum = malloc(n * sizeof(int));
	SCANF(ArrofNum, n);
	int max = MAXF(ArrofNum, n);
	int min = MINF(ArrofNum, n);
	float mean = MEAN(ArrofNum, n);
	float rms = RMS(ArrofNum, n);
	printf("MAX: %d\nMIN: %d\nMEAN: %f\nRMS: %f\n", max, min, mean, rms);
	free(ArrofNum);
	printf("Press '1' to repeat the programm\n");
	scanf_s("%d", &g);
	} while (g == 1);
	return 0;
}