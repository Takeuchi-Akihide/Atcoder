#include <bits/stdc++.h>
using namespace std;
#define MAX_N       200005
#define MOD         998244353

int main() {
    int i, j;
    int N;
    int A[MAX_N];
    long long kitaichi[MAX_N] = {0};
    cin >> N;
    kitaichi[N] = 1;
    for (i=1, i<=N-1; i++) {
        cin >> A[i];
    }
    for (i=N-1; i>=1; i--) {
        if (i + A[i] > N) {
            long long count = 0;
            for (j=1; j<=N-i; j++) {
                count += kitaichi[i+j];
            }
            count += (i + A[i] - N);
            kitaichi[i] = count / (A[i]+1);
        }
    }
    cout << kitaichi[1] << endl;
    return 0;
}
