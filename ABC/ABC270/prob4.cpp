#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;

int main(int argc, char *argv[]) {
    int i, j;
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for (i=0; i<K; i++) {
        cin >> A[i];
    }
    vector<int> dp(N+1, 0);
    for (i=1; i<=N; i++) {
        for (j=0; j<K; j++) {
            if (A[j] > i) {
                break;
            }
            dp[i] = max(dp[i], i - dp[i-A[j]]);
        }
    }
    cout << dp[N] << endl;
    return 0;
}