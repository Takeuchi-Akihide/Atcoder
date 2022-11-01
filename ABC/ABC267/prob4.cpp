#include <bits/stdc++.h>
using namespace std;
#define MAX_N   2010

long long dp[MAX_N][MAX_N] = {0};

int main(void)
{
    int i, j, k;
    int N, M;
    long long A[MAX_N];
    cin >> N >> M;
    A[0] = 0;
    for (i=1; i<=N; i++) {
        cin >> A[i];
    }
    dp[0][1] = -pow(10, 12);
    for (i=1; i<=N; i++) {
        for (j=1; j<=M; j++) {
            dp[i][j] = -pow(10, 12);
        }
    }
    for (i=1; i<=N; i++) {
        dp[i][1] = max(dp[i-1][1], A[i]);
    }
    for (i=2; i<=N; i++) {
        for (j=2; j<=M; j++) {
            if (j > i) continue;
            dp[i][j] = max(dp[i-1][j-1] + j * A[i], max(dp[i][j], dp[i-1][j]));
        }
    }
    for (i=1; i<=N; i++) {
        cout << i << ": ";
        for (j=1; j<=M; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[N][M] << endl;
    return 0;
}
