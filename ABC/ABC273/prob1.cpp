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
    int N;
    int ans = 1;
    cin >> N;
    if (N == 0) {
        cout << ans << endl;
        return 0;
    }
    for (int i=1; i<=N; i++) {
        ans *= i;
    }
    cout << ans << endl;
    return 0;
}