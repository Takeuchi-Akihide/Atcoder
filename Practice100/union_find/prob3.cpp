#include <bits/stdc++.h>
using namespace std;
#define MAX_M   100005

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
    int N, M;
    long long ans[MAX_M];
    int a[MAX_M], b[MAX_M];
    cin >> N >> M;
    for (i=0; i<M; i++) {
        cin >> a[i] >> b[i];
    }
    UnionFind tree(N);
    ans[M] = (long long)N * ((long long)N - 1) / 2;
    for (i=M-1; i>0; i--) {
        if (tree.root(a[i]-1) == tree.root(b[i]-1)) {
            ans[i] = ans[i+1];
            continue;
        }
        ans[i] = ans[i+1] - tree.sameNum(a[i]-1) * tree.sameNum(b[i]-1);
        tree.unite(a[i]-1, b[i]-1);
    }
    for(i=1; i<=M; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
