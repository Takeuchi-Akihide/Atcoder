#include <bits/stdc++.h>
using namespace std;
#define MAX_N   200005

int main(void)
{
    int i, j;
    int N, M;
    long long A[MAX_N];
    cin >> N >> M;
    A[0] = 0;
    for (i=1; i<=N; i++) {
        cin >> A[i];
    }
    long long sumA[MAX_N];
    sumA[0] = 0;
    for (i=1; i<=N; i++) {
        sumA[i] = sumA[i-1] + A[i];
    }
    long long sum1 = 0, sum2 = 0;
    long long max = -1000000000000;
    for (i=1; i<=M; i++) {
        sum1 += A[i] * i;
    }
    max = sum1;
    for (i=2; i<=N-M+1; i++) {
        sum2 = sum1 + A[M+i-1] * M - (sumA[M+i-2] - sumA[i-2]);
        if (max < sum2) max = sum2;
        sum1 = sum2;
    }

    cout << max << endl;
    return 0;
}
