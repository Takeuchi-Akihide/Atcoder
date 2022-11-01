#include <bits/stdc++.h>
using namespace std;
#define MAX_V   105
long long INF = 0x3fffffffffffffff;

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
    int V, E;
    int a, b, c;
    cin >> V >> E;
    for (i=0; i<V; i++) {
        for (j=0; j<V; j++) {
            if (i == j) {
                cost[i][j] = 0;
                d[i][j] = 0;
            } else {
                cost[i][j] = INF;
                d[i][j] = INF;
            }
        }
    }
    for (i=0; i<E; i++) {
        cin >> a >> b >> c;
        cost[a][b] = c;
        d[a][b] = c;
    }
    warshall_floyd(V);
    for (i=0; i<V; i++) {
        if (d[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for (i=0; i<V; i++) {
        for (j=0; j<V; j++) {
            if (d[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
