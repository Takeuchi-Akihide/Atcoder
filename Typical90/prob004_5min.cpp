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
    int i, j;
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (i=0; i<H; i++) {
        for (j=0; j<W; j++) {
            cin >> A[i][j];
        }
    }
    vector<int> sumRow(H, 0);
    vector<int> sumCol(W, 0);
    for (i=0; i<H; i++) {
        for(j=0; j<W; j++) {
            sumRow[i] += A[i][j];
        }
    }
    for (j=0; j<W; j++) {
        for(i=0; i<H; i++) {
            sumCol[j] += A[i][j];
        }
    }
    for (i=0; i<H; i++) {
        for(j=0; j<W; j++) {
            int num = sumRow[i] + sumCol[j] - A[i][j];
            cout << num;
            if (j != W-1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}