#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int x[4], y[4];
    int i, j;
    for (i=0; i<4; i++) {
        cin >> x[i] >> y[i];
    }
    // ACの式を求める
    int bunboAC = x[2] - x[0];
    int xAC = y[2] - y[0];
    int bunshiAC = -(x[2] * y[0] + y[2] * x[0]);
    // BDの式を求める
    int bunboBD = x[3] - x[1];
    int xBD = y[3] - y[1];
    int bunshiBD = -(x[3] * y[1] + y[3] * x[1]);
    bool isB = ((xAC * x[1] + bunshiAC) > (y[1] * bunboAC));
    bool isD = ((xAC * x[3] + bunshiAC) > (y[3] * bunboAC));
    bool isA = ((xBD * x[0] + bunshiBD) > (y[0] * bunboBD));
    bool isC = ((xBD * x[2] + bunshiBD) > (y[2] * bunboBD));
    cout << isA << isB << isC << isD << endl;
    cout << xAC * x[1] + bunshiAC << ", " << y[1] * bunboAC << endl;
    cout << xAC * x[3] + bunshiAC << ", " << y[3] * bunboAC << endl;
    cout << xBD * x[0] + bunshiBD << ", " << y[0] * bunboBD << endl;
    cout << xBD * x[2] + bunshiBD << ", " << y[2] * bunboBD << endl;
    if ((isB + isD == 1) && (isA + isC == 1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
