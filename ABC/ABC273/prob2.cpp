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
    ll X;
    int K;
    cin >> X >> K;
    ll tmpX = X;
    for (int i=0; i<K; i++) {
        ll tmp = tmpX / pow(10, i);
        if (tmp % 10 >= 5) {
            tmp = tmp/10 + 1;
        } else {
            tmp = tmp/10;
        }
        tmpX = tmp * pow(10, i+1);
    }
    cout << tmpX << endl;
    return 0;
}