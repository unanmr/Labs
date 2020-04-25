#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double ryadchos(double x, double eps) {
double val = 0, cur = 1, dif;
int n = 1;

val = cur;

while (cur > eps)
{

cur = cur / ((2 * n)*(2 * n - 1))*(x*x) * 4;
val = val + cur;
n++;
if (n == 3)
{
printf("/n");
}
}

val += x;

printf("\nval = %lf\nlib = %lf", val, cosh(2 * x) + x);
dif = cosh(2 * x) + x - val;
printf("\ndif = %lf", dif);
return dif;
}

int main(int argc, const char * argv[]) {
double x, eps, a;
printf("\nxxxx=");
scanf_s("%lf", &x);

printf("\nepsss=");
scanf_s("%lf", &eps);

a = ryadchos(x, eps);
printf("%lf\n", a);

system("pause");
}
