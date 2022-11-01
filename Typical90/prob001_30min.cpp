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

bool isDevide(int num, int N, vector<int> A, int K) {
    int i;
    int now = 0;
    int devideNum = 0;
    for (i=1; i<=N+1; i++) {
        if (A[i] - A[now] >= num) {
            now = i;
            devideNum++;
        }
        if (devideNum >= K) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int i, j;
    int N, L, K;
    cin >> N >> L;
    cin >> K;
    K++;
    vector<int>A(N+2);
    for (i=1; i<=N; i++) {
        cin >> A[i];
    }
    A[0] = 0;
    A[N+1] = L;
    int min = 1;
    int max = L;
    int score;
    while (1) {
        if (max - min <= 1) {
            if (isDevide(max, N, A, K)) score = max;
            else score = min;
            break;
        }
        int mid = (min + max) / 2;
        if (isDevide(mid, N, A, K)) {
            min = mid;
        } else {
            max = mid;
        }
    }
    cout << score << endl;
    return 0;
}