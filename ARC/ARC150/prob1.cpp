#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define MAX_N   100005

int main(void) {
    string S;
    int T;
    cin >> T;
    vector<bool> ans(T, false);
    for (int i=0; i<T; i++) {
        int N, K;
        cin >> N >> K;
        cin >> S;
        // 最初と最後の1の場所を探す
        int first1 = -1;
        int last1 = -1;
        for (int j=0; j<N; j++) {
            if (S[j] == '1') {
                if (first1 == -1) {
                    first1 = j;
                }
                last1 = j;
            }
        }
        if (last1 - first1 + 1 > K) {
            continue;
        }
        bool isAns = true;
        if (first1 == -1) {
            int count = 0;
            int case1 = 0;
            for (int j=0; j<N; j++) {
                if (S[j] == '?') {
                    count++;
                    if (count >= K) {
                        case1++;
                    }
                    if (case1 >= 2) {
                        isAns = false;
                        break;
                    }
                } else {
                    count = 0;
                }
            }
            if (case1 != 1) isAns = false;
            // cout << "[" << i << "] count: " << count << endl;
        } else {
            int first_ = 0;
            int last_ = N-1;
            for (int j=first1-1; j>=0; j--) {
                if (S[j] == '0') {
                    first_ = j + 1;
                    break;
                }
            }
            for (int j=last1+1; j<N; j++) {
                if (S[j] == '0') {
                    last_ = j - 1;
                    break;
                }
            }
            // cout << "[" << i << "] " << first1 << ", " << last1 << ", " << first_ << ", " << last_ << ", " << endl;
            for (int j=first1+1; j<last1; j++) {
                if (S[j] == '0') {
                    isAns = false;
                    break;
                }
            }
            if (first1 == first_ || last1 == last_) {
                if (last_ - first_ + 1 < K) isAns = false;
            } else {
                if (!(last1 - first1 + 1 == K) && !(last_ - first_ + 1 == K)) {
                    isAns = false;
                }
            }
        }
        ans[i] = isAns;
    }
    for (int i=0; i<T; i++) {
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}