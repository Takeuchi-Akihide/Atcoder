#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = unsigned long long;
using mint = atcoder::modint998244353;

int main(int argc, char *argv[]) {
    int i, j;
    int N, M, Q;
    cin >> N >> M >> Q;
    for (i=0; i<Q; i++) {
        int num;
        ll x;
        cin >> num;
        switch (num)
        {
        case 1:
            int l, r;
            cin >> l >> r >> x;
            break;
        case 2:
            int i;
            cin >> i >> x;
            break;
        case 1:
            int i, j;
            cin >> i >> j;
            break;
        
        default:
            break;
        }
    }
    cout << sumM1[M].val() << endl;
    return 0;
}