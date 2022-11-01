#include <bits/stdc++.h>
using namespace std;
#define MAX_N       105
#define MAX_K       20

/* dpの亜種 */
/* https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_d */
int main (int argc, char *argv[]) {
    int i, j;
    int N;
    int num[MAX_N];
    long long dp[MAX_N][MAX_K+1] = {0};

    cin >> N;
    for (i=0; i<N; i++) {
        cin >> num[i];
    }
    dp[0][num[0]] = 1;
    // dp[i][j] := i番目の数までに合計がjになっている場合の数

    for (i=1; i<N; i++) {
        for (j=0; j<=MAX_K; j++) {
            if (j >= num[i]) {      // 引き算ができることを確認
                dp[i][j-num[i]] += dp[i-1][j];
            }
            if (num[i] + j <= MAX_K) {      // 足し算ができることを確認
                dp[i][j+num[i]] += dp[i-1][j];
            }
        }
    }

    cout << dp[N-1][num[N]] << endl;
    return 0;
}
