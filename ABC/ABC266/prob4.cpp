#include <bits/stdc++.h>
using namespace std;
#define MAX_N   100005

long long dp[MAX_N][5];
int main(void)
{
    int i, j;
    int N;
    int A, X, T;
    cin >> N;
    for (i=1; i<=N; i++) {
        cin >> T >> X >> A;
        if (T >= X) {
            dp[T][X] = A;
        }
    }
    for (i=0; i<5; i++) {
        dp[0][i] = 0;
    }
    for (i=1; i<=MAX_N; i++) {
        for (j=0; j<5; j++) {
            if (j == 0) {
                if (dp[i-1][j] > dp[i-1][j+1]) dp[i][j] += dp[i-1][j];
                else dp[i][j] += dp[i-1][j+1];
            } else if (j == 4) {
                if (dp[i-1][j] > dp[i-1][j-1]) dp[i][j] += dp[i-1][j];
                else dp[i][j] += dp[i-1][j-1];
            } else {
                if ((dp[i-1][j] >= dp[i-1][j-1]) && (dp[i-1][j] >= dp[i-1][j+1])) dp[i][j] += dp[i-1][j];
                else if ((dp[i-1][j-1] >= dp[i-1][j+1]) && (dp[i-1][j-1] >= dp[i-1][j])) dp[i][j] += dp[i-1][j-1];
                else dp[i][j] += dp[i-1][j+1];
            }
        }
    }
    long long max = 0;
    for (i=0; i<5; i++) {
        if (dp[MAX_N][i] > max) {
            max = dp[MAX_N][i];
        }
    }
    cout << max << endl;
    return 0;
}
