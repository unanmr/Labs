#include <stdio.h>
#include <limits.h>
#include <iostream> 
#include <time.h>
  
#pragma warning(disable : 4996)
typedef unsigned uint;
#define swap(a, b) { tmp = a; a = b; b = tmp; }
#define each(i, x) for (i = 0; i < x; i++)
  
/* sort unsigned ints */
static void rad_sort_u(uint *from, uint *to, uint bit)
{
    if (!bit || to < from + 1) return;
  
    uint *ll = from, *rr = to - 1, tmp;
    while (1) {
        /* find left most with bit, and right most without bit, swap */
        while (ll < rr && !(*ll & bit)) ll++;
        while (ll < rr &&  (*rr & bit)) rr--;
        if (ll >= rr) break;
        swap(*ll, *rr);
    }
  
    if (!(bit & *ll) && ll < to) ll++;
    bit >>= 1;
  
    rad_sort_u(from, ll, bit);
    rad_sort_u(ll, to, bit);
}
  
/* sort signed ints: flip highest bit, sort as unsigned, flip back */
static void radix_sort(int *a, const size_t len)
{
    size_t i;
    uint *x = (uint*) a;
	int k = INT_MIN;
    each(i, len) x[i] ^= INT_MIN;
    rad_sort_u(x, x + len, INT_MIN);
    each(i, len) x[i] ^= INT_MIN;
}

int irand(int a, int b)
{
	return a + rand() % (b - a + 1);
}

void rand_arr(FILE* F, int* A, int size)
{
	for (int i = 0; i < size; i++) {
		A[i] = irand(1, 1000000);
		fprintf(F, "%d ", A[i]);
	}
	fclose(F);
}

void WriteToFile(FILE *F, int *A, int size)
{
	for (int i = 0; i < size; i++) {
		fprintf(F, "%d ", A[i]);
	}
	fclose(F);
}

static inline void radix_sort_unsigned(uint *a, const size_t len)
{
    rad_sort_u(a, a + len, (uint)INT_MIN);
}
  
int main(void)
{
	int N, i=0;
	clock_t start_t;
    //int len = 100, x[100];
	printf("Array size=");
	scanf("%d", &N);
	int *A = (int*)calloc(N, sizeof(int));
	FILE *F1;
	
	F1 = fopen("input.txt", "w");
	rand_arr(F1, A, N);
	F1 = fopen("Radix_sort.txt", "w");
	start_t = clock();
	radix_sort(A, N);
	start_t = clock() - start_t;
	WriteToFile(F1, A, N);
	fclose(F1);
	free(A);

	printf("The array was sorted with Rdix sort by %lf\n", (float)start_t / CLOCKS_PER_SEC);
	system("pause");
}
