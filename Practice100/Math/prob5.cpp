#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;
#define MAX_N   200005

int main(void) {
    int i, j;
    int M;
    cin >> M;
    ll count = 0;
    ll ans = 0;
    for (i=0; i<M; i++) {
        int c;
        ll d;
        cin >> c >> d;
        ans += d;
        count += (c * d);
        ans += count / 9;
        count %= 9;
    }
    if (count == 0) ans--;
    cout << ans-1 << endl;
    return 0;
}
