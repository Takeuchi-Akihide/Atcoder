#include <bits/stdc++.h>
using namespace std;
#define MAX_V   100001
#define INF     0x3fffffff

struct edge {
    int to;
    long long cost;
};
vector<edge> G[MAX_V];
long long d[MAX_V];           // 頂点sからの最短距離
typedef pair<int, int> P;   // first：最短距離、second：頂点の番号

void dijkstra(int V, int s) {
    int i;
    priority_queue<P, vector<P>, greater<P> >que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (i=0; i<G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

// long long cost[MAX_V][MAX_V];   // cost[i][j]:=頂点i→jへのコスト
// long long d[MAX_V];             // 頂点sからの最短距離
// bool used[MAX_V];               // 頂点sを探索済みか？

// void dijkstra(int V, int r) {
//     fill(d, d+V, INF);
//     fill(used, used + V, false);
//     d[r] = 0;
    
//     while (1) {
//         int v = -1;
//         for (j=0; j<V; j++) {
//             if (!used[j] && (v == -1 || d[j] < d[v])) {
//                 v = j;
//             }
//         }
//         if (v == -1) break;
//         used[v] = true;
//         for (j=0; j<V; j++) {
//             if (!(cost[v][j] == INF)) {
//                 d[j] = min(d[j], d[v] + cost[v][j]);
//             }
//         }
//     }
//     return;
// }

int main(void) {
    int i, j;
    int V, E, r;
    cin >> V >> E >> r;
    int s, t;
    long long u;
    for (i=0; i<E; i++) {
        cin >> s >> t >> u;
        edge e;
        e.to = t;
        e.cost = u;
        G[s].push_back(e);
        // cost[s][t] = u;
    }

    dijkstra(V, r);
    for (j=0; j<V; j++) {
        cout << d[j] << endl;
    }
    return 0;
}
