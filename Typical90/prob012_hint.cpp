#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;
typedef pair<int, int> P;   // class, point

int H, W;
vector<vector<int>> HW(2005, vector<int>(2005, 0));

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> rank;
    vector<int> num;

    UnionFind(int N) : par(N), rank(N), num(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
            num[i] = 1;
        }
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        num[rx] += num[ry];
        num[ry] = num[rx];
        if (rank[rx] < rank[ry]) {
            par[rx] = ry;
        } else {
            par[ry] = rx;
        }
        if (rank[rx] == rank[ry]) rank[rx]++;
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int sameNum(int x) {
        return num[root(x)];
    }
};

void query1(int px, int py, UnionFind *tree) {
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
    int i;
    int hash1 = (px - 1) * W + (py - 1);
    for (i=0; i<4; i++) {
        int sx = px + dx[i];
        int sy = py + dy[i];
        if (HW[sx][sy] == 0) continue;
        int hash2 = (sx - 1) * W + (sy - 1);
        tree->unite(hash1, hash2);
    }
}

bool query2(int px, int py, int qx, int qy, UnionFind *tree) {
    if (HW[px][py] == 0 || HW[qx][qy] == 0) {
        return false;
    }
    int hash1 = (px - 1) * W + (py - 1);
    int hash2 = (qx - 1) * W + (qy - 1);
    if (tree->same(hash1, hash2)) {
        return true;
    }
    return false;
}

int main(void) {
    ll i, j;
    cin >> H >> W;
    UnionFind tree(H*W);
    int Q;
    cin >> Q;
    vector<int> ans;
    for (i=0; i<Q; i++) {
        int q;
        cin >> q;
        switch (q)
        {
        case 1:
            int r, c;
            cin >> r >> c;
            HW[r][c] = 1;
            query1(r, c, &tree);
            break;
        case 2:
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ans.push_back(query2(ra, ca, rb, cb, &tree));            
            break;        
        default:
            break;
        }
    }
    for (i=0; i<ans.size(); i++) {
        if (ans[i]) cout << "Yes" << endl;
        else        cout << "No" << endl;
    }
    return 0;
}