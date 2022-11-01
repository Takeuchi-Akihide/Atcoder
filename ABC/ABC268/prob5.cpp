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

int main(int argc, char *argv[]) {
    int i, j;
    int N;
    cin >> N;
    vector<int> p(N);
    for (i=0; i<N; i++) {
        cin >> p[i];
    }

    ll ans = 0;
    // 初期値の答えを求める
    for (i=0; i<N; i++) {
        int d = (p[i] - i + N) % N;
        ans += min(d, N-d);
    }

    ll delta = 0;
    vector<int> e(N+1, 0);
    if (N % 2 == 0) {
        for (i=0; i<N; i++) {
            int d = (i-p[i]+N) % N; // 不満度0の地点から回した回数
            if (d < N/2) delta++;   // 半分より小さかったら、1回転後は1増える
            if (d >= N/2) delta--;  // 半分以上だったら、1回転後は1減る
            e[(N-d)%N] += 2;        // 不満度0の地点はedge(+2)
            e[(N-d+N/2)%N] -= 2;    // 不満度0の地点からN/2進んだ地点はedge(-2)
        }
    } else {
        for (i=0; i<N; i++) {
            int d = (i-p[i]+N) % N; // 不満度0の地点から回した回数
            if (d < N/2) delta++;   // 半分より小さかったら、1回転後は1増える
            if (d >= (N+1)/2) delta--;  // 半分以上だったら、1回転後は1減る
            e[(N-d)%N] += 2;        // 不満度0の地点はedge(+2)
            e[(N-d+(N+1)/2)%N] -= 1;    // 不満度0の地点からN/2進んだ地点はedge(-1)
            e[(N-d+(N-1)/2)%N] -= 1;    // 不満度0の地点からN/2進んだ地点はedge(-1)
        }
    }
    
    ll now = ans;
    for (i=0; i<N; i++) {
        now += delta;
        ans = min(now, ans);
        delta += e[i+1];
    }

    cout << ans << endl;
    return 0;
}