#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;
typedef pair<int, int> P;   // x, y

int main(void) {
    int i, j, k;
    int N;
    cin >> N;
    vector<P> point(N);
    for (i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        point[i] = P(x, y);
    }
    // for (i=0; i<N; i++) {
    //     cout << "[" << i << "]: " << point[i].first << ", " << point[i].second << endl;
    // }
    float ans = 1;
    int A, B, C;
    for (i=0; i<N-2; i++) {
        for (j=i+1; j<N-1; j++) {
            for (k=j+1; k<N; k++) {
                A = i; B = j; C = k;
                float tmp;
                tmp = ((point[B].first - point[A].first) * (point[C].second - point[A].second) - (point[B].second - point[A].second) * (point[C].first - point[A].first)) 
                      / pow(pow((point[B].first - point[A].first), 2) + pow((point[B].second - point[A].second), 2) * (pow((point[C].first - point[A].first), 2) + pow((point[C].second - point[A].second), 2)), 0.5);
                if (abs(ans + 1) > abs(tmp + 1)) {
                    ans = tmp;
                }
                A = j; B = k; C = i;
                tmp = ((point[B].first - point[A].first) * (point[C].second - point[A].second) - (point[B].second - point[A].second) * (point[C].first - point[A].first)) 
                      / pow(pow((point[B].first - point[A].first), 2) + pow((point[B].second - point[A].second), 2) * (pow((point[C].first - point[A].first), 2) + pow((point[C].second - point[A].second), 2)), 0.5);
                if (abs(ans + 1) > abs(tmp + 1)) {
                    ans = tmp;
                }
                A = k; B = i; C = j;
                tmp = ((point[B].first - point[A].first) * (point[C].second - point[A].second) - (point[B].second - point[A].second) * (point[C].first - point[A].first)) 
                      / pow(pow((point[B].first - point[A].first), 2) + pow((point[B].second - point[A].second), 2) * (pow((point[C].first - point[A].first), 2) + pow((point[C].second - point[A].second), 2)), 0.5);
                if (abs(ans + 1) > abs(tmp + 1)) {
                    ans = tmp;
                }
            }
        }
    }
    cout << ans << endl;
    ans = (asin(ans) * 180 / M_PI);
    if (ans < 0) ans = 180 - ans;
    if (ans > 180) ans -= 180;
    cout << ans << endl;
    return 0;
}