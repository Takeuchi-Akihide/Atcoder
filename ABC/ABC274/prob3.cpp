#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
#define MAX_N   100005

int main(void) {
    int i;
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> ans(N*2+1, 0);
    for (i=0; i<N; i++) {
        cin >> A[i];
        ans[i*2+1] = ans[A[i]-1] + 1;
        ans[i*2+2] = ans[A[i]-1] + 1;
    }
    for (i=0; i<N*2+1; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}