#include <bits/stdc++.h>
using namespace std;
#define MAX_V   305
long long INF = 0x3fffffffffff;

long long d[MAX_V][MAX_V];           // 頂点sからの最短距離
long long cost[MAX_V][MAX_V];
bool road[MAX_V][MAX_V];

void warshall_floyd(int V) {
    int i, j, k;
    for (k=1; k<=V; k++) {
        for (i=1; i<=V; i++) {
            for (j=1; j<=V; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return;
}

int main(void) {
    int i, j, k;
    int N;
    long long ans = 0;
    cin >> N;
    for (i=1; i<=N; i++) {
        for (j=1; j<=N; j++) {
            cin >> cost[i][j];
            d[i][j] = cost[i][j];
            road[i][j] = true;
        }
    }
    warshall_floyd(N);
    for (i=1; i<=N; i++) {
        for (j=1; j<=N; j++) {
            if (d[i][j] < cost[i][j]) {
                cout << "-1" << endl;
                return 0;
            }
            for (k=1; k<=N; k++) {
                if (i != k && j != k && d[i][j] == d[i][k] + d[k][j]) {
                    road[i][j] = false;
                    continue;
                }
            }
            if (road[i][j]) ans += cost[i][j];
        }
    }
    cout << ans/2 << endl;
    return 0;
}
