#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WH 3

typedef struct matrix {
	float m[WH][WH];
} matrix;

int scanf_matrix1(matrix* matrix_) {
	int temp;
	printf("Choose type of enter (1 - from console, 2 - from file 'matrix1'): \n");
	while (1) {
		scanf_s("%d", &temp);
		if (temp == 1) {
			printf("Input matrix %dx%d elements:\n", WH, WH);
			for (int i = 0; i < WH; i++) {
				for (int j = 0; j < WH; j++) {
					scanf_s("%f", &matrix_->m[i][j]);
				}
			}
			break;
		}
		else if (temp == 2) {
			printf("Matrix from file was read:\n");
			FILE *matrix1;
			if ((matrix1 = fopen("matrix1.txt", "r")) == NULL)
			{
				printf("Error, file undefinded");
				getchar();
				return 1;
			}
			for (int i = 0; i < WH; i++) {
				for (int j = 0; j < WH; j++) {
					fscanf_s(matrix1, "%f", &matrix_->m[i][j]);
				}
			}
			fclose(matrix1);
			break;
		}
		else {
			printf("Noncorrect type of enter, enter type again : ");
		}
	}
	return 0;
}

int scanf_matrix2(matrix* matrix_) {
	int temp;
	printf("Choose type of enter (1 - from console, 2 - from file 'matrix2'): \n");
	while (1) {
		scanf_s("%d", &temp);
		if (temp == 1) {
			printf("Input matrix %dx%d elements:\n", WH, WH);
			for (int i = 0; i < WH; i++) {
				for (int j = 0; j < WH; j++) {
					scanf_s("%f", &matrix_->m[i][j]);
				}
			}
			break;
		}
		else if (temp == 2) {
			printf("Matrix from file was read:\n");
			FILE *matrix2;
			if ((matrix2 = fopen("matrix2.txt", "r")) == NULL)
			{
				printf("Error, file undefinded");
				getchar();
				return 1;
			}
			for (int i = 0; i < WH; i++) {
				for (int j = 0; j < WH; j++) {
					fscanf_s(matrix2, "%f", &matrix_->m[i][j]);
				}
			}
			fclose(matrix2);
			break;
		}
		else {
			printf("Noncorrect type of enter, enter type again : ");
		}
	}
	return 0;
}

int printf_det(float a) {
	int temp;
	printf("Choose type of print (1 - to console, 2 - to file 'resault'): \n");
	while (1) {
		scanf_s("%d", &temp);
		if (temp == 1) {
			printf("%.5f \n", a);
		}
		else if (temp == 2) {
			printf("Determinant was written to file \n");
			FILE *resault;
			if ((resault = fopen("resault.txt", "w")) == NULL) {
				printf("Error type of print");
				getchar();
				return 1;
			}
			fprintf(resault, "%.5f \n", a);
			fclose(resault);
		}
		else {
			printf("Noncorrect type of print, enter type again : ");
		}
		break;
	}
	return 0;
}

int printf_matrix(matrix matrix_) {
	int temp;
	printf("Choose type of print (1 - to console, 2 - to file 'resault'): \n");
	while (1) {
		scanf_s("%d", &temp);
		if (temp == 1) {
			for (int i = 0; i < WH; i++) {
				for (int j = 0; j < WH; j++) {
					printf("%.5f ", matrix_.m[i][j]);
				}
				printf("\n");
			}
			break;
		}
		else if (temp == 2) {
			printf("Matrix was written to file:\n");
			FILE *resault;
			if ((resault = fopen("resault.txt", "w")) == NULL) {
				printf("Error type of print");
				getchar();
				return 1;
			}
			for (int i = 0; i < WH; i++) {
				for (int j = 0; j < WH; j++) {
					fprintf(resault, "%.5f ", matrix_.m[i][j]);
				}
				fprintf(resault, "\n");
			}
			fclose(resault);
			break;
		}
		else {
			printf("Noncorrect type of print, enter type again : ");
		}
	}
	return 0;
}

matrix sum_of_matrices(matrix matrix1, matrix matrix2) {
	matrix summatrices;
	for (int i = 0; i < WH; i++) {
		for (int j = 0; j < WH; j++) {
			summatrices.m[i][j] = matrix1.m[i][j] + matrix2.m[i][j];
		}
	}
	return summatrices;
}

