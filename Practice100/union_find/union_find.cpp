#include <bits/stdc++.h>
using namespace std;
#define MAX_V   105

vector<int> ans;

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
            ans.push_back(tree.same(A, B));
        }
    }
    for (i=0; i<ans.size(); i++) {
        if (ans[i]) cout << "Yes" << endl;
        else        cout << "No" << endl;
    }
    return 0;
}
