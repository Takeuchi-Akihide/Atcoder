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
    }

    dijkstra(V, r);
    for (j=0; j<V; j++) {
        cout << d[j] << endl;
    }
    return 0;
}
