#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define MAX_N   10005
#define MAX_K   5005
long long INF = 0x3fffffffffffffff;

long long cost[MAX_N][MAX_N];
long long dis[MAX_N];         // 頂点sからの最短距離
typedef pair<int, int> P;   // first：最短距離、second：頂点の番号
long long ans[MAX_N];
// bool used[MAX_N];

// void dijkstra(int V, int r) {
//     int j;
//     fill(dis, dis + V + 1, INF);
//     fill(used, used + V + 1, false);
//     dis[r] = 0;
    
//     while (1) {
//         int v = -1;
//         for (j=1; j<=V; j++) {
//             if (!used[j] && (v == -1 || dis[j] < dis[v])) {
//                 v = j;
//             }
//         }
//         if (v == -1) break;
//         used[v] = true;
//         for (j=1; j<=V; j++) {
//             if ((cost[v][j] != INF)) {
//                 dis[j] = min(dis[j], dis[v] + cost[v][j]);
//             }
//         }
//     }
//     return;
// }
long long dijkstra(int V, int s, int g) {
    // int i;
    // priority_queue<P, vector<P>, greater<P> >que;
    // fill(dis, dis + V + 1, INF);
    // dis[s] = 0;
    // que.push(P(0, s));
    // while(!que.empty()) {
    //     P p = que.top();
    //     que.pop();
    //     int v = p.second;
    //     if (dis[v] < p.first) continue;
    //     if (v == g) return dis[v];
    //     for (i=0; i<G[v].size(); i++) {
    //         edge e = G[v][i];
    //         if (dis[e.to] > dis[v] + e.cost) {
    //             dis[e.to] = dis[v] + e.cost;
    //             que.push(P(dis[e.to], e.to));
    //         }
    //     }
    // }
    int i;
    priority_queue<P, vector<P>, greater<P> >que;
    fill(dis, dis + V + 1, INF);
    dis[s] = 0;
    que.push(P(0, s));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        if (p.first == INF) break;
        int v = p.second;
        if (dis[v] < p.first) continue;
        if (v == g) return dis[v];
        // used[v] = true;
        for (i=1; i<=V; i++) {
            // if (used[i]) continue;
            if (cost[v][i] != INF && dis[i] > dis[v] + cost[v][i]) {
                dis[i] = dis[v] + cost[v][i];
                que.push(P(dis[i], i));
            }
        }
    }
    return -1;
}

int main(void) {
    int i, j;
    int n, k;
    int ansn = 0;
    cin >> n >> k;
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            if (i == j)     cost[i][j] = 0;
            else            cost[i][j] = INF;
        }
    }
    
    for (i=0; i<k; i++) {
        int buf;
        cin >> buf;
        if (buf == 0) {
            int a, b;
            cin >> a >> b;
            ans[ansn] = dijkstra(n, a, b);
            // ans[ansn] = dis[b];
            // if (ans[ansn] == INF) ans[ansn] = -1;
            ansn++;
        } else if (buf == 1) {
            int c, d, e;
            cin >> c >> d >> e;
            if (cost[c][d] > e) {
                cost[c][d] = e;
                cost[d][c] = e;
            }
        }
    }
    for (i=0; i<ansn; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
