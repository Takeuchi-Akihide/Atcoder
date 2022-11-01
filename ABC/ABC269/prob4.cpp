#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;

typedef pair<int, int> P;   // first：i、second：j

int main(int argc, char *argv[]) {
    int i, j;
    int N;
    cin >> N;
    vector<vector<int>> map(2010, vector<int>(2010, 0));
    vector<vector<bool>> used(2010, vector<bool>(2010, false));
    int count = 0;
    for (i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        x += 1001;
        y += 1001;
        map[x][y] = 1;
    }
    for (i=1; i<=2001; i++) {
        for (j=1; j<=2001; j++) {
            if (map[i][j] && !used[i][j]) {
                count++;
                used[i][j] = true;
                stack<P> que;
                que.push(P(i,j));
                while(!que.empty()) {
                    int ii, jj;
                    ii = que.top().first;
                    jj = que.top().second;
                    que.pop();
                    used[ii][jj] = true;
                    if (map[ii-1][jj-1] && !used[ii-1][jj-1]) que.push(P(ii-1,jj-1));   
                    if (map[ii-1][jj]   && !used[ii-1][jj])   que.push(P(ii-1,jj));
                    if (map[ii][jj-1]   && !used[ii][jj-1])   que.push(P(ii,  jj-1));
                    if (map[ii][jj+1]   && !used[ii][jj+1])   que.push(P(ii,  jj+1));
                    if (map[ii+1][jj]   && !used[ii+1][jj])   que.push(P(ii+1,jj));
                    if (map[ii+1][jj+1] && !used[ii+1][jj+1]) que.push(P(ii+1,jj+1));
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}