matrix composition_of_matrices(matrix matrix1, matrix matrix2) {
	matrix compos;
	for (int i = 0; i < WH; i++) {
		for (int j = 0; j < WH; j++) {
			compos.m[i][j] = 0;
			for (int k = 0; k < WH; k++) {
				compos.m[i][j] += matrix1.m[i][k] * matrix2.m[k][j];
			}
		}
	}
	return compos;
}

float det_of_matrix(matrix matrix1) {
	float det = matrix1.m[0][0] * matrix1.m[1][1] * matrix1.m[2][2] + matrix1.m[0][1] * matrix1.m[1][2] * matrix1.m[2][0] + matrix1.m[0][2] * matrix1.m[1][0] * matrix1.m[2][1] - matrix1.m[0][1] * matrix1.m[1][0] * matrix1.m[2][2] - matrix1.m[0][2] * matrix1.m[1][1] * matrix1.m[2][0] - matrix1.m[0][0] * matrix1.m[1][2] * matrix1.m[2][1];
	return det;
}

matrix inverse_matrix(matrix matrix1) {
	matrix inverse_matrix;
	inverse_matrix.m[0][0] = (matrix1.m[1][1] * matrix1.m[2][2] - matrix1.m[1][2] * matrix1.m[2][1]) / det_of_matrix(matrix1);
	inverse_matrix.m[1][0] = -(matrix1.m[1][0] * matrix1.m[2][2] - matrix1.m[1][2] * matrix1.m[2][0]) / det_of_matrix(matrix1);
	inverse_matrix.m[2][0] = (matrix1.m[1][0] * matrix1.m[2][1] - matrix1.m[1][1] * matrix1.m[2][0]) / det_of_matrix(matrix1);
	inverse_matrix.m[0][1] = -(matrix1.m[0][1] * matrix1.m[2][2] - matrix1.m[0][2] * matrix1.m[2][1]) / det_of_matrix(matrix1);
	inverse_matrix.m[1][1] = (matrix1.m[0][0] * matrix1.m[2][2] - matrix1.m[0][2] * matrix1.m[2][0]) / det_of_matrix(matrix1);
	inverse_matrix.m[2][1] = -(matrix1.m[0][0] * matrix1.m[2][1] - matrix1.m[0][1] * matrix1.m[2][0]) / det_of_matrix(matrix1);
	inverse_matrix.m[0][2] = (matrix1.m[0][1] * matrix1.m[1][2] - matrix1.m[0][2] * matrix1.m[1][1]) / det_of_matrix(matrix1);
	inverse_matrix.m[1][2] = -(matrix1.m[0][0] * matrix1.m[1][2] - matrix1.m[0][2] * matrix1.m[1][0]) / det_of_matrix(matrix1);
	inverse_matrix.m[2][2] = (matrix1.m[0][0] * matrix1.m[1][1] - matrix1.m[0][1] * matrix1.m[1][0]) / det_of_matrix(matrix1);
	return inverse_matrix;
}

void operations() {
	int temp;
	matrix matrix1;
	matrix matrix2;
	printf("Enter type of operation (1 - sum of matrices, 2 - composition of matrices, 3 - det. of matrix, 4 - inverse matrix): \n");
	while (1) {
		scanf_s("%d", &temp);
		if (temp == 1) {
			scanf_matrix1(&matrix1);
			scanf_matrix2(&matrix2);
			printf_matrix(sum_of_matrices(matrix1, matrix2));
			break;
		}
		else if (temp == 2) {
			scanf_matrix1(&matrix1);
			scanf_matrix2(&matrix2);
			printf_matrix(composition_of_matrices(matrix1, matrix2));
			break;
		}
		else if (temp == 3) {
			scanf_matrix1(&matrix1);
			printf_det(det_of_matrix(matrix1));
			break;
		}
		else if (temp == 4) {
			scanf_matrix1(&matrix1);
			if (det_of_matrix(matrix1) == 0)
			{
				printf("Error, determinant of matrix is 0, imposible find inverse matrix \n");
			}
			else {
				printf_matrix(inverse_matrix(matrix1));
			}
			break;
		}
		else {
			printf("Noncorrect type of operation, enter again : ");
		}
	}
}

int main() {
	int g;
	do {
		matrix matrix1;
		matrix matrix2;
		puts("\n");
		operations();
		printf("Press '1' to repeat the programm\n");
		scanf_s("%d", &g);
	} while (g == 1);
	return 0;
}