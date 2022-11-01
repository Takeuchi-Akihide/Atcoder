#include <bits/stdc++.h>
using namespace std;
#define MAX_N   50
#define MAX_M   MAX_N * MAX_N

vector<int> ans;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> rank;

    UnionFind(int N) : par(N), rank(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
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
};

int main(void) {
    int i, j;
    int N, M;
    int count = 0;
    int a[MAX_M], b[MAX_M];
    cin >> N >> M;
    for (i=0; i<M; i++) {
        cin >> a[i] >> b[i];
    }
    for (i=0; i<M; i++) {
        UnionFind tree(N);
        for (j=0; j<M; j++) {
            if (i == j) continue;
            tree.unite(a[j]-1, b[j]-1);
        }
        if (!tree.same(a[i]-1, b[i]-1)) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
