#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define INF (1 << 30)


vector<int> ans(500000);
int main(void) {
    int Q;
    cin >> Q;
    map<int, vector<int>> note;
    vector<int> A;
    int i;
    int num;
    char query[10];
    for (i=0; i<Q; i++) {
        scanf("%s %d", query, &num);
        switch (query[0])
        {
        case 'A':
            A.push_back(num);
            break;
        case 'D':
            if (!A.empty()) {
                A.pop_back();
            }
            break;
        case 'S':
            note[num] = A;
            break;
        case 'L':
            A = note[num];
            break;
        default:
            break;
        }
        if (A.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = A.back();
        }
    }
    for (i=0; i<Q-1; i++) {
        cout << ans[i] << " ";
        // printf("%d ", ans[i]);
    }
    cout << ans[i] << "\n";
    // printf("%d\n", ans[Q-1]);
    return 0;
}
