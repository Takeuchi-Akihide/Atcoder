#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define MAX_N   100005
#define MAX_A   1000001
#define INF (1 << 30)

struct edge {
    int to;
    long long cost;
};
vector<edge> G[MAX_N];
vector<vector<bool>> used(MAX_N, vector<bool>(MAX_N, false));

int main(void) {
    int i, j;
    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    vector<int> Y(N);
    vector<int> XY(N);
    vector<int> car(N, -1);
    // vector<vector<int>> graph(N, vector<int>(N, INF));
    int hub = 0;
    int hubXY = INF;
    for (i=0; i<N; i++) {
        cin >> X[i];
    }
    for (i=0; i<N; i++) {
        cin >> Y[i];
        XY[i] = X[i] + Y[i];
        if (XY[i] < hubXY) {
            hubXY = XY[i];
            hub = i;
        }
    }
    for (i=0; i<M; i++) {
        int a, b, Z;
        cin >> a >> b >> Z;
        a--;
        b--;
        edge e1, e2;
        e1.to = b;
        e1.cost = Z;
        G[a].push_back(e1);
        e2.to = a;
        e2.cost = Z;
        G[b].push_back(e2);
    }
    ll ans[3] = {0};
    // 空港のみ
    for (i=0; i<N; i++) {
        ans[0] += X[i];
        ans[1] += Y[i];
        if (i == hub) {
            ans[2] += hubXY;
        } else {
            XY[i] = min(X[i], Y[i]);
            ans[2] += XY[i];
        }
    }
    int minN = 0;
    if (ans[0] > ans[i]) {
        minN = 1;
    }
    if (minN) {
        for (i=0; i<N; i++) {
            int to;
            for (j=0; j<G[i].size(); j++) {
                if (G[i][j].cost < X[i]) {
                    to = G[i][j].to;
                    if (car[to] == i) continue;
                    if (X[to] > X[i]) {
                        car[to] = i;
                        X[to] = G[i][j].cost;
                        ans[0] -= (X[to] - G[i][j].cost);
                    } else {
                        car[i] = to;
                        X[i] = G[i][j].cost;
                        ans[0] -= (X[i] - G[i][j].cost);
                    }
                }
            }
        }
    } else {
        for (i=0; i<N; i++) {
            int to;
            for (j=0; j<G[i].size(); j++) {
                if (G[i][j].cost < Y[i]) {
                    to = G[i][j].to;
                    if (car[to] == i) continue;
                    if (Y[to] > Y[i]) {
                        car[to] = i;
                        Y[to] = G[i][j].cost;
                        ans[1] -= (Y[to] - G[i][j].cost);
                    } else {
                        car[i] = to;
                        Y[i] = G[i][j].cost;
                        ans[1] -= (Y[i] - G[i][j].cost);
                    }
                }
            }
        }
    }
    for (i=0; i<N; i++) {
        int to;
        if (i == hub) continue;
        for (j=0; j<G[i].size(); j++) {
            if (G[i][j].cost < XY[i]) {
                to = G[i][j].to;
                if (car[to] == i) continue;
                if (XY[to] > XY[i]) {
                    car[to] = i;
                    XY[to] = G[i][j].cost;
                    ans[2] -= (XY[to] - G[i][j].cost);
                } else {
                    car[i] = to;
                    XY[i] = G[i][j].cost;
                    ans[2] -= (XY[i] - G[i][j].cost);
                }
            }
        }
    }
    ll res = min(ans[0], ans[1]);
    res = min(res, ans[2]);
    cout << res << endl;

    return 0;
}