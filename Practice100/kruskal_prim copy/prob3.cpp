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
    int N;
    // int x[MAX_V], y[MAX_V];
    priority_queue<P, vector<P>, greater<P> >x_que;
    priority_queue<P, vector<P>, greater<P> >y_que;
    int x, y;
    cin >> N;
    for (i=0; i<N; i++) {
        cin >> x >> y;
        x_que.push(P(x, i));
        y_que.push(P(y, i));
    }

    for (i=0; i<N-1; i++) {
        edge e1, e2;
        P x1 = x_que.top();
        x_que.pop();
        P x2 = x_que.top();
        int costx = abs(x1.first - x2.first);
        e1.cost = costx;
        e1.to = x2.second;
        e2.cost = costx;
        e2.to = x1.second;
        G[x1.second].push_back(e1);
        G[x2.second].push_back(e2);
        
        P y1 = y_que.top();
        y_que.pop();
        P y2 = y_que.top();
        int costy = abs(y1.first - y2.first);
        e1.cost = costy;
        e1.to = y2.second;
        e2.cost = costy;
        e2.to = y1.second;
        G[y1.second].push_back(e1);
        G[y2.second].push_back(e2);
    }
    long long ans = prim1(N);
    cout << ans << endl;
    return 0;
}
