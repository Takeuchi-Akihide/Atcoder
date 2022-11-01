#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = atcoder::modint998244353;
#define     MAX_N   200005

// vector<int> dist(MAX_N, MAX_N);
vector<vector<int>> graph(MAX_N);
int N;

void push(int u, int d, vector<int>& dist, queue<int>& que) {
    if (dist[u] > d) {
        dist[u] = d;
        que.push(u);
    }
}

int get_farthest(int src) {
    // for (int i=0; i<N; i++) {
    //     dist[i] = N;
    // }
    // memcpy(*dist, *dist + N, N);
    vector<int> dist(N, N);
    queue<int> que;
    push(src, 0, dist, que);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int v=0; v<graph[u].size(); v++) {
            push(graph[v], dist[u] + 1, dist, que);
        }
    }
    return max_element(dist.begin(), dist.end()) - dist.begin();
}

int main() {
    int i, j;
    cin >> N;
    for (i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int Q;
    cin >> Q;
    vector<vector<pair<int,int>>> query(Q);
    for (i=0; i<Q; i++) {
        int u, k;
        cin >> u >> k;
        u--;
        query[i].emplace_back(u, k);
    }
    for (i=0; i<Q; i++) {
        cout << "query[" << i << "]: " << query[i][0].first << ", " << query[i][0].second << endl;
    }
    int L = get_farthest(0);
    int R = get_farthest(L);
    vector<int> ans(Q, -1);
    for (i=0; i<Q; i++) {
        int u = query[i][0].first;
        int k = query[i][0].second;
        if (k > get_farthest(u)) continue;
        vector<int> isCheck(N, false);
        for (j=0; j<k; j++) {
            for (int l=0; l<graph[u].size(); l++) {
                int next = graph[u][i];
                if (isCheck[next] == false) {
                    isCheck[next] = true;
                    u = next;
                }
            }
        }
        ans[i] = u + 1;
    }

    for (i=0; i<Q; i++) {
        cout << ans[i] << endl;
    }    
    return 0;
}
