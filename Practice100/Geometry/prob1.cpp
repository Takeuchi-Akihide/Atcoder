#include <bits/stdc++.h>
using namespace std;
#define MAX_N       205


int main(void) {
    int i, j;
    int N, M;
    int x[MAX_N], y[MAX_N];
    double r[MAX_N];
    cin >> N >> M;
    for (i=1; i<=N; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (i=N+1; i<=N+M; i++) {
        cin >> x[i] >> y[i];
    }

    for (i=N+1; i<=N+M; i++) {
        r[i] = 400;
        for (j=1; j<=M+N; j++) {
            if (i == j) continue;
            double tmpR = pow(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2), 0.5);
            if (j <= N) tmpR -= r[j];
            else tmpR /= 2;
            if (tmpR < r[i]) r[i] = tmpR;
        }
    }
    double min = 400;
    for (i=1; i<=N+M; i++) {
        if (r[i] < min) min = r[i];
    }
    cout << fixed << setprecision(15) << min << endl;
    return 0;
}
