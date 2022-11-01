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
    string S, T;
    bool isTrue = true;
    cin >> S;
    cin >> T;
    if (S.size() > T.size()) {
        cout << "No" << endl;
        return 0;
    }
    for (i=0; i<S.size(); i++) {
        if (S[i] != T[i]) {
            isTrue = false;
            break;
        }
    }
    if (isTrue) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}