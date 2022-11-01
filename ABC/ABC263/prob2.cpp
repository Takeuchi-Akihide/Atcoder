#include <bits/stdc++.h>
using namespace std;
#define     MAX_N   55

int main() {
    int i, j, k;
    int N;
    int count = 0;
    int P[MAX_N];
    cin >> N;
    for (i=2; i<=N; i++) {
        cin >> P[i];
    }
    int now = N;
    while (now != 1) {
        now = P[now];
        count++;
    }
    cout << count << endl;
    return 0;
}
