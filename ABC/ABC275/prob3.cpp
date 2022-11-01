#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
#define MAX_N   100005

int main(void) {
    int ans = 0;
    int map[9][9] = {0};
    int i, j;
    string ch;
    for (i=0; i<9; i++) {
        cin >> ch;
        for (j=0; j<9; j++) {
            if (ch[j] == '#') {
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
    }
    for (i=0; i<81; i++) {
        int x1 = i % 9;
        int y1 = i / 9;
        if (map[x1][y1] == 0) continue;
        for (j=i+1; j<81; j++) {
            int x2 = j % 9;
            int y2 = j / 9;
            if (map[x2][y2] == 0) continue;
            if (x2 < x1 || y2 <= y1) continue;
            int x3 = x2 - (y2 - y1);
            int y3 = y2 + (x2 - x1);
            int x4 = x1 - (y2 - y1);
            int y4 = y1 + (x2 - x1);
            if (x3 < 0 || x4 < 0 || y3 < 0 || y4 < 0 || x3 >= 9 || x4 >= 9 || y3 >= 9 || y4 >= 9) {
                continue;
            }
            if (map[x3][y3] && map[x4][y4]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}