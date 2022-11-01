#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;

int main(void) {
    ll i, j;
    ll N;
    cin >> N;
    ll num = 0;
    vector<ll> A(20, 0);
    for (i=0; i<=60; i++) {
        if ((N >> i) & 0x01) {
            A[num] = i;
            num++;
        }
    }
    for (i=0; i<powl(2,num); i++) {
        ll ans = 0;
        for (j=0; j<num; j++) {
            if ((i >> j) & 0x01) {
                ans += powl(2, A[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}