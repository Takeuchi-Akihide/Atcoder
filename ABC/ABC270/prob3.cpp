#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
#define MAX_N   100005

int main(void) {
    int i, j;
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<vector<int>> graph(N);
    X--;
    Y--;
    for (i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    stack<int> que;
    vector<int> isCheck(N, false);
    vector<int> before(N, false);
    que.push(Y);
    isCheck[Y] = true;
    while (true) {
        int now = que.top();
        que.pop();
        isCheck[now] = true;
        if (now == X) {
            break;
        }
        for (i=0; i<graph[now].size(); i++) {
            int next = graph[now][i];
            if (isCheck[next]) continue;
            que.push(next);
            before[next] = now;
        }
    }
    int now = X;
    while(now != Y) {
        cout << now+1 << " ";
        now = before[now];
    }
    cout << Y+1 << endl;

    return 0;
}