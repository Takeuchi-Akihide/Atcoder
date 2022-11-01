#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;

int main(void) {
    int i, j, k;
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<mint>> dp(7, vector<mint>(N+1, 0));
    for (i=0; i<N; i++) {
        for (j=0; j<7; j++) {
            dp[j][i+1] = dp[j][i];
        }
        if (S[i] == 'a')        dp[0][i+1] += 1;
        else if (S[i] == 't')   dp[1][i+1] += dp[0][i+1];
        else if (S[i] == 'c')   dp[2][i+1] += dp[1][i+1];
        else if (S[i] == 'o')   dp[3][i+1] += dp[2][i+1];
        else if (S[i] == 'd')   dp[4][i+1] += dp[3][i+1];
        else if (S[i] == 'e')   dp[5][i+1] += dp[4][i+1];
        else if (S[i] == 'r')   dp[6][i+1] += dp[5][i+1];
    }
    cout << dp[6][N].val() << endl;
    return 0;
}