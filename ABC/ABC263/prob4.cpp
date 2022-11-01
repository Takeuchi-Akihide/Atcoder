#include <bits/stdc++.h>
using namespace std;
#define     MAX_N   200005

int main() {
    int i, j, k;
    long long N, L, R;
    long long A[MAX_N];
    long long sum[MAX_N];
    cin >> N >> L >> R;
    for (i=1; i<=N; i++) {
        cin >> A[i];
        sum[i] = sum[i-1] + A[i];
    }
    long long f[MAX_N], g[MAX_N];
    f[0] = 0, g[N] = 0;
    for (i=1; i<=N; i++) {
        // f[k] := A[1], A[2],...,A[k]に対して適当なxを選んで操作を行った時の総和の最小値
        f[i] = min(f[i-1] + A[i], L * i);
    }
    for (i=N-1; i>=0; i--) {
        // g[k] := A[k+1], A[k+2],...,A[N]に対して適当なxを選んで操作を行った時の総和の最小値
        g[i] = min(g[i+1] + A[i+1], R * (N-i));
    }
    long long sumMin = R * N;
    long long tmp;
    for (i=0; i<=N; i++) {
        tmp = f[i] + g[i];
        if (tmp < sumMin) {
            sumMin = tmp;
        }
    }
    cout << sumMin << endl;
    return 0;
}
