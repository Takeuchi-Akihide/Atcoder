#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define MAX_V   200005
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

enum {
    Safe = 0,
    Danger,
    Unreach,
};

int main(int argc, char *argv[]) {
    int i, j, k;
    int N, M, K, S;
    long long P, Q;
    int City[MAX_V];
    queue<int> q;
    cin >> N >> M >> K >> S;
    cin >> P >> Q;
    for (i=1; i<=N; i++) {
        City[i] = Safe;
    }
    for (i=0; i<K; i++) {
        int buf;
        cin >> buf;
        City[buf] = Unreach;
        q.push(buf);
    }
    for (i=0; i<M; i++) {
        int A, B;
        cin >> A >> B;
        edge e1, e2;
        e1.to = B;
        e1.cost = P;
        G[A].push_back(e1);
        e2.to = A;
        e2.cost = P;
        G[B].push_back(e2);
    }

    // 幅優先探索
    for(i=0; i<=S; i++){
		if(q.empty())break;
		
		for(j=q.size()-1; j>=0; j--){
			int from = q.front();
            q.pop();
			if (City[from] == Danger) continue;
            if (City[from] == Safe) {
    			City[from] = Danger;
            }
            if (!G[from].empty()) {
                for(k=0; k<G[from].size(); k++){
                    q.push(G[from][k].to);
                }
            }
		}
	}
    for (i=1; i<=N; i++) {
        if (G[i].empty()) {
            continue;
        }
        for (j=0; j<G[i].size(); j++) {
            if (City[G[i][j].to] == Unreach) {
                G[i][j].cost = INF;
            } else if (City[G[i][j].to] == Danger) {
                G[i][j].cost = Q;
            }
            if (G[i][j].to == N) {
                G[i][j].cost = 0;
            }
        }
    }
    dijkstra(N, 1);
    cout << d[N] << endl;
    return 0;
}