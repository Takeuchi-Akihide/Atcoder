#include <bits/stdc++.h>
using namespace std;
#define MAX_V   305
long long INF = 0x3fffffff;

long long d[MAX_V][MAX_V];           // 頂点sからの最短距離
long long cost[MAX_V][MAX_V];

void warshall_floyd(int V) {
    int i, j, k;
    for (k=0; k<V; k++) {
        for (i=0; i<V; i++) {
            for (j=0; j<V; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(void) {
    int i, j;
    int H, W;
    int num[11] = {0};
    int A;
    cin >> H >> W;
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            if (i == j) {
                cost[i][j] = 0;
                d[i][j] = 0;
            } else {
                cost[i][j] = INF;
                d[i][j] = INF;
            }
        }
    }
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            cin >> cost[i][j];
            d[i][j] = cost[i][j];
        }
    }
    for (i=1; i<=H; i++) {
        for (j=1; j<=W; j++) {
            cin >> A;
            if (A != -1) {
                num[A]++;
            }
        }
    }
    warshall_floyd(10);
    long long ans = 0;
    for (i=0; i<10; i++) {
        ans += num[i] * d[i][1];
    }
    cout << ans << endl;
    return 0;
}
