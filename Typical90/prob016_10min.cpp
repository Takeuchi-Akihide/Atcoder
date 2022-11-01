#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;
#define MAX_N 9999

int main(void) {
    int N;
    cin >> N;
    int A, B, C;
    cin >> A >> B >> C;
    int ia, ib;
    int ans = MAX_N;
    for (ia=0; ia<=MAX_N; ia++) {
        if (ia * A > N) break;
        for (ib=0; ib<=MAX_N-ia; ib++) {
            if (ia*A + ib*B > N) break;
            if ((N - (ia*A + ib*B)) % C == 0) {
                int tmp = ia + ib + (N - (ia*A + ib*B)) / C;
                ans = min(ans, tmp);
            }
        }
    }

    cout << ans << endl;
    return 0;
}