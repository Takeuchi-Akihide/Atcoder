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

string kaiten(string S, int L, int R) {
    string res = S;
    int i;
    for (i=L; i<=R; i++) {
        if (S[R-(i-L)] == 'd') {
            res[i] = 'p';
        } else {
            res[i] = 'd';
        }
    }
    return res;
}

int main(void) {
    int i, j;
    int N;
    string S;
    cin >> N;
    cin >> S;
    int L = -1;
    stack<int> R;
    bool isL = false;
    bool isBeforeD = false;
    for (i=0; i<N; i++) {
        if (isL) {
            if (S[i] == 'd') {
                if (isBeforeD == false) {
                    R.push(i-1);
                }
                isBeforeD = true;
            } else {
                isBeforeD = false;
                if (i == N-1) {
                    R.push(i);
                }
            }
        } else {
            if (S[i] == 'p') {
                isL = true;
                L = i;
                isBeforeD = false;
                R.push(i);
            }
        }
    }
    if (L == -1) {
        cout << S << endl;
        return 0;
    }
    string small = S;
    while (!R.empty()) {
        int R2 = R.top();
        R.pop();
        string S2 = kaiten(S, L, R2);
        if (S2 <= small) {
            small = S2;
        }
    }
    cout << small << endl;
    return 0;
}