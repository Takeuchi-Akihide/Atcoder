#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
using namespace std;
using namespace atcoder;
using ll = long long;
#define MAX_N   100005

int main(void) {
    int i, j;
    int N;
    cin >> N;
    int k = 2, sumK = 0;
    bool isTrue = false;
    while(sumK <= N) {
        sumK = k * (k - 1) / 2;
        if (sumK == N) {
            isTrue = true;
            break;
        }
        k++;
    }
    if (isTrue == false) {
        cout << "No" << endl;
        return 0;
    }
    int max = 0;
    cout << "Yes" << endl;
    vector<vector<int>> S(k, vector<int>(k-1));
    cout << k << endl;
    for (i=0; i<k; i++) {
        cout << k-1 << " ";
        for (j=0; j<i; j++) {
            S[i][j] = S[j][i-1];
            cout << S[i][j];
            if (j != k-2) {
                cout << " ";
            }
        }
        for (j=i; j<k-1; j++) {
            S[i][j] = ++max;
            cout << S[i][j];
            if (j != k-2) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
