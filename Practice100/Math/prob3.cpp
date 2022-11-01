#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define MAX_N   100005

long long checkGCD(long long a, long long b);
long long checkLCM(long long a, long long b);

long long checkLCM(long long a, long long b) {
    return a * b / checkGCD(a, b);
}
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

int main(void) {
    long long N, M;
    int i, j;
    long long a[MAX_N];
    cin >> N >> M;
    for (i=1; i<=N; i++) {
        cin >> a[i];
    }
    // a[i]/2 の最小公倍数を求める
    long long LCM = a[1]/2;
    long long tmp;
    for (i=1; i<N; i++) {
        tmp = checkLCM(a[i+1]/2, LCM);
        LCM = tmp;
    }
    // cout << "LCM: " << LCM << endl;
    for (i=1; i<=N; i++) {
        if ((LCM / (a[i]/2)) % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    int count = 0;
    if (M >= LCM) {
        count = (M - LCM) / (LCM * 2) + 1;
    }
    cout << count << endl;
    return 0;
}
