#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void SCANF(float* arr, int n) {
	printf("Input arr from %d elements: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%f", &arr[i]);
	}
}

void PRINTF(float* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%.10f  ", arr[i]);
	}
	printf("\n");
}

int compare1(float a, float b) {
	if (a > b) return 1;
	else return 0;
}

int compare2(float a, float b) {
	if (a < b) return 1;
	else return 0;
}

int compare3(float a, float b) {
	if (fabs(a) > fabs(b)) return 1;
	else return 0;
}

void sort_arr(float* arr, int n) {
	int(*compare)(float, float);
	int temp;

	printf("Enter type of sort (1 - increase, 2 - decrease or 3 - abs. increase): \n");
	while (1) {
		scanf_s("%d", &temp);
		if (temp == 1) {
			compare = compare1;
			break;
		}
		else if (temp == 2) {
			compare = compare2;
			break;
		}
		else if (temp == 3) {
			compare = compare3;
			break;
		}
		else {
			printf("Noncorrect type of sort, enter again : "); }
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (compare (arr[j], arr[j + 1])) {
				float tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
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
		float* ArrofNum = malloc(n * sizeof(float));
		SCANF(ArrofNum, n);
		sort_arr(ArrofNum, n);
		PRINTF(ArrofNum, n);
		free(ArrofNum);
		printf("Press '1' to repeat the programm\n");
		scanf_s("%d", &g);
	} while (g == 1);
	return 0;
}