#include <bits/stdc++.h>
using namespace std;
long long INF = 998244353;

int main() {
    string s;
    cin >> s;
    int i, j, k;
    bool isSplit = false;

    if (s[0] == '1') {
        cout << "No" << endl;
        return 0;
    }
    int line[7] = {0};
    if (s[6] == '1') line[0] = 1;
    if (s[3] == '1') line[1] = 1;
    if (s[1] == '1' || s[7] == '1') line[2] = 1;
    if (s[4] == '1') line[3] = 1;
    if (s[2] == '1' || s[8] == '1') line[4] = 1;
    if (s[5] == '1') line[5] = 1;
    if (s[9] == '1') line[6] = 1;
    for (i=0; i<5; i++) {
        for (j=i+2; j<7; j++) {
            if (line[i] && line[j]) {
                for (k=i+1; k<j; k++) {
                    if (line[k] == 0) isSplit = true;
                    break;
                }
            }
        }
    }
    if (isSplit) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
