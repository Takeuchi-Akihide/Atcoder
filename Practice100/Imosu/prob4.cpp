#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define MAX_N   5005
#define MAX_M   500005

int MAP[MAX_N][MAX_N];

int main(int argc, char *argv[]) {
    int i, j, k;
    int N, M;
    long long count = 0;
    long long A, B, X;
    cin >> N >> M;
    for (i=1; i<=M; i++) {
        cin >> A >> B >> X;
        MAP[A][B]++;
        MAP[A][B+1]--;
        MAP[A+X+1][B]--;
        MAP[A+X+2][B+1]++;
        MAP[A+X+1][B+X+2]++;
        MAP[A+X+2][B+X+2]--;
    }
    for (i=1; i<=N+2; i++) {
        for (j=2; j<=N+2; j++) {
            MAP[i][j] += MAP[i][j-1];
        }
    }
    for (i=2; i<=N+2; i++) {
        for (j=1; j<=N+2; j++) {
            MAP[i][j] += MAP[i-1][j];
        }
    }
    for (i=2; i<=N+2; i++) {
        for (j=2; j<=N+2; j++) {
            MAP[i][j] += MAP[i-1][j-1];
        }
    }
    for (i=1; i<=N; i++) {
        for (j=1; j<=i; j++) {
            if (MAP[i][j] > 0) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}