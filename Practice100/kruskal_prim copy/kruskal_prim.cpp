#include <bits/stdc++.h>
using namespace std;
#define MAX_V   105
long long INF = 0x3fffffffffffffff;

int cost[MAX_V][MAX_V];     // cost[u][v] := 辺e=(u,v)のコスト
int mincost[MAX_V];         // 集合Xからの辺の最小コスト
bool used[MAX_V];           // 頂点iがXに含まれているかどうか
// int v;

/* O(V^2)のやり方 */
int prim2(int V) {
    int i;
    for (i=0; i<V; i++) {
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;

    while(1) {
        int v = -1;
        int u;
        // Xに属さない頂点のうち、Xからの辺のコストが最小になる頂点を探す
        for (u=0; u<V; u++) {
            if(!used[u] && (v==-1 || mincost[u] < mincost[v])) {
                v = u;
            }
        }
        if (v == -1) break;
        used[v] = true;
        res += mincost[v];
        for (int u=0; u<V; u++) {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}

/* O(V*logE)のやり方 */
int prim1(int V) {
    int i;
    priority_queue<P, vector<P>, greater<P> >que;
    fill(mincost, mincost + V, INF);
    mincost[0] = 0;
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

struct edge {int u, v, cost; };
bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}
edge es[MAX_E];

int kruskal(int V, int E) {     // V:=頂点数、 E:=辺数
    int i;
    sort(es, es + E, comp);     // edge.costの昇順にソート
    init_union_find(V);
    int res = 0;
    for (i=0; i<E; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
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
