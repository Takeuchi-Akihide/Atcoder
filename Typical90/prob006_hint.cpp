#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;
#define MAX_N   100005
#define MAX_A   1000001
#define INF     1000001

int main(void) {
    int i, j, k;
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    vector<vector<int>> c(N+1, vector<int>(26, INF));
    for (i=N-1; i>=0; i--) {
        char ch = S[i];
        for (j=0; j<26; j++) {
            c[i][j] = c[i+1][j];
        }
        c[i][ch-'a'] = i;
    }

    string ans = "";
    int ik = 0;
    int in = 0;
    while(true) {
        for (j=0; j<26; j++) {
            if (N-c[in][j] >= K-ik) {
                ans += ('a' + j);
                in = c[in][j] + 1;
                ik++;
                break;
            }
        }
        if (ik == K) break;
    }
    cout << ans << endl;
    return 0;
}