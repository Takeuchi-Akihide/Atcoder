#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define MAX_N   100005
#define MAX_A   1000001
#define INF     1 << 30

int main(void) {
    int i, j;
    int T;
    cin >> T;
    vector<ll> ans(T, INF);
    for (i=0; i<T; i++) {
        int A, B;
        cin >> A >> B;
        if (A > B) {
            ans[i] = A - B;
        } else if (B % A == 0) {
            ans[i] = 0;
        } else {
            ll x = 0;
            while(true) {
                ll n = B/A;
                if (n < A) {
                    for (j=1; j<=n; j++) {
                        ll k = B - j * A;
                        if (k % j == 0) {
                            ans[i] = min(k/j, ans[i]);
                        } else {
                            ans[i] = min(k/j+1 + j*(k/j+1) - k, ans[i]);
                        }
                    }
                } else {
                    for (j=0; j<A; j++) {
                        ll y = (B/(A+j) + 1) * (A+j) - B;
                        ans[i] = min(ans[i], j + y);
                        if (j >= ans[i]) break;
                    }
                }
            }
        }
    }
    for (i=0; i<T; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}