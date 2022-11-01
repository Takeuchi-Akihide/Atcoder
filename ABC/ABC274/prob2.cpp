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
    int H, W;
    cin >> H >> W;
    vector<int> ans(W, 0);
    int i, j;
    for (i=0; i<H; i++) {
        string buf;
        cin >> buf;
        for (j=0; j<W; j++) {
            if (buf[j] == '#') ans[j]++;
        }
    }
    for (i=0; i<W-1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[W-1] << endl;
    return 0;
}