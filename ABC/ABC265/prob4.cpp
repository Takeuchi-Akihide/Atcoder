#include <bits/stdc++.h>
using namespace std;
#define     MAX_N   200005

long long sumA[MAX_N] = {0};

int binarySearch(long long num, long long N) {
    long long min = 0;
    long long max = N;
    long long mid;
    while (min <= max) {
        mid = (min + max) / 2;
        if (sumA[mid] == num) {
            return (int)mid;
        } else if (min == max) {
            return -1;
        } else if (sumA[mid] < num) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return -1;
}

int main(){
    int i, j;
    long long N, P, Q, R;
    long long A[MAX_N];
    cin >> N >> P >> Q >> R;
    for (i=0; i<N; i++) {
        cin >> A[i];            
        sumA[i+1] = sumA[i] + A[i];
    }

    int x, y, z, w;
    for (x=0; x<N-2; x++) {
        y = binarySearch(sumA[x] + P, N);
        if (y == -1) {
            continue;
        }
        z = binarySearch(sumA[y] + Q, N);
        if (z == -1) {
            continue;
        }
        w = binarySearch(sumA[z] + R, N);
        if (w == -1) {
            continue;
        }
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}