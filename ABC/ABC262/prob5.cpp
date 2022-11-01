#include <bits/stdc++.h>
using namespace std;

bool isKaibun(string S, int N) {
    if (N == 1) {
        return true;
    }
    if (N == 2) {
        if (S[0] == S[1]) {
            return true;
        } else {
            return false;
        }
    }
    if (N == 3) {
        if (S[0] == 'B' || S[2] == 'A') {
            return true;
        } else {
            return false;
        }
    }
    if (S[0] == S[N-1]){
        return true;
    } else if (S[0] == 'B' && S[N-1] == 'A') {
        S[1] = 'B';
        return true;
    }
    return false;
}

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    bool isTrue = false;
    while (isKaibun(S, N)) {
        N -= 2;
        if (N <= 0) {
            isTrue = true;
            break;
        } 
        S = S.substr(1, N);
    }
    if (isTrue) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
