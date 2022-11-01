#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
using namespace std;
using namespace atcoder;
using mint = atcoder::modint1000000007;
#define MAX_N   100005

int main(void) {
    int i, j;
    int N;
    cin >> N;
    vector<int> A(N);
    for (i=0; i<N; i++) {
        cin >> A[i];
    }
    int count[3] = {0};
    mint ans = 1;
    for (i=0; i<N; i++) {
        int match = 0;
        int num = 0;
        for (j=0; j<3; j++) {
            if (A[i] == count[j]) {
                match++;
                num = j;
            }
        }
        ans *= match;
        if (ans == 0) break;
        count[num]++;
    }
    cout << ans.val() << endl;
    return 0;
}
