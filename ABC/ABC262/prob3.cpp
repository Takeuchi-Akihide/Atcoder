#include <bits/stdc++.h>
using namespace std;
#define     MAX_N   100
#define     MOD     998244353

int main() {
    int i, j, k;
    int N;
    cin >> N;
    int a[MAX_N];
    for (i=1; i<=N; i++) {
        cin >> a[i];
    }
    long long count = 0;
    long long sameCount = 0;
    for (i=1; i<=N; i++) {
        if (a[i] == i) {
            sameCount++;
        }
        else if (a[i] > i) {
            if (a[a[i]] == i) {
                count++;
            }
        }
    }
    count += (sameCount * (sameCount-1) / 2);
    cout << count << endl;
    return 0;
}
