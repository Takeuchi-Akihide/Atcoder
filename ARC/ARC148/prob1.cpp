#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define MAX_N   100005

long long checkGCD(long long a, long long b) {
    long long r;
    
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
    int i;
    int N;
    cin >> N;
    vector<ll> A(N, 0);
    for (i=0; i<N; i++) {
        cin >> A[i];
    }
    int j = 1;
    bool isSame = false;
    while (A[j-1] == A[j]) {
        j++;
        if (j == N+1) {
            isSame = true;
        }
    }
    if (isSame) {
        cout << 1 << endl;
        return 0;
    }
    ll gcd = llabs(A[j-1] - A[j]);
    for (i=j+1; i<N; i++) {
        if (A[i-1] == A[i]) {
            continue;
        }
        gcd = checkGCD(llabs(A[i-1] - A[i]), gcd);
    }
    if (gcd == 1) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}