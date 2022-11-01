#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;

int main(void) {
    int i;
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for (i=0; i<N; i++) {
        cin >> A[i];
    }
    for (i=0; i<N; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll ans = 0;
    for (i=0; i<N; i++) {
        ans += llabs(A[i] - B[i]);
    }
    cout << ans << endl;
    return 0;
}