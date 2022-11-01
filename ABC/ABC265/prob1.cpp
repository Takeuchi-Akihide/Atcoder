#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y, N;
    cin >> X >> Y >> N;
    if (Y >= X * 3) {
        cout << X * N << endl;
    } else {
        cout << Y * (N/3) + X * (N%3) << endl;
    }
    return 0;
}
