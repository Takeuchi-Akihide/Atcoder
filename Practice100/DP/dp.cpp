#include <bits/stdc++.h>
using namespace std;
#define MAX_N       105
#define MAX_W       10005

/* ナップザック問題 */
int main (int argc, char *argv[]) {
    int i, w;

    /* Nの取得 */
    int N, W;
    cin >> N >> W;
    int value[MAX_N], weight[MAX_N];
    for (i=0; i<N; i++) {
        cin >> value[i] >> weight[i];
    }

    int dp[MAX_N][MAX_W];
    for (w=0; w<=W; w++) {
        dp[0][w] = 0;
    }

    for (i=0; i<N; i++) {
        for (w=0; w<=W; w++) {
            if (w >= weight[i]) {
                dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
            } else {
                dp[i+1][w] = dp[i][w];
            }
        }
    }
    cout << dp[N][W] << endl;
}
