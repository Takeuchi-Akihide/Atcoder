#include <bits/stdc++.h>
using namespace std;
#define MAX_N       30

int clearFlg[MAX_N][MAX_N];
int statusNow[MAX_N][MAX_N];
int statusAfter[MAX_N][MAX_N];
int H, W, K;

int setClearFlg() {
    int i, j, h, w;
    int now;
    for (h=1; h<=H; h++) {
        for (w=1; w<=W; w++) {
            clearFlg[h][w] = false;
        }
    }
    fill(d, d + V, false);
    for (h=H; h>=1; h--) {
        int count = 0;
        for (w=1; w<=W; w++) {
            if (count == 0) {
                now = statusNow[h][w];
                count = 1;
            } else {
                if (now == statusNow[h][w] && statusNow[h][w] != 0) {
                    count++;
                    if (count >= K) {
                        for (i=w; i>w-count; i--) {
                            clearFlg[h][i] = true;
                        }
                    }
                } else {
                    now = statusNow[h][w];
                    count = 1;
                }
            }
        }
    }
}

int clearCell() {
    int i, j, h, w;
    int clearNum[MAX_N];
    for (h=1; h<=H; h++) {
        for (w=1; w<=W; w++) {
            statusAfter[h][w] = 0;
            clearNum[w] = 0;
        }
    }
    
    for (h=H; h>=1; h--) {
        for (w=1; w<=W; w++) {
            if (clearFlg[h][w] == true) {
                clearNum[h][w]++;
            }
            statusAfter[h][w] = statusNow[i][j-]
        }
    }


}

int main(void) {
    int i, j, h, w
    int c[MAX_N][MAX_N];
    cin >> H >> W >> K;
    for (i=1; i<=H, i++) {
        for (j=1; j<=W; j++) {
            cin >> c[i][j];
        }
    }
    int x[MAX_N], y[MAX_N];
    double r[MAX_N];
    cin >> N >> M;
    for (i=1; i<=N; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (i=N+1; i<=N+M; i++) {
        cin >> x[i] >> y[i];
    }

    for (i=N+1; i<=N+M; i++) {
        r[i] = 400;
        for (j=1; j<=M+N; j++) {
            if (i == j) continue;
            double tmpR = pow(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2), 0.5);
            if (j <= N) tmpR -= r[j];
            else tmpR /= 2;
            if (tmpR < r[i]) r[i] = tmpR;
        }
    }
    double min = 400;
    for (i=1; i<=N+M; i++) {
        if (r[i] < min) min = r[i];
    }
    cout << fixed << setprecision(15) << min << endl;
    return 0;
}
