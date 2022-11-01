#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char *argv[]) {
    int i, j;

    /* Nの取得 */
    int N;
    scanf("%d", &N);
    int M = N * 2;
    int x;
    int a, b;
    a = N / 4;
    b = N % 4;
    printf("%d\n", M);
    if (b != 0) {
        printf("%d", b);
    }
    for (i=0; i<a; i++) {
        printf("4");
    }
    printf("\n");
    return 0;
}
