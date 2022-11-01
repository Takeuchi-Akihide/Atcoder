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
    vector<string> S(10);
    int a, b, c, d;
    bool isStarti = false;
    bool isEndi = false;
    bool isEndj = false;
    for (i=0; i<10; i++) {
        cin >> S[i];
        for (j=0; j<10; j++) {
            if (isStarti == false) {
                if (S[i][j] == '#') {
                    a = i + 1;
                    c = j + 1;
                    isStarti = true;
                }
            }
            if (isStarti && !isEndj && a == i + 1) {
                if (S[i][j] == '.') {
                    d = j;
                    isEndj = true;
                } else if (j == 9) {
                    d = 10;
                    isEndj = true;
                }
            }
            if (isStarti && !isEndi && c == j + 1) {
                if (S[i][j] == '.') {
                    b = i;
                    isEndi = true;
                } else if (i == 9) {
                    b = 10;
                    isEndi = true;
                }
            }
        }
    }
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    return 0;
}