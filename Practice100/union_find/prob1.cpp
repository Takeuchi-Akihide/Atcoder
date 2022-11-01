#include <bits/stdc++.h>
using namespace std;
#define MAX_V   100005

vector<int> ans;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(void) {
    int i, j;
    int N, Q;
    int P, A, B;
    cin >> N >> Q;
    UnionFind tree(N);
    for (i=0; i<Q; i++) {
        cin >> P >> A >> B;
        if (P == 0) {
            // 連結クエリ
            tree.unite(A, B);
        } else if (P == 1) {
            // 判定クエリ
            ans.push_back(tree.same(A, B));
        }
    }
    for (i=0; i<ans.size(); i++) {
        if (ans[i]) cout << 1 << endl;
        else        cout << 0 << endl;
    }
    return 0;
}
