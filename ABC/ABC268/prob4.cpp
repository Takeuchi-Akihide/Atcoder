#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;

map<string, int> Tmap;

void dfs(int cur, vector<string> &S, int remain, string ans){
    if (remain < 0) return;
    if (cur == S.size()) {
        if (ans.size() >= 3 && Tmap[ans] == 0) {
            cout << ans << endl;
            exit(0);
        }
        return;
    }

    if (ans.size() > 0 && ans.back() != '_') {
        dfs(cur, S, remain, ans + "_");
    } else {
        dfs(cur + 1, S, remain, ans + S[cur]);
        if (ans.size() > 0 && remain >= 1) {
            dfs(cur, S, remain-1, ans + "_");
        }
    }
}

int main(int argc, char *argv[]) {
    int i, j;
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    string T;
    int remain = 16;
    for (i=0; i<N; i++) {
        cin >> S[i];
        remain -= S[i].size();
    }
    sort(S.begin(), S.end());
    remain -= (N-1);
    for (i=0; i<M; i++) {
        cin >> T;
        Tmap[T] = 1;
    }

    do {
        dfs(0, S, remain, "");
    } while (next_permutation(S.begin(), S.end()));

    cout << "-1" << endl;
    return 0;
}