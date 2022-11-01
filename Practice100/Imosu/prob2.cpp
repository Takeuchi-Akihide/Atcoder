#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define MAX_N   10005
#define MAX_S   86401

int mapA[MAX_S] = {0};
int ans[MAX_N];

int main(int argc, char *argv[]) {
    int i, j, k;
    string a, b;
    int n;
    int ans_i = 0;
    while (1) {
        for (j=0; j<MAX_S; j++) {
            mapA[j] = 0;
        }
        cin >> n;
        if (n == 0) {
            break;
        }
        for (i=1; i<=n; i++) {
            cin >> a >> b;
            int h, m, s, time;
            h = (a[0]-'0') * 10 + (a[1]-'0');
            m = (a[3]-'0') * 10 + (a[4]-'0');
            s = (a[6]-'0') * 10 + (a[7]-'0');
            time = h * 3600 + m * 60 + s;
            mapA[time]++;
            h = (b[0]-'0') * 10 + (b[1]-'0');
            m = (b[3]-'0') * 10 + (b[4]-'0');
            s = (b[6]-'0') * 10 + (b[7]-'0');
            time = h * 3600 + m * 60 + s;
            mapA[time]--;
        }
        for (i=1; i<MAX_S; i++) {
            mapA[i] += mapA[i-1];
        }
        int max = 0;
        for (i=0; i<MAX_S; i++) {
            if (max < mapA[i]) {
                max = mapA[i];
            }
        }
        ans[ans_i] = max;
        ans_i++;
    }
    for (i=0; i<ans_i; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}