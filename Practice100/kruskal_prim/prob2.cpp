#include <bits/stdc++.h>
using namespace std;
#define MAX_V   100005
long long INF = 0x3fffffffffffffff;


struct edge {
    int to;
    long long cost;
};
vector<edge> G[MAX_V];      // 頂点iから行ける頂点とコスト
long long mincost[MAX_V];   // 集合Xからの最短距離
bool used[MAX_V];           // 頂点iがXに含まれているかどうか
typedef pair<int, int> P;   // first：最短距離、second：頂点の番号
priority_queue<int, vector<int>, less<int> >costs;  // 追加した道の通行料金を高い順に並べたもの

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
        costs.push(mincost[v]);
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
    int N, M, K;
    int a, b, c;
    cin >> N >> M >> K;
    for (i=0; i<M; i++) {
        cin >> a >> b >> c;
        edge e1, e2;
        e1.to = a - 1;
        e1.cost = c;
        e2.to = b - 1;
        e2.cost = c;
        G[b-1].push_back(e1);
        G[a-1].push_back(e2);
    }
    long long ans = prim1(N);
    for (i=1; i<K; i++) {
        ans -= (long long)costs.top();
        costs.pop();
    }
    cout << ans << endl;
    return 0;
}
