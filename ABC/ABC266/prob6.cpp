#include <bits/stdc++.h>
using namespace std;
#define     MAX_N   200005

int main() {
    int i, j, k;
    int N, K;
    cin >> N >> K;
    vector<int> p[MAX_N];
    for (i=1; i<=N; i++) {
        cin >> p[i];
    }

    // 削除のみのパターン
    vector<int> p_1[MAX_N];
    int K_1 = K, N_1 = N;
    int min_1 = MAX_N;
    int min_i;
    for (i=1; i<=K; i++) {
        if (min_1 > p_1[i]) {
            min_1 = p_1[i];
            min_i = i;
        }
    }
    for (i=1; i<min_i; i++) {
        p_1[i].
    }
    while (K_1 > 0) {

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
