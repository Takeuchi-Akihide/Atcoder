#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;
#define MAX_N   100005
#define INF     (1 << 30)


struct edge {
    int to;
    long long cost;
};
vector<edge> G[MAX_N];
typedef pair<int, int> P;   // first：最短距離、second：頂点の番号

void dijkstra(int V, int s, vector<int>& d) {
    int i;
    priority_queue<P, vector<P>, greater<P> >que;
    for (i=0; i<V; i++) {
        d[i] = INF;
    }
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (i=0; i<(int)G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(void) {
    int i;
    int N, M;
    cin >> N >> M;
    vector<int> d1(N);
    vector<int> d2(N);
    int a, b, c;
    for (i=0; i<M; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        edge e1, e2;
        e1.cost = c; e1.to = b;
        e2.cost = c; e2.to = a;
        G[a].push_back(e1);
        G[b].push_back(e2);
    }
    dijkstra(N, 0, d1);
    dijkstra(N, N-1, d2);
    for (i=0; i<N; i++) {
        cout << d1[i] + d2[i] << endl;
    }
    return 0;
}