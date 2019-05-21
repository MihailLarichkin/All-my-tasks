#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <malloc.h>


void clear()
{
	char ch;
	ch = '1';
	while (ch != '\n')
	{
		ch = getchar();
	}
}

void replace_symb(int num, char symb, char *s)
{
	s[num] = symb;
}

int delete_symb(int num, char *s, int len)
{
	for (int i = num; i < len; i++)
	{
		s[i] = s[i + 1];
	}
	return len--;
}

int insert_symb(int num, char sym, char *s, int len)
{
	for (int i = len; i >= num; i--)
	{
		s[i + 1] = s[i];
	}
	s[num] = sym;

	return len++;
}

void undel_spaces(char *s, int len)
{
	for (int i = 0; i <= len; i++)
	{
		if ((s[i] == ' ') && ((s[i + 1] == ' ')
			|| (s[i + 1] == '.')
			|| (s[i + 1] == ',')
			|| (s[i + 1] == '?')
			|| (s[i + 1] == '!')
			|| (s[i + 1] == ':')
			|| (s[i + 1] == ';')))
		{
			len = delete_symb(i, s, len);
			i--;
		}
	}
}

void wrong_punct_marks(char *s, int len)
{
	int i;
	for (i = 0; i <= len; i++)
	{
		if ((s[i] == '.') && (s[i + 1] == '.') && (s[i + 2] == '.'))
		{
			if ((s[i + 3] == '.')
				|| (s[i + 3] == ',') 
				|| (s[i + 3] == '?') 
				|| (s[i + 3] == '!') 
				|| (s[i + 3] == ':') 
				|| (s[i + 3] == ';'))
			{
				len = delete_symb(i + 3, s, len);
				i--;
			}
			else
			{
				i = i + 2;
			}
		}
		else
		{
			if ((s[i] == '?') && (s[i + 1] == '!'))
			{
				if ((s[i + 2] == '.')
					|| (s[i + 2] == ',') 
					|| (s[i + 2] == '?') 
					|| (s[i + 2] == '!') 
					|| (s[i + 2] == ':') 
					|| (s[i + 2] == ';'))
				{
					len = delete_symb(i + 2, s, len);
				}
				else
				{
					i++;
				}
			}
			else
			{
				if (((s[i] == '.') || (s[i] == ',') || (s[i] == '?') || (s[i] == '!') || (s[i] == ':') || (s[i] == ';')) 
					&&
					((s[i + 1] == '.') || (s[i + 1] == ',') || (s[i + 1] == '?') || (s[i + 1] == '!') || (s[i + 1] == ':') || (s[i + 1] == ';')))
				{
					len = delete_symb(i + 1, s, len);
				}
			}
		}
	}
}

void rewriter(char *r, char *w, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		*(w + i) = *(r + i);
	}
}

void del_spaces(char *s, int len)
{
	int i;
	for (i = 0; i <= len; i++)
	{
		if ((s[i] == '.') && (s[i + 1] == '.') && (s[i + 2] == '.'))
		{
			i = i + 1;
		}
		else
		{
			if ((s[i] == '?') && (s[i + 1] == '!'))
			{

			}
			else
			{
				if (((s[i] == '.') || (s[i] == ',') || (s[i] == '?') || (s[i] == '!') || (s[i] == ':') || (s[i] == ';')) && (s[i + 1] != ' '))
				{
					len = insert_symb(i + 1, ' ', s, len);
				}
			}
		}
	}
}

void correct_string(char *s, int len)
{
	undel_spaces(s, len);
	wrong_punct_marks(s, len);
	del_spaces(s, len);
	int i;
	for (i = 0; i <= len; i++)
	{
		if (((int)s[i] >= 65) && ((int)s[i] <= 90))
		{
			replace_symb(i, (char)((int)s[i] + 32), s);
		}
		if (((s[i - 2] == '.') || (s[i - 2] == '?') || (s[i - 2] == '!')) && ((int)s[i] >= 97) && ((int)s[i] <= 122))
		{
			replace_symb(i, (char)((int)s[i] - 32), s);
		}
	}
	if (((int)s[0] >= 97) && ((int)s[0] <= 122))
	{
		replace_symb(0, (char)((int)s[0] - 32), s);
	}
}



char *console_input(int *outp)
{
	char inp;
	char *arr;
	char *arr1;
	int len;
	arr = (char*)malloc(1 * sizeof(char));
	if (arr == NULL)
	{
		return NULL;
	}
	inp = getchar();
	*arr = inp;
	len = 1;
	while (1)
	{
		len++;
		inp = getchar();

		arr1 = (char*)malloc(2 * len * sizeof(char));
		if (arr1 == NULL)
		{
			free(arr);
			return NULL;
		}

		rewriter(arr, arr1, len - 1);
		*(arr1 + len - 1) = inp;

		free(arr);
		arr = arr1;

		if (inp == '#')
		{
			clear();
			break;
		}
	}
	*outp = len;
	return arr;
}

char *file_input(int *outp)
{
	FILE *fp;
	char inp;
	char *arr;
	char *arr1;
	int len = 1;

	if ((fp = fopen("Text.txt", "r")) == NULL)
	{
		printf("Error, file undefinded, program can't work \n");
		getchar();
	}
	if (fp == 0)
	{
		printf("File can't be read\n");
		return 0;
	}

	arr = (char*)malloc(1 * sizeof(char));
	if (arr == NULL)
	{
		return NULL;
	}
	inp = fgetc(fp);
	*arr = inp;
	while (1)
	{
		len++;
		inp = fgetc(fp);

		arr1 = (char*)malloc(2 * len * sizeof(char));
		if (arr1 == NULL)
		{
			free(arr);
			return NULL;
		}

		rewriter(arr, arr1, len - 1);
		*(arr1 + len - 1) = inp;

		free(arr);
		arr = arr1;

		if (inp == '#')
		{
			break;
		}
	}
	*outp = len;
	fclose(fp);
	return arr;
}

int main() {
	int g;
	do {
		int len_mass = 0;
		char *p;
		int temp;
		printf("Choose type of enter (1 - from console, 2 - from file 'f'): \n");
		while (1) {
			scanf_s("%d", &temp);
			if (temp == 1) {
				printf("Input your text(The end of the text must be #).\n");
				p = console_input(&len_mass);
				break;
			}
			else if (temp == 2)
			{
				p = file_input(&len_mass);
				break;
			}
			else {
				printf("Noncorrect type of enter, enter type again : ");
			}	
		}
		printf("\nYour input is:\n");
		int i;
		for (i = 0; i < len_mass; i++)
		{
			printf("%c", *(p + i));
		}
		printf("\nDo you want to correct this text?(1 - Yes, 0 - No)\n");
		while (1) {
			scanf_s("%d", &temp);
			if (temp == 1) {
				printf("Corrected text:\n");
				correct_string(p, len_mass);
				for (i = 0; i < len_mass; i++)
				{
					printf("%c", *(p + i));
				}
				break;
			}
			if (temp == 0) {
				printf("Text was not corrected : ");
				break;
			}
			else { 
				printf("Noncorrect type of working, enter type again : "); 
			}
		}
		free(p);
		printf("\nflow = %d\n", _CrtDumpMemoryLeaks());
		printf("Press '1' to repeat the program\n");
		scanf_s("%d", &g);
	} while (g == 1);
	return 0;
}