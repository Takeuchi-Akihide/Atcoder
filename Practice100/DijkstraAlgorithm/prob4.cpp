#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define MAX_V   10005
long long INF = 0x3fffffffffffffff;

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
    fill(d, d + V + 1, INF);
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

int main(int argc, char *argv[]) {
    int i, j, k, l;
    int N, K;
    int C[MAX_V], R[MAX_V];
    queue<int> q[MAX_V];
    vector<int> map[MAX_V];
    cin >> N >> K;
    for (i=1; i<=N; i++) {
        cin >> C[i] >> R[i];
        q[i].push(i);
    }
    for (i=0; i<K; i++) {
        int A, B;
        cin >> A >> B;
        map[A].push_back(B);
        map[B].push_back(A);
    }

    // 幅優先探索
    edge e;
    for (i=1; i<=N; i++) {
        bool used[MAX_V] = {false};
        for (j=1; j<=R[i]; j++) {
            if (q[i].empty()) break;

            for (k=q[i].size()-1; k>=0; k--) {
                int from = q[i].front();
                q[i].pop();
                if (map[from].empty()) {
                    continue;
                }
                for(l=0; l<map[from].size(); l++){
                    int next = map[from][l];
                    if (!used[next] && i != next) {
                        q[i].push(next);
                        e.to = next;
                        e.cost = C[i];
                        G[i].push_back(e);
                        used[next] = true;
                    }
                }
            }
        }
    }
    dijkstra(N, 1);
    cout << d[N] << endl;
    return 0;
}