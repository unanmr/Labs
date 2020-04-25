#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale>
#include <ctime>
using namespace std;

int* readfile(char *path, size_t *l)
{
	int *la = 0;
	FILE *fin = fopen(path, "r");
	if (fin != 0)
	{
		fscanf(fin, "%d", l);
		la = (int*)calloc(*l, sizeof(int));
		size_t i = 0;
		while (i < *l)
		{
			fscanf(fin, "%d", &la[i]);
			i++;
		}
		fclose(fin);
	}
	return la;
}

int writefile(char* path, int* arr, size_t l)
{
	FILE *fout = fopen(path, "w");
	if (fout != 0)
	{
		fprintf(fout, "%d", l);
		size_t i = 0;
		while (i < l)
		{
			fprintf(fout, " %d", arr[i]);
			i++;
		}
		fclose(fout);
		return 1;
	}
	return 0;
}

int* copyarr(int* arr, size_t l)
{
	int *ca = (int*)calloc(l, sizeof(int));
	size_t i = 0;
	for (; i < l; i++)
	{
		ca[i] = arr[i];
	}
	return ca;
}

int* insertionsort(int *arr, size_t l)
{
	int* arris = copyarr(arr, l);
	int temp;
	for (size_t i = 1; i < l; i++)
	{
		temp = arris[i];
		int j = i - 1;
		while (j >= 0 && arris[j] > temp)
		{
			arris[j + 1] = arris[j];
			j = j - 1;
		}
		arris[j + 1] = temp;
	}
	return arris;
}


int main(void)
{
	setlocale(LC_ALL, "Rus");

	char filein[] = "lab5datain.txt";
	char fileout1[] = "lab5dataout1.txt";

	size_t l, i = 0;
	int *arr;
	arr = readfile(filein, &l);

	if (arr == 0)
	{
		printf("\nНе удалось прочитать файл.");
		return 0;
	}
	printf("\nСчитанный массив: \n");

	for (; i < l; i++)
		printf("%d ", arr[i]);
	printf("\n");

	double start_time_1 = clock();
	int* arris = insertionsort(arr, l);
	double end_time_1 = clock();
	double search_time_1 = (double)(start_time_1 - end_time_1) / CLOCKS_PER_SEC;
	printf("\nTime 1 = %f\n ", search_time_1);

	printf("\nWrite attempt: %d\n", writefile(fileout1, arris, l));
	printf("\nОтсортированный в возрастающем порядке массив :\n");
	for (i = 0; i < l; i++)
		printf("%d ", arris[i]);
	printf("\n");

	if (arr != 0)
	{
		free(arr);
		free(arris);
	}
	system("pause");

	return 0;
}
