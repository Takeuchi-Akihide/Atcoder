#include <bits/stdc++.h>
using namespace std;
#define MAX_N   100005

int main(void) {
    int i, j;
    int N;
    vector<int> a;
    int now;
    cin >> N;
    for (i=1; i<=N; i++) {
        int tmp;
        cin >> tmp;
        if (i == 1) {
            a.push_back(i);
            now = abs(tmp - i%2);
        } else {
            if (now != abs(tmp - i%2)) {
                a.push_back(i);
                now = abs(tmp - i%2);
            }
        }
    }
    a.push_back(N+1);
    // for (i=0; i<a.size(); i++) {
    //     cout << a[i] << endl;
    // }
    int max;
    if (a.size() == 2) {
        max = a[1] - a[0];
    } else {
        max = a[2] - a[0];
    }
    if (a.size() <= 3) {
        cout << max << endl;
        return 0;
    }
    for (i=3; i<a.size(); i++) {
        int tmpMax = a[i] - a[i-3];
        if (tmpMax > max) {
            max = tmpMax;
        }
    }
    cout << max << endl;
    return 0;
}
