#include <bits/stdc++.h>
using namespace std;
#define MAX_N       200005
#define MOD         998244353

int main() {
    int i, j;
    int N, M, E;
    int U[MAX_N], V[MAX_N];
    int Q;
    vector<int> map[MAX_N];
    cin >> N >> M >> E;
    for (i=0; i<E; i++) {
        cin >> U[i] >> V[i];
        map[U].push_back(E);
        map[E].push_back(U);
    }
    
    cin >> Q;


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
