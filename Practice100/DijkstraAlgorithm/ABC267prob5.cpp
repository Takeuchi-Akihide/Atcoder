#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX_V       200005

ll cost[MAX_V];        // 各頂点のコスト
vector<int> connect[MAX_V];     // つながっている頂点
typedef pair<ll, int> P;       // first：cost、second：頂点の番号

int main() {
    int i, j;
    int N, M;
    int U, V;
    ll A[MAX_V];
    cin >> N >> M;
    for (i=1; i<=N; i++) {
        cin >> A[i];
    }
    for (i=1; i<=M; i++) {
        cin >> U >> V;
        cost[U] += A[V];
        cost[V] += A[U];
        connect[U].push_back(V);
        connect[V].push_back(U);
    }

    priority_queue<P, vector<P>, greater<P> >que;
    for (i=1; i<=N; i++) {
        que.push(P(cost[i], i));
    }
    long long ans = 0;
    vector<bool> erased(N);
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (erased[v]) continue;
        ans = max(p.first, ans);
        erased[v] = true;
        for (i=0; i<connect[v].size(); i++) {
            int next = connect[v][i];
            if (!erased[next]) {
                cost[next] -= A[v];
                que.push(P(cost[next], next));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
