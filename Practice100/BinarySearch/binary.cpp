#include <bits/stdc++.h>
using namespace std;
#define     MAX_N   200005


/* 昇順に並んだarrayから、numの位置を返す(0~N-1)。見つからない場合は-1を返す */
int binarySearch(long long num, long long *array, long long N) {
    long long min = 0;
    long long max = N;
    long long mid;
    while (min <= max) {
        mid = (min + max) / 2;
        if (array[mid] == num) {
            return (int)mid;
        } else if (min == max) {
            return -1;
        } else if (array[mid] < num) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return -1;
}

/* array[i-1]<x<=array[i] のとき、iを返す */
/* arrayは昇順に並べ替えておく */
long long binarySearchNum(long long x, long long *array, long long n) {
    long long min = 0;
    long long max = n;
    long long mid;
    while (min <= max) {
        mid = (min + max) / 2;
        if (mid == 0 && x <= array[mid]) {
            return mid;
        } else if 
            ((mid == n-1 && array[mid] < x) ||
             (array[mid] < x && x <= array[mid+1])) {
            return mid + 1;
        } else if (array[mid] < x) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return -1; // ここには来ないはず
}

int main(){
    int i, j;
    long long N, P, Q, R;
    long long A[MAX_N];
    cin >> N >> P >> Q >> R;
    long long sumA[MAX_N] = {0};
    for (i=0; i<N; i++) {
        cin >> A[i];            
        sumA[i+1] = sumA[i] + A[i];
    }

    int x, y, z, w;
    for (x=0; x<N-2; x++) {
        y = binarySearch(sumA[x] + P, sumA, N);
        if (y == -1) {
            continue;
        }
        z = binarySearch(sumA[y] + Q, sumA, N);
        if (z == -1) {
            continue;
        }
        w = binarySearch(sumA[z] + R, sumA, N);
        if (w == -1) {
            continue;
        }
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}