#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = unsigned long long;
using mint = atcoder::modint998244353;

int main(int argc, char *argv[]) {
    int i, j;
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<mint>> dp(M+1, vector<mint>(N+1, 0));
    vector<mint> sumM1(M+1, 0);   // sumM[i]:=dp[0][j]からdp[i][j]の和
    vector<mint> sumM2(M+1, 0);   // swapして回していく
    for (i=1; i<=M; i++) {
        dp[i][1] = 1;
        sumM1[i] = sumM1[i-1] + dp[i][1];
    }
    for (i=2; i<=N; i++) {
        for (j=0; j<=M; j++) {
            sumM2[j] = 0;
        }
        for (j=1; j<=M; j++) {
            if (K == 0) {
                dp[j][i] = sumM1[M];
                sumM2[j] = sumM2[j-1] + dp[j][i];
            } else {
                int minM = max(j-K, 0);
                int maxM = min(j+K, M+1) - 1;
                dp[j][i] = sumM1[minM] + (sumM1[M] - sumM1[maxM]);
                sumM2[j] = sumM2[j-1] + dp[j][i];
            }
        }
        swap(sumM1, sumM2);
    }
    // for (i=1; i<=M; i++) {
    //     cout << "[" << i << "]: ";
    //     for (j=1; j<=N; j++) {
    //         cout << dp[i][j].val() << " ";
    //     }
    //     cout << endl;
    // }
    cout << sumM1[M].val() << endl;
    return 0;
}