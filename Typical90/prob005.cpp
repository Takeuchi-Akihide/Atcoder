#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;
#define MAX_N   100005
#define MAX_A   1000001

int main(void) {
    int i, j;
    ll N;
    int B, K;
    cin >> N >> B >> K;
    vector<int> c(10, 0);
    int tmp;
    for (i=0; i<K; i++) {
        cin >> tmp;
        c[tmp] = 1;
    }
    return 0;
}