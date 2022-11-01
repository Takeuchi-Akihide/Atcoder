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

void calc_recursion(int result, int stack, string ans) {
    if (result == 0) {
        cout << ans << endl;
        return;
    }
    if (result > stack) {
        calc_recursion(result-1, stack+1, ans + "(");
        if (stack > 0) {
            calc_recursion(result-1, stack-1, ans + ")");
        }
    } else {
        calc_recursion(result-1, stack-1, ans + ")");
    }

}

int main(void) {
    int N;
    cin >> N;
    if (N % 2 == 1) return 0;
    calc_recursion(N, 0, "");
    return 0;
}