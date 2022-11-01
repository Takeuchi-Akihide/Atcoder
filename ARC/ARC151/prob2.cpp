#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define MOD 998244353

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(void) {
    ll N, M;
    cin >> N >> M;
    vector<int> P(N+1);
    vector<bool> used(N+1, false);
    for (int i=1; i<=N; i++) {
        cin >> P[i];
    }
    int remain = 0;
    mint ans = 0;
    for (int i=1; i<=N; i++) {
        cout << "i: " << i << ", P[i]: " << P[i] << ", ans: " << ans.val() << endl;
        if (P[i] == i || used[i]) {
            used[i] = true;
            continue;
        } else {
            remain++;
            used[i] = true;
            if (!used[P[i]]) {
                remain++;
                used[P[i]] = true;
            }
            ll tmp = (pow(M, N - remain) * ((M * (M-1) / 2) % MOD)) % MOD;
            ans += tmp;
        }
    }
    cout << ans.val() << endl;
    return 0;
}