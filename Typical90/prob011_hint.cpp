#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;
typedef pair<int, int> P;   // class, point
#define MAX_N   5005

// bool canFinishTable[MAX_N] = {true};

// ll canFinish(ll i, vector<vector<int>> DCS, int N) {
//     int now = 0;
//     int tmp = 0;
//     ll ret = 0;
//     while (tmp < N) {
//         if (i & (1 << tmp)) {
//             now += DCS[tmp][1];
//             if (now > DCS[tmp][0]) {
//                 return -1;
//             }
//             ret += DCS[tmp][2];
//         }
//         tmp++;
//     }
//     return ret;
// }

ll dp[MAX_N][MAX_N];

int main(void) {
    ll i, j;
    int N;
    cin >> N;
    vector<vector<int>> DCS(N, vector<int>(3));
    for (i=0; i<N; i++) {
        cin >> DCS[i][0] >> DCS[i][1] >> DCS[i][2];
    }
    sort(DCS.begin(),DCS.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[0] < beta[0];});
    ll ans = 0;
    for (i=0; i<N; i++) {
        for (j=0; j<=5000; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (j+DCS[i][1] <= DCS[i][0]) {
                dp[i+1][j+DCS[i][1]] = max(dp[i+1][j+DCS[i][1]], dp[i][j] + DCS[i][2]);
            }
        }
    }
    for (i=0; i<=5000; i++) {
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}