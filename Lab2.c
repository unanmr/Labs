#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

double gradus(int x, int* S)
{
	int a = 0;
	int b = 0;
	double pi = 3.14159265358979323846;
	double alpha = 0;
	double sum = 0;

	for (int i = 0; i <(x*x) - x; i += x)
	{
		alpha = 0;
		a = 0;
		b = 0;
		for (int j = 0; j < x; j++)
		{
			alpha = alpha + (S[i + j] * S[i + j + x]);
			a = a + S[i + j];
			b = b + S[i + j + x];
		}
		alpha = acos((float)alpha / (a*b));
		alpha *= 180 / pi;
		printf("%f \n", alpha);
		sum += alpha;

	}

	return sum;
}

int main(void)
{
	int x = 0;
	double ans = 0;
	scanf_s("%d", &x);
	int* S = (int*)malloc(x*x * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < x*x; i++)
	{
		if (i % x == 0)
			printf("\n");

		S[i] = rand() % 10;
		printf("%d  ", S[i]);

	}
	printf("\n");
	ans = gradus(x, S);
	printf("\n %f", (ans / x - 1));
	getchar();
	getchar();
	return 0;
}
