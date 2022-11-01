#include <bits/stdc++.h>
using namespace std;
#define MAX_N       30


int main(void) {
    long long A, B, K;
    cin >> A >> B >> K;
    if (A >= K) {
        cout << A - K << " " << B << endl;
    } else if (A + B >= K) {
        cout << "0 " << A + B - K << endl;
    } else {
        cout << "0 0" << endl;
    }
    return 0;
}
