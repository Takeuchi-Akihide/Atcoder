#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;
#define MAX_N   100005
#define MAX_A   1000001

int binarySearch(int x, vector<int> A, int N) {
    int minX = 0;
    int maxX = N-1;
    int mid;
    while(maxX - minX > 1) {
        mid = (maxX + minX) / 2;
        if (A[mid] > x) {
            maxX = mid;
        } else if (A[mid] < x) {
            minX = mid;
        } else {
            return 0;
        }
        // if (maxX - minX <= 1) break;
    }
    return (min(abs(A[maxX]-x), abs(A[minX]-x)));
}

int main(void) {
    int i, j, k;
    int N, Q;
    cin >> N;
    vector<int> A(N);
    for (i=0; i<N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    cin >> Q;
    vector<int> B(Q);
    for (i=0; i<Q; i++) {
        cin >> B[i];
    }
    for (i=0; i<Q; i++) {
        int ans;
        // auto pos = lower_bound(A.begin(), A.end(), B[i]);
        // if (pos == A.end()) {
        //     ans = llabs(B[i] - A[N-1]);
        // } else if (pos == A.begin()) {
        //     ans = llabs(B[i] - A[0]);
        // } else {
        //     ans = min(llabs(B[i] - *pos), llabs(B[i] - *(pos-1)));
        // }
        ans = binarySearch(B[i], A, N);
        cout << ans << endl;
    }
    
    return 0;
}