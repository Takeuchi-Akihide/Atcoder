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
    int A;
    int odd[2] = {-1, -1}, even[2] = {-1, -1};
    for (i=0; i<N; i++) {
        cin >> A;
        if (A % 2 == 0) {
            if (A > even[0]) {
                even[1] = even[0];
                even[0] = A;
            } else if (A > even[1]){
                even[1] = A;
            }
        } else {
            if (A > odd[0]) {
                odd[1] = odd[0];
                odd[0] = A;
            } else if (A > odd[1]){
                odd[1] = A;
            }
        }
    }
    int ans = -1;
    if (even[0] != -1 && even[1] != -1) {
        ans = max(ans, even[0] + even[1]);
    }
    if (odd[0] != -1 && odd[1] != -1) {
        ans = max(ans, odd[0] + odd[1]);
    }
    cout << ans << endl;

    return 0;
}