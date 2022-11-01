#include <bits/stdc++.h>
using namespace std;
#define MAX_V   10005
#define MAX_E   100005
long long INF = 0x3fffffffffffffff;


struct edge {
    int to;
    long long cost;
};
vector<edge> G[MAX_V];      // 頂点iから行ける頂点とコスト
long long mincost[MAX_V];   // 集合Xからの最短距離
bool used[MAX_V];           // 頂点iがXに含まれているかどうか
typedef pair<int, int> P;   // first：最短距離、second：頂点の番号

long long prim1(int V) {
    int i;
    priority_queue<P, vector<P>, greater<P> >que;
    fill(mincost, mincost + V, INF);
    fill(used, used + V, false);
    mincost[0] = 0;
    long long res = 0;
    que.push(P(0, 0));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (mincost[v] < p.first) continue;
        res += mincost[v];
        used[v] = true;
        for (i=0; i<G[v].size(); i++) {
            edge e = G[v][i];
            if (!used[e.to] && mincost[e.to] > e.cost) {
                mincost[e.to] = e.cost;
                que.push(P(mincost[e.to], e.to));
            }
        }
    }
    return res;
}

int main(void) {
    int i, j;
    int V, E;
    int a, b, c;
    cin >> V >> E;
    for (i=0; i<E; i++) {
        cin >> a >> b >> c;
        edge e1, e2;
        e1.to = a;
        e1.cost = c;
        e2.to = b;
        e2.cost = c;
        G[b].push_back(e1);
        G[a].push_back(e2);
    }
    long long ans = prim1(V);
    cout << ans << endl;
    return 0;
}
