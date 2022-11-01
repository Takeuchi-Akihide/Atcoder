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
    int i, j1, j2;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> butou(N, vector<int>(N, 0));
    for (i=0; i<N; i++) {
        butou[i][i] = 1;
    }
    int k;
    for (i=0; i<M; i++) {
        cin >> k;
        vector<int> x(k, 0);
        for (j1=0; j1<k; j1++) {
            cin >> x[j1];
            x[j1]--;
        }
        for (j1=0; j1<k; j1++) {
            for (j2=j1+1; j2<k; j2++) {
                butou[x[j1]][x[j2]] = 1;
                butou[x[j2]][x[j1]] = 1;
            }
        }
    }
    for (i=0; i<N; i++) {
        for (j1=0; j1<N; j1++) {
            if (butou[i][j1] == 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}