#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
#define MAX_N   100005

ll ans = 0;
map<ll, ll> func;

ll calcFrecursive (ll n) {
    if (func[n] != 0) return func[n];
    ll ans = calcFrecursive(n/2) + calcFrecursive(n/3);
    func[n] = ans;
    return ans;
}


int main(void) {
    ll N;
    cin >> N;
    func[0] = 1;
    ll ans = calcFrecursive(N);
    cout << ans << endl;
    return 0;
}