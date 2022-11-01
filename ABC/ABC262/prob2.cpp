#include <bits/stdc++.h>
using namespace std;
#define     MAX_N   105

int main() {
    int i, j, k;
    int U, V;
    int N, M;
    cin >> N >> M;
    int Graph[MAX_N][MAX_N];
    for (i=0; i<M; i++) {
        cin >> U >> V;
        Graph[U][V] = 1;
    }
    int count = 0;
    for (i=1; i<=N-2; i++) {
        for (j=i+1; j<=N-1; j++) {
            for (k=j+1; k<=N; k++) {
                if (Graph[i][j] == 1 && Graph[i][k] == 1 && Graph[j][k] == 1) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}
