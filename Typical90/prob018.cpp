#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;

int main(void) {
    int T, L, X, Y;
    cin >> T;
    cin >> L >> X >> Y;
    int Q;
    cin >> Q;
    vector<double>ans(Q);
    for (int i=0; i<Q; i++) {
        int t;
        cin >> t;
        double y = L/2.0 * (-sin(2*M_PI*t/T));
        double z = L/2.0 * (1 - cos(2*M_PI*t/T));
        ans[i] = atan2(z, pow((pow(Y-y, 2)) + pow(X, 2), 0.5)) * 180/ M_PI;
    }
    for (int i=0; i<Q; i++) {
        cout << fixed << setprecision(12) << ans[i] << endl;
    }
    return 0;
}