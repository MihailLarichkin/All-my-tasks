#include <math.h>
#include <stdio.h>

#define SIZE 10
int arr[SIZE];

void SCANF(int* parr) {
	printf("Input array with %d numbers:", SIZE);
	for (int i = 0; i < SIZE; i++) {
		scanf_s("%d", &parr[i]);
	}
}

int MAXF(int* parr) {
	int max = parr[0];
	for (int i = 0; i < SIZE; i++) {
		if (parr[i] > max)		max = parr[i];
	}
	return max;
}

int MINF(int* parr) {
	int min = parr[0];
	for (int i = 0; i < SIZE; i++) {
		if (parr[i] < min)		min = parr[i];
	}
	return min;
}

float MEAN(int* parr) {
	float sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += parr[i];
	}
	return sum/SIZE;
}

float RMS(int* parr) {
	float sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += pow (parr[i] - MEAN(arr), 2);
	}
	return pow(sum / SIZE, 0.5);
}

int main() {
	int g;
	do {
	SCANF(arr);
	int max = MAXF (arr);
	int min = MINF(arr);
	float mean = MEAN(arr);
	float rms = RMS(arr);
	printf("MAX: %d\nMIN: %d\nMEAN: %f\nRMS: %f\n", max, min, mean, rms);
	printf("Press '1' to repeat the programm\n");
	scanf_s("%d", &g);
	} while (g == 1);
	return 0;
}