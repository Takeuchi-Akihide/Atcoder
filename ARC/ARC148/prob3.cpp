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

vector<int> tree[MAX_N];
vector<int> isOmote(MAX_N, false);

ll calcRecursive(bool oyaisOmote, int num) {
    int i;
    ll res = 0;
    for (i=0; i<tree[num].size(); i++) {
        int next = tree[num][i];
        res += calcRecursive(isOmote[num], next);
    }
    if (oyaisOmote != isOmote[num]) {
        return res + 1;
    } else {
        return res;
    }
}

int main(void) {
    int N, Q;
    int i, j;
    cin >> N >> Q;
    vector<ll> ans(Q, -1);
    int tmp;
    for (i=1; i<N; i++) {
        cin >> tmp;
        tmp--;
        tree[tmp].push_back(i);
    }
    for (i=0; i<Q; i++) {
        for (j=0; j<N; j++) {
            isOmote[j] = false;
        }
        int M;
        cin >> M;
        int tmp;
        for (j=0; j<M; j++) {
            cin >> tmp;
            tmp--;
            isOmote[tmp] = true;
        }
        ans[i] = calcRecursive(false, 0);
    }
    for (i=0; i<Q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}