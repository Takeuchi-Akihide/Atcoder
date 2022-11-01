#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;
typedef pair<int, int> P;   // class, point

int main(void) {
    int i, j;
    int N;
    cin >> N;
    vector<P> score(N+1);
    for (i=1; i<=N; i++) {
        int c, p;
        cin >> c >> p;
        score[i] = P(c, p);
    }
    vector<vector<int>> sum(N+1, vector<int>(2, 0));   // sum[i][j] := 学籍番号iまでのj組生徒の点数の合計
    for (i=1; i<=N; i++) {
        for (j=0; j<=1; j++) {
            sum[i][j] = sum[i-1][j];
        }
        sum[i][score[i].first-1] += score[i].second;
    }

    int Q;
    cin >> Q;
    vector<P> ans(Q);
    for (i=0; i<Q; i++) {
        int L, R;
        cin >> L >> R;
        ans[i] = P(sum[R][0] - sum[L-1][0], sum[R][1] - sum[L-1][1]);
    }
    for (i=0; i<Q; i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}