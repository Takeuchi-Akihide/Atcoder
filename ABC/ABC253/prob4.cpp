#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = unsigned long long;
using mint = atcoder::modint998244353;
#define MAX_N   200005
#define MAX_A   1000001

ll checkGCD(ll a, ll b) {
    ll r;
    
    /* 自然数 a > b を確認・入替 */
    if(a<b){
        swap(a, b);
    }
    
    /* ユークリッドの互除法 */
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main(int argc, char *argv[]) {
    ll N, A, B;
    cin >> N >> A >> B;

    // 総和
    ll sum;
    sum = N * (N + 1) / 2;

    /* Aの倍数の総和を算出 */
    ll max_A, max_B, max_AB;
    ll sum_A, sum_B, sum_AB;
    max_A = N/A;
    sum_A = max_A * (max_A + 1) / 2 * A;
    
    /* Bの倍数の総和を算出 */
    max_B = N/B;
    sum_B = max_B * (max_B + 1) / 2 * B;

    /* AとBの最小公倍数を算出 */
    ll AandB;
    AandB = A / checkGCD(A, B) * B;
    max_AB = N / AandB;
    sum_AB = max_AB * (max_AB + 1) / 2 * AandB;
    ll result;
    result = sum - (sum_A + sum_B - sum_AB);
    cout << result << endl;
    return 0;
}