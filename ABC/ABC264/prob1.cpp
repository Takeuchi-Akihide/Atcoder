#include <bits/stdc++.h>
using namespace std;

int main() {
    int i;
    string s = "atcoder";
    int L, R;
    cin >> L >> R;
    for (i=L-1; i<R; i++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}
