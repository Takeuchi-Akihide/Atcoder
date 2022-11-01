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
    int A;
    int N;
    int ans = 0;
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A;
        ans += A;
    }
    cout << ans << endl;
    return 0;
}