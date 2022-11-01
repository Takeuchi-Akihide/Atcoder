#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       80

long long fibonacciNum[MAX_N] = {0};

int main (int argc, char *argv[]) {
    /* Nの取得 */
    int i, n;
    scanf("%d", &n);
    fibonacciNum[0] = 1;
    fibonacciNum[1] = 1;

    for (i=2; i<=n; i++) {
        fibonacciNum[i] = fibonacciNum[i-1] + fibonacciNum[i-2];
    }

    printf("%lld\n", fibonacciNum[n]);
    
    return 0;
}
