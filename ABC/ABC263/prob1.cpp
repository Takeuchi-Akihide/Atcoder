#include <bits/stdc++.h>
using namespace std;

int main() {
    int i;
    int A[5];
    cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4];
    int box[15] = {0};
    for (i=0; i<5; i++) {
        box[A[i]]++;
    }
    int flag2 = 0, flag3 = 0;
    for (i=1; i<=13; i++) {
        if (box[i] == 2) {
            flag2 = 1;
        } else if (box[i] == 3) {
            flag3 = 1;
        }
    }
    if (flag2 && flag3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
