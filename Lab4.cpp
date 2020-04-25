#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* STR(char* str, int *t)
{
	int q;
	q = 0;
	int i = 0;
	char* new_str = (char*)malloc(80);
	for (; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			new_str[i] = str[i];
		}
		else
		{
			new_str[i] = '_';
			q++;
		}
	}
	*t = q;
	new_str[i] = '\0';
	return new_str;
}

int main()
{
	int t = 0;
	char* my_str = (char*)malloc(80);
	printf("Input text:");
	gets(my_str);
	char* new_str = STR(my_str, &t);
	puts(new_str);
	printf("\nNumber of punctuation marks :");
	printf("%d", t);
	free(new_str);
	free(my_str);
}
