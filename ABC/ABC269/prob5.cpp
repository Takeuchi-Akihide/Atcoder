#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define MAX_N   100005
#define MAX_A   1000001

int main(void) {
    int i;
    int x, y;
    int N;
    cin >> N;
    int min = 1;
    int max = N;
    int mid;
    int T;
    int num;
    for (i=0; i<10; i++) {
        mid = (min + max) / 2;
        num = mid - min + 1;
        cout << "? " << min << " " << mid << " " << 1 << " " << N << endl;
        cin >> T;
        if (T == -1) {
            return 0;
        }
        if (T == num) {
            mid++;
            min = mid;
        } else {
            max = mid;
        }
        if (num == 1) {
            break;
        }
    }
    x = mid;
    min = 1;
    max = N;
    for (i=0; i<10; i++) {
        mid = (min + max) / 2;
        num = mid - min + 1;
        cout << "? " << 1 << " " << N << " " << min << " " << mid << endl;
        cin >> T;
        if (T == -1) {
            return 0;
        }
        if (T == num) {
            mid++;
            min = mid;
        } else {
            max = mid;
        }
        if (num == 1) {
            break;
        }
    }
    y = mid;
    cout << "!" << " " << x << " " << y << endl;
    return 0;
}