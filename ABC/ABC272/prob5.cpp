#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define INF (1 << 30)

int main(void) {
    int i, j;
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> ans(M, 0);
    for (i=0; i<N; i++) {
        cin >> A[i];
    }
    for (i=1; i<=M; i++) {
        vector<int> B(N, 0);
        for (j=0; j<N/M; j++) {
            int tmp = A[j] + (j+1) * M;
            if (tmp >= 0 && tmp < N) {
                B[tmp] = 1;
            }
        }
        for (j=0; j<=N/M; j++) {
            if (B[j] == 0) {
                ans[i] = j;
                break;
            }
        }
        
    }
    for (i=1; i<=M; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}