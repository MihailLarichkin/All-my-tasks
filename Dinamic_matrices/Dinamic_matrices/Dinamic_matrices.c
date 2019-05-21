#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
	int i;
	int j;
	double** matrix;
} matrix;

matrix mem_matrix(int i, int j) {
	matrix arr;
	arr.i = i;
	arr.j = j;
	arr.matrix = (double**)malloc(arr.i * sizeof(double*));
	for (int n = 0; n < arr.i; n++) {
		arr.matrix[n] = (double*)malloc(arr.j * sizeof(double));
		for (int m = 0; m < arr.j; m++) {
			arr.matrix[n][m] = 0;
		}
	}
	return arr;
}

int delete_matrix(matrix arr) {
	for (int n = 0; n < arr.i; n++) {
		free(arr.matrix[n]);
	}
	free(arr.matrix);
	return 0;
}

matrix scanf_matrix1(matrix arr, int i, int j) {
	int temp;
	printf("Choose type of enter (1 - from console, 2 - from file 'matrix1'): \n");
	arr = mem_matrix(i, j);
	while (1) {
		scanf_s("%d", &temp);
		if (temp == 1) {
			printf("Input matrix %dx%d elements:\n", arr.i, arr.j);
			for (int n = 0; n < arr.i; n++) {
				for (int m = 0; m < arr.j; m++) {
					scanf_s("%lf", &arr.matrix[n][m]);
				}
			}
			break;
		}
		else if (temp == 2) {
			FILE *matrix1;
			if ((matrix1 = fopen("matrix1.txt", "r")) == NULL)
			{
				printf("Error, file undefinded, program can't work \n");
				getchar();
				return mem_matrix(0, 0);
			}
			for (int n = 0; n < arr.i; n++) {
				for (int m = 0; m < arr.j; m++) {
					fscanf_s(matrix1, "%lf", &arr.matrix[n][m]);
				}
			}
			printf("Matrix from file was read:\n");
			fclose(matrix1);
			break;
		}
		else {
			printf("Noncorrect type of enter, enter type again : ");
		}
	}
	return arr;
}

matrix scanf_matrix2(matrix arr, int i, int j) {
	int temp;
	printf("Choose type of enter (1 - from console, 2 - from file 'matrix2'): \n");
	arr = mem_matrix(i, j);
	while (1) {
		scanf_s("%d", &temp);
		if (temp == 1) {
			printf("Input matrix %dx%d elements:\n", arr.i, arr.j);
			for (int n = 0; n < arr.i; n++) {
				for (int m = 0; m < arr.j; m++) {
					scanf_s("%lf", &arr.matrix[n][m]);
				}
			}
			break;
		}
		else if (temp == 2) {
			FILE *matrix2;
			if ((matrix2 = fopen("matrix2.txt", "r")) == NULL)
			{
				printf("Error, one of files matrix1 or matrix2 undefinded, program can't work \n");
				getchar();
				return mem_matrix(0, 0);
			}
			for (int n = 0; n < arr.i; n++) {
				for (int m = 0; m < arr.j; m++) {
					fscanf_s(matrix2, "%lf", &arr.matrix[n][m]);
				}
			}
			printf("Matrix from file was read:\n");
			fclose(matrix2);
			break;
		}
		else {
			printf("Noncorrect type of enter, enter type again : ");
		}
	}
	return arr;
}

int printf_det(double a) {
	int temp;
	printf("Choose type of print (1 - to console, 2 - to file 'resault'): \n");
	while (1) {
		scanf_s("%d", &temp);
		if (temp == 1) {
			printf("%.5lf \n", a);
		}
		else if (temp == 2) {
			printf("Determinant was written to file \n");
			FILE *resault;
			if ((resault = fopen("resault.txt", "w")) == NULL) {
				printf("Error type of print");
				getchar();
				return 1;
			}
			fprintf(resault, "%.5lf \n", a);
			fclose(resault);
		}
		else {
			printf("Noncorrect type of print, enter type again : ");
		}
		break;
	}
	return 0;
}

int printf_matrix(matrix arr) {
	int temp;
	printf("Choose type of print (1 - to console, 2 - to file 'resault'): \n");
	while (1) {
		scanf_s("%d", &temp);
		if (temp == 1) {
			for (int n = 0; n < arr.i; n++) {
				for (int m = 0; m < arr.j; m++) {
					printf("%.5lf ", arr.matrix[n][m]);
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
			for (int n = 0; n < arr.i; n++) {
				for (int m = 0; m < arr.j; m++) {
					fprintf(resault, "%.5lf ", arr.matrix[n][m]);
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
	matrix summatrices = mem_matrix(matrix1.i, matrix1.j);
	for (int n = 0; n < matrix1.i; n++) {
		for (int m = 0; m < matrix1.j; m++) {
			summatrices.matrix[n][m] = matrix1.matrix[n][m] + matrix2.matrix[n][m];
		}
	}
	return summatrices;
}

matrix composition_of_matrices(matrix matrix1, matrix matrix2) {
	matrix compos = mem_matrix(matrix1.i, matrix2.j);
	for (int n = 0; n < matrix1.i; n++) {
		for (int m = 0; m < matrix2.j; m++) {
			compos.matrix[n][m] = 0;
			for (int k = 0; k < matrix1.j; k++) {
				compos.matrix[n][m] += matrix1.matrix[n][k] * matrix2.matrix[k][m];
			}
		}
	}
	return compos;
}

matrix matrixwithoutrowandcol(matrix arr, int row, int col) {
	matrix newmat = mem_matrix((arr.i) - 1, (arr.j) - 1);
	int c_add = 0;
	int r_add = 0;
	for (int n = 0; n < (arr.i) - 1; n++) {
		if (n >= row)
			r_add = 1;
		for (int m = 0; m < (arr.j) - 1; m++) {
			if (m >= col)
				c_add = 1;
			else c_add = 0;
			newmat.matrix[n][m] = arr.matrix[n + r_add][m + c_add];
		}
	}
	return newmat;
}

double det_of_matrix(matrix arr) {
	double det = 0;

	if (arr.i == 1) {
		return arr.matrix[0][0];
	}
	else if (arr.i == 2) {
		return arr.matrix[0][0] * arr.matrix[1][1] - arr.matrix[0][1] * arr.matrix[1][0];
	}
	else if (arr.i > 2) {
		for (int m = 0; m < arr.j; m++) {
			//printf_matrix(matrixwithoutrowandcol(arr, 0, m));
			det = det + (pow(-1, m) * arr.matrix[0][m] * det_of_matrix(matrixwithoutrowandcol(arr, 0, m)));
		}
	}
	return det;
}

matrix inverse_matrix(matrix matrix1) {
	matrix inverse_matrix = mem_matrix(matrix1.i, matrix1.j);
	for (int n = 0; n < matrix1.i; n++) {
		for (int m = 0; m < matrix1.j; m++) {
			inverse_matrix.matrix[m][n] = (pow(-1, m + n) * det_of_matrix(matrixwithoutrowandcol(matrix1, n, m))) / det_of_matrix(matrix1);
		}
	}
	return inverse_matrix;
}

void operations() {
	int i;
	int j;
	int temp;
	printf("Enter type of operation (1 - sum of matrices, 2 - composition of matrices, 3 - det. of matrix, 4 - inverse matrix): \n");
	while (1) {
		scanf_s("%d", &temp);
		if (temp == 1) {
			printf("Enter sizes of matrices: \n");
			scanf_s("%d%d", &i, &j);
			matrix matrix1 = scanf_matrix1(mem_matrix(i, j), i, j);
			matrix matrix2 = scanf_matrix2(mem_matrix(i, j), i, j);
			printf_matrix(sum_of_matrices(matrix1, matrix2));
			delete_matrix(matrix1);
			delete_matrix(matrix2);
			break;
		}
		else if (temp == 2) {
			printf("Enter sizes of first matrix: \n");
			scanf_s("%d%d", &i, &j);
			matrix matrix1 = scanf_matrix1(mem_matrix(i, j), i, j);
			matrix matrix2 = scanf_matrix2(mem_matrix(j, i), j, i);
			printf_matrix(composition_of_matrices(matrix1, matrix2));
			delete_matrix(matrix1);
			delete_matrix(matrix2);
			break;
		}
		else if (temp == 3) {
			printf("Enter sizes of matrices: \n");
			scanf_s("%d%d", &i, &j);
			matrix matrix1 = scanf_matrix1(mem_matrix(i, j), i, j);
			printf_det(det_of_matrix(matrix1));
			delete_matrix(matrix1);
			break;
		}
		else if (temp == 4) {
			printf("Enter sizes of matrices: \n");
			scanf_s("%d%d", &i, &j);
			matrix matrix1 = scanf_matrix1(mem_matrix(i, j), i, j);
			if (det_of_matrix(matrix1) == 0)
			{
				printf("Error, determinant of matrix is 0, imposible find inverse matrix \n");
			}
			else {
				printf_matrix(inverse_matrix(matrix1));
			}
			delete_matrix(matrix1);
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
		puts("\n");
		operations();
		printf("Press '1' to repeat the programm\n");
		scanf_s("%d", &g);
	} while (g == 1);
	return 0;
}