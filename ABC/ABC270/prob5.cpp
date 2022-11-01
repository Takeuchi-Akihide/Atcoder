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

int main(void) {
    ll N, K;
    int i, j;
    cin >> N >> K;
    vector<ll> A(N);
    map<ll, int> count;
    for (i=0; i<N; i++) {
        cin >> A[i];
    }
    ll Min = 0;
    ll Max = pow(10, 12) + 100;
    ll mid;
    while (Max - Min > 1) {
        mid = (Max + Min) / 2;
        ll ate = 0;
        for (i=0; i<N; i++) {
            ate += min(mid, A[i]);
        }
        if (ate <= K){
            Min = mid;
        } else {
            Max = mid;
        }
    }
    ll remain = K;
    for (i=0; i<N; i++) {
        ll d = min(Min, A[i]);
        A[i] -= d;
        remain -= d;
    }
    for (i=0; i<N; i++) {
        if (remain > 0) {
            if (A[i]) {
                cout << A[i] - 1;
                remain--;
            } else {
                cout << A[i];
            }
        } else {
            cout << A[i];
        }
        if (i != N-1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}