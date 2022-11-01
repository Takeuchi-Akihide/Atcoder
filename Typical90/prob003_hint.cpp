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

vector<vector<int>> graph(MAX_N);
int N;

void push(int u, int d, vector<int>& dist, queue<int>& que) {
    if (dist[u] > d) {
        dist[u] = d;
        que.push(u);
    }
}

int get_farthest(int src, int *ans) {
    vector<int> dist(N, N);
    queue<int> que;
    push(src, 0, dist, que);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int v=0; v<graph[u].size(); v++) {
            push(graph[u][v], dist[u] + 1, dist, que);
        }
    }
    *ans = *max_element(dist.begin(), dist.end());
    return max_element(dist.begin(), dist.end()) - dist.begin();
}

int main(void) {
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
    
    int ans;
    int L = get_farthest(0, &ans);
    int R = get_farthest(L, &ans);
    cout << ans+1 << endl;
    return 0;
}