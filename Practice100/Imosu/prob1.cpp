#include <bits/stdc++.h>
using namespace std;
#define MAX_N   100005
#define MAX_A   1000001

int mapA[MAX_A] = {0};

int main(int argc, char *argv[]) {
    int i, j, k;
    int a, b;
    int n;
    cin >> n;
    for (i=1; i<=n; i++) {
        cin >> a >> b;
        mapA[a]++;
        mapA[b+1]--;
    }
    for (i=1; i<MAX_A; i++) {
        mapA[i] += mapA[i-1];
    }
    int max = 0;
    for (i=0; i<MAX_A; i++) {
        if (max < mapA[i]) {
            max = mapA[i];
        }
    }
    cout << max << endl;
    return 0;
}