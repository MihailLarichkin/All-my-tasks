#include <math.h>
#include <stdio.h>
/*	k - ������� ��������� ����� � �����
	n - �����, �� �������� �� ���� ������� �����
	i - ���������� ����� ����� �� n
	j - ���������� ����� �������� �� ������ �� n*/
int main() {
	printf("You are welcome! It's a finder of simple numbers, please input n\n");
	int n, i, j, k;
	k = 0;
	scanf_s("%d", &n);
	for (i = 2; i < n; i++) {
		for (j = 1; j <= (int)(sqrt((double)i)); j++) {
			if ((double)i/(double)j - i / j == (double)0) {
				k = k + 1;
			}
		}
		if (k == 1) {
			printf("%d\n", i);
		}
		k = 0;
	}
	getch();
	return 0;
}