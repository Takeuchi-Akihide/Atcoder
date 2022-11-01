#include <bits/stdc++.h>
using namespace std;
long long INF = 998244353;

int main() {
    long long N;
    cin >> N;
    if (N >= 0) {
        cout << (N % INF) << endl;
    } else {
        long long minusN = -N;
        if (minusN % INF) {
            cout << INF - (minusN % INF) << endl;
        } else {
            cout << 0 << endl;
        }
        
    }
    return 0;
}
