#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[]) {
    /* Pの取得 */
    double P;
    scanf("%lf", &P);

    double start_min = 0;
    double start_max = P;
    double start_mid;
    double mid;
    double deltam, deltas;
    const double DELTA = pow(0.1, 10);
    
    while (start_min <= start_max) {
        start_mid = (start_min + start_max) / 2;
        deltas = (start_max - start_min) / 100;
        mid = start_mid + P / (pow(2, (start_mid/1.5)));
        deltam = (start_mid + deltas) + P / (pow(2, ((start_mid + deltas)/1.5)));
        if (fabs(mid - deltam) < DELTA) {
            break;
        } else if (mid - deltam > 0) {
            start_min = start_mid;
        } else {
            start_max = start_mid;
        }
    }
    printf("%.10f\n", mid);
    return 0;
}
