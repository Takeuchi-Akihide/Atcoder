#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define MAX_N   100005
#define MAX_A   1000001

int main(int argc, char *argv[]) {
    int i, j;
    ll N, M;
    cin >> N >> M;
    int Q;
    cin >> Q;
    vector<mint> ans(Q);
    mint S;
    for (i=0; i<Q; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll A1 = b - a + 1;
        ll A2 = d - c + 1;
        if (A2 % 2 == 0) {
            S = (mint)A1 * (mint)A2* (mint)((c+d) - 2 * M + (a+b) * M) / 2;
            if (A1 % 2 == 0) {
                ans[i] = S/2;
            } else {
                if (S != 0) {
                    mint dif = (d-c+1) / 2;
                    if ((a + c) % 2 == 0) {
                        ans[i] = (S-dif) / 2;
                    } else {
                        ans[i] = (S+dif) / 2;
                    }
                }
            }
        } else {
            A2 = d - c;
            S = (mint)A1 * (mint)A2* (mint)((c+d-1) - 2 * M + (a+b) * M) / 2;
            if (A1 % 2 == 0) {
                ans[i] = S/2;
                if ((a + d) % 2 == 0) {
                    mint start = (a-1) * M + d;
                    ans[i] += (mint)(start * 2 + M * (b-a-1)) * (mint)(b-a+1) / 4;
                } else {
                    mint start = a * M + d;
                    ans[i] += (mint)(start * 2 + M * (b-a-1)) * (mint)(b-a+1) / 4;
                }
            } else {
                if (S != 0) {
                    mint dif = (d-c) / 2;
                    if ((a + c) % 2 == 0) {
                        ans[i] = (S-dif) / 2;
                    } else {
                        ans[i] = (S+dif) / 2;
                    }
                }
                if ((a + d) % 2 == 0) {
                    mint start = (a-1) * M + d;
                    ans[i] += (mint)(start * 2 + M * (b-a)) * (mint)(b-a+2) / 4;
                } else {
                    mint start = a * M + d;
                    ans[i] += (mint)(start * 2 + M * (b-a-2)) * (mint)(b-a) / 4;
                }
            }
        }
    }
    for (i=0; i<Q; i++) {
        cout << ans[i].val() << endl;
    }
    return 0;
}