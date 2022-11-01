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
    int N;
    cin >> N;
    vector<int> A(N);
    int tmp;
    for (i=0; i<N; i++) {
        cin >> tmp;
        A[i] = i - tmp;
        if (A[i] < 0) {
            A[i] += N;
        }
        if (A[i] >= N) {
            A[i] -= N;
        }
    }
    int count = 0;
    vector<int> res(N, 0);
    for (i=0; i<N; i++) {
        res[A[i]]++;
    }
    for (i=0; i<N; i++) {
        int tmp;
        if (i == 0) {
            tmp = res[N-1] + res[0] + res[1];
        } else if (i == N-1) {
            tmp = res[N-2] + res[N-1] + res[0];
        } else {
            tmp = res[i-1] + res[i] + res[i+1];
        }
        if (tmp > count) count = tmp;
    }
    cout << count << endl;
    return 0;
}