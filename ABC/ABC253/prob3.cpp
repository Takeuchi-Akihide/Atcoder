#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define MAX_N   200005
#define MAX_A   1000001

int main(int argc, char *argv[]) {
    int i, j;
    int Q;
    cin >> Q;
    vector<int> ans(Q);
    multiset<int> array;
    int now = 0;
    for (i=0; i<Q; i++) {
        int n, x, c;
        cin >> n;
        if (n == 1) {
            cin >> x;
            array.insert(x);
        } else if (n == 2) {
            cin >> x >> c;
            for (j=0; j<c; j++) {
                if (array.find(x) != array.end()) {
                    array.erase(array.find(x));
                } else {
                    break;
                }
            }
        } else {
            ans[now] = *array.rbegin() - *array.begin();
            now++;
        }
    }
    for (i=0; i<now; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}