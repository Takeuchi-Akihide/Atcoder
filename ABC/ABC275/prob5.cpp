#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define MOD 998244353

int main(void) {
    int N, M, K;
    int i, j, k;
    cin >> N >> M >> K;
    vector<vector<mint>> dp(K+1, vector<mint>(N+1, 0));
    mint m_inv = mint(1) / M;
    mint ans = 0;
    dp[0][0] = 1;
    for (i=1; i<=K; i++) {
        for (j=0; j<N; j++) {
            for (k=1; k<=M; k++) {
                if (j + k > N) {
                    dp[i][N*2-(j+k)] += dp[i-1][j] * m_inv;
                } else {
                    dp[i][j+k] += dp[i-1][j] * m_inv;
                }
            }
        }
    }
    for (i=1; i<=K; i++) {
        ans += dp[i][N];
    }
    cout << ans.val() << endl;
    return 0;
}
