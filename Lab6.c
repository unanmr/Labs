#include <stdio.h>
#include <stdlib.h>

double* LAB(double **m,double M,double N){
int i,j;
double sum=0,sred=0;
double* new_m = malloc(sizeof(double)*N);
for (i = 0; i < N; i++){
for (j = 0; j < M; j++){
sum = sum + m[i][j];
}
sred = sum/M;
new_m[i] = sred;
sum = 0;

}

return new_m;
}

int main(int argc, const char * argv[]) {
double N,M;
int i,j;
printf("\nM = ");
scanf("%lf", &M);
printf("\nN = ");
scanf("%lf", &N);

double** m = (double**)malloc(sizeof(double)*N);
for (i = 0; i < N; i++){
m[i] = (double*)malloc(sizeof(double)*M);
}
for (i = 0; i < N; i++)
{
for (j = 0; j < M; j++){
printf("m[%d][%d] = ", i ,j );
scanf("%lf", &m[i][j]);
}

}
for (i = 0; i < N; i++){
printf("\n");
for (j = 0; j < M; j++){
printf(" %lf",m[i][j]);
}
}
double *new_m = LAB(m,M,N);
for (i = 0; i < N; i++){

printf("\nnew_m[%d] = %lf", i ,new_m[i] );
}
free(new_m);
free(m);
return 0;
}
