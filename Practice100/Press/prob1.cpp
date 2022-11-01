#include <bits/stdc++.h>
using namespace std;
#define MAX_N       100005

typedef pair<int, int> P;   // first：変化点、second：白(0)/黒(1)のどちらに変わったか

int main(void) {
    int i, j;
    int N;
    int a, b, last;
    stack<P> que;
    cin >> N;
    if (N == 1) {
        cin >> a;
        if (a == 0) cout << 1 << endl;
        else        cout << 0 << endl;
        return 0;
    }
    for (i=0; i<N/2; i++) {
        cin >> a >> b;
        if (que.empty()) {
            que.push(P(i*2, b));
            continue;
        }
        int lastColor = que.top().second;
        if (lastColor != b) {
            if (a == b) {
                que.push(P(i*2, b));
            } else {
                que.pop();
                if (que.empty()) {
                    que.push(P(0, b));
                }
            }
        }
    }
    if (N % 2 == 1) {
        cin >> last;
    }
    int next = (N/2) * 2;
    int count = 0;
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        if (p.second == 0) {
            count += (next - p.first);
        }
        next = p.first;
    }
    if (last == 0) count++;
    cout << count << endl;
    return 0;
}
