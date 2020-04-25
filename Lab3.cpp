#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str(char* str, char *new_str)
{
	int i = 0;
	for (; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
		{
			new_str[i] = str[i] - 32;
		}
		else
		{
			new_str[i] = str[i];
		}
	}

	new_str[i] = '\0';
}

int main()
{
	char* my_str = (char*)malloc(80);
	gets(my_str);
	char* res_str = (char*)malloc(80);
	str(my_str, res_str);
	puts(res_str);
	free(res_str);
	free(my_str);
	return 0;
}
