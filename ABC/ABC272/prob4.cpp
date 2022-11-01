#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
typedef pair<int, int> P;       // first：x軸方向、second：y軸方向

int main(int argc, char *argv[]) {
    int i, j, k;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> used(N, vector<int>(N, -1));
    used[0][0] = 0;
    vector<P> move;
    queue<P> que2;

    for (i=0; i<=sqrt(M); i++) {
        int tmp1 = M - i*i;
        int tmp2 = (int)sqrt(tmp1);
        if (i * i + tmp2 * tmp2 == M) {
            move.push_back(P(i, tmp2));
        }
    }
    if (!move.empty()) {
        que2.push(P(0, 0));
        for (i=0; i<N*2; i++) {
            int size = que2.size();
            for (j=0; j<size; j++) {
                P p = que2.front();
                que2.pop();
                for (k=0; k<move.size(); k++) {
                    int nexti, nextj;
                    nexti = p.first + move[k].first;
                    nextj = p.second + move[k].second;
                    if (nexti >= 0 && nexti < N && nextj >= 0 && nextj < N) {
                        if (used[nexti][nextj] == -1) {
                            used[nexti][nextj] = i+1;
                            que2.push(P(nexti, nextj));
                        }
                    }
                    nexti = p.first - move[k].first;
                    nextj = p.second - move[k].second;
                    if (nexti >= 0 && nexti < N && nextj >= 0 && nextj < N) {
                        if (used[nexti][nextj] == -1) {
                            used[nexti][nextj] = i+1;
                            que2.push(P(nexti, nextj));
                        }
                    }
                    nexti = p.first + move[k].first;
                    nextj = p.second - move[k].second;
                    if (nexti >= 0 && nexti < N && nextj >= 0 && nextj < N) {
                        if (used[nexti][nextj] == -1) {
                            used[nexti][nextj] = i+1;
                            que2.push(P(nexti, nextj));
                        }
                    }
                    nexti = p.first - move[k].first;
                    nextj = p.second + move[k].second;
                    if (nexti >= 0 && nexti < N && nextj >= 0 && nextj < N) {
                        if (used[nexti][nextj] == -1) {
                            used[nexti][nextj] = i+1;
                            que2.push(P(nexti, nextj));
                        }
                    }
                }
            }

        }
    }
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            cout << used[i][j];
            if (j != N-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}