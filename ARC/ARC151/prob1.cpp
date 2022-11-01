#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define MAX_N   200005

// char ans[MAX_N] = "";

int main(void) {
    int N;
    string S, T;
    cin >> N;
    cin >> S;
    cin >> T;
    int dif = 0;
    for (int i=0; i<N; i++) {
        if (S[i] != T[i]) dif++;
    }
    if (dif % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    int max_dif = dif / 2;
    int s_dif = 0, t_dif = 0;
    for (int i=0; i<N; i++) {
        // cout << "i: " << i << ", S: " << S[i] << ", T: " << T[i] << endl;
        if (S[i] != T[i]) {
            if (S[i] == '0') {
                if (t_dif < max_dif) {
                    t_dif++;
                    cout << 0;
                    // cout << "t_dif: " << t_dif << ", " << 0 << endl;
                } else {
                    s_dif++;
                    cout << 1;
                    // cout << "s_dif: " << s_dif << ", " << 1 << endl;
                }
            } else {
                if (s_dif < max_dif) {
                    s_dif++;
                    cout << 0;
                    // cout << "s_dif: " << s_dif << ", " << 0 << endl;
                } else {
                    t_dif++;
                    cout << 1;
                    // cout << "t_dif: " << t_dif << ", " << 1 << endl;
                }
            }
        } else {
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}