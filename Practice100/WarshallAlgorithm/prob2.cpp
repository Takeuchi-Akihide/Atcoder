#include <bits/stdc++.h>
using namespace std;
#define MAX_V   305
long long INF = 0x3fffffff;

long long d[MAX_V][MAX_V];           // 頂点sからの最短距離
long long cost[MAX_V][MAX_V];

void warshall_floyd(int V) {
    int i, j, k;
    for (k=1; k<=V; k++) {
        for (i=1; i<=V; i++) {
            for (j=1; j<=V; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(void) {
    int i, j;
    int N, M;
    int a, b, c;
    cin >> N >> M;
    for (i=1; i<=N; i++) {
        for (j=1; j<=N; j++) {
            if (i == j) {
                cost[i][j] = 0;
                d[i][j] = 0;
            } else {
                cost[i][j] = INF;
                d[i][j] = INF;
            }
        }
    }
    for (i=0; i<M; i++) {
        cin >> a >> b >> c;
        cost[a][b] = c;
        cost[b][a] = c;
        d[a][b] = c;
        d[b][a] = c;
    }
    warshall_floyd(N);
    int max_n[MAX_V];
    int min_all = INF;
    for (i=1; i<=N; i++) {
        max_n[i] = 0;
        for (j=1; j<=N; j++) {
            if (max_n[i] < d[i][j]) {
                max_n[i] = d[i][j];
            }
        }
        if (min_all > max_n[i]) {
            min_all = max_n[i];
        }
    }
    cout << min_all << endl;
    return 0;
}
