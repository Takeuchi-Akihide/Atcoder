#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
#define MAX_N   100005

vector<vector<int>> dp_x(1005, vector<int>(20021, 0));   // -10010~10010, 0 = 10011
vector<vector<int>> dp_y(1005, vector<int>(20021, 0));   // -10010~10010, 0 = 10011
#define offset   10011

int main(void) {
    int N, x, y;
    cin >> N >> x >> y;
    int i, j;
    vector<int> A(N);
    for (i=0; i<N; i++) {
        cin >> A[i];
    }
    dp_x[1][A[0]+offset] = 1;
    dp_y[1][offset] = 1;
    for (i=2; i<=N; i++) {
        if (i % 2 == 1) {
            for (j=10; j<20011; j++) {
                if (dp_x[i-1][j] == 1) {
                    dp_x[i][j-A[i-1]] = 1;
                    dp_x[i][j+A[i-1]] = 1;
                }
                dp_y[i][j] = dp_y[i-1][j];
            }
        } else {
            for (j=10; j<20011; j++) {
                if (dp_y[i-1][j] == 1) {
                    dp_y[i][j-A[i-1]] = 1;
                    dp_y[i][j+A[i-1]] = 1;
                }
                dp_x[i][j] = dp_x[i-1][j];
            }
        }
    }
    // cout << "dp_x" << endl;
    // for (i=1; i<=N; i++) {
    //     cout << "[" << i << "]: ";
    //     for (j=-10; j<=10; j++) {
    //         cout << dp_x[i][j+offset] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "dp_y" << endl;
    // for (i=1; i<=N; i++) {
    //     cout << "[" << i << "]: ";
    //     for (j=-10; j<=10; j++) {
    //         cout << dp_y[i][j+offset] << " ";
    //     }
    //     cout << endl;
    // }
    if (dp_x[N][x+offset] && dp_y[N][y+offset]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}