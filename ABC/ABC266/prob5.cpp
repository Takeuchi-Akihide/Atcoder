#include <bits/stdc++.h>
using namespace std;
#define MAX_N       200005
#define MOD         998244353

int main() {
    int i, j;
    int N;
    cin >> N;
    float kitaichi[100];
    kitaichi[N] = 3.5;
    for (i=N-1; i>0; i--) {
        double tmp = 0;
        for (j=1; j<=6; j++) {
            if ((float)j > kitaichi[i+1]) tmp += j;
            else tmp += kitaichi[i+1];
        }
        kitaichi[i] = tmp / 6;
    }
    cout << kitaichi[1] << endl;
    return 0;
}
