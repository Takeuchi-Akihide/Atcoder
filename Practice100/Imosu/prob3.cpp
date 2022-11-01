#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define MAX_N   100005

int main(int argc, char *argv[]) {
    int i, j, k;
    int N, M;
    long long cost = 0;
    long long P[MAX_N], A[MAX_N], B[MAX_N], C[MAX_N];
    long long MAP[MAX_N];
    long long Thre[MAX_N];
    cin >> N >> M;
    for (i=1; i<=M; i++) {
        cin >> P[i];
    }
    for (i=1; i<=N-1; i++) {
        cin >> A[i] >> B[i] >> C[i];
        Thre[i] = C[i] / (A[i] - B[i]) + 1; /* 移動回数がThre[i]未満ならA*n, Thre[i]以上ならC+B*n */
    }
    for (i=1; i<=M-1; i++) {
        // 右向きの時は始点+1/終点-1 左向きの時は始点-1/終点+1
        if (P[i] < P[i+1]) {
            MAP[P[i]]++;
            MAP[P[i+1]]--;
        } else {
            MAP[P[i]]--;
            MAP[P[i+1]]++;
        }
    }
    for (i=2; i<=N-1; i++) {
        MAP[i] += MAP[i-1];
    }

    for (i=1; i<=N-1; i++) {
        if (MAP[i] < Thre[i]) {
            cost += A[i] * MAP[i];
        } else {
            cost += B[i] * MAP[i] + C[i];
        }
    }
    cout << cost << endl;
    return 0;
}