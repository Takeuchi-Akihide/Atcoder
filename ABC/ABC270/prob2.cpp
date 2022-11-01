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

int main(int argc, char *argv[]) {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int ans;
    if (X > 0) {
        if (X > Y && Y > 0) {
            if (Z < Y) {
                ans = abs(Z) + abs(X - Z);
            } else {
                ans = -1;
            }
        } else {
            ans = abs(X);
        }
    } else {
        if (X < Y && Y < 0) {
            if (Z > Y) {
                ans = abs(Z) + abs(X - Z);
            } else {
                ans = -1;
            }
        } else {
            ans = abs(X);
        }
    }
    cout << ans << endl;
    return 0;
}