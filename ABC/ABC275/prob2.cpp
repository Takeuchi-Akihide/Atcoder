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
    mint A, B, C, D, E, F;
    ll tmp[6];
    for (int i=0; i<6; i++) {
        cin >> tmp[i];
    }
    A = tmp[0] % 998244353;
    B = tmp[1] % 998244353;
    C = tmp[2] % 998244353;
    D = tmp[3] % 998244353;
    E = tmp[4] % 998244353;
    F = tmp[5] % 998244353;
    mint ans = A * B * C - D * E * F;
    cout << ans.val() << endl;
    return 0;
}