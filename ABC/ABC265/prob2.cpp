#include <bits/stdc++.h>
#define MAX_N   100005
using namespace std;

int main() {
    int i;
    long long N, M, T;
    long long A[MAX_N];
    long long Plus[MAX_N];
    long long x, y;
    cin >> N >> M >> T;
    for (i=1; i<=N-1; i++) {
        cin >> A[i];
    }
    for (i=1; i<=M; i++) {
        cin >> x >> y;
        Plus[x] = y;
    }
    for (i=1; i<=N-1; i++) {
        T += Plus[i];
        if (T <= A[i]) {
            cout << "No" << endl;
            return 0;
        }
        T -= A[i];
    }
    cout << "Yes" << endl;
    return 0;
}
