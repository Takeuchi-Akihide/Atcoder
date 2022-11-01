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
    int d = N / 2;
    int minF = 0x7fffffff;
    while (true) {
        int fuman = 0;
        int isMinus = 0;
        int isPlus = 0;
        d = (d + 1) / 2;
        for (i=0; i<N; i++) {
            if (A[i] > (N - A[i])) {
                isMinus++;
                fuman += (N - A[i]);
            } else if (A[i] != 0) {
                isPlus++;
                fuman += A[i];
            }
        }
        minF = min(fuman, minF);
        if (d == 1) break;
        if (isMinus > isPlus) {
            for (i=0; i<N; i++) {
                A[i] += d;
                if (A[i] >= N) {
                    A[i] -= N;
                }
            }
        } else if (isPlus > isMinus) {
            for (i=0; i<N; i++) {
                A[i] -= d;
                if (A[i] < 0) {
                    A[i] += N;
                }
            }
        } else {
            break;
        }
    }

    cout << minF << endl;
    return 0;
}