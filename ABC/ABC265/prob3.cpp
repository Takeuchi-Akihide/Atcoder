#include <bits/stdc++.h>
using namespace std;
#define MAX_H   505

int G[MAX_H][MAX_H];
enum {
    U = 0,
    D,
    L,
    R,
    MAX_NUM,
};

int main(void)
{
    int i, j;
    int H, W;
    cin >> H >> W;
    string buf;
    for (i=1; i<=H; i++) {
        cin >> buf;
        for (j=1; j<=W; j++) {
            switch (buf[j-1])
            {
            case 'U':
                G[i][j] = U;
                break;
            case 'D':
                G[i][j] = D;
                break;
            case 'L':
                G[i][j] = L;
                break;
            case 'R':
                G[i][j] = R;
                break;
            default:
                break;
            }
        }
    }
    int x = 1;
    int y = 1;
    for (i=0; i<=MAX_H*MAX_H*2; i++) {
        switch (G[x][y])
        {
        case U:
            if (x == 1) {
                cout << x << " " << y << endl;
                return 0;
            }
            x -= 1;
            break;
        case D:
            if (x == H) {
                cout << x <<" " <<  y << endl;
                return 0;
            }
            x += 1;
            break;
        case L:
            if (y == 1) {
                cout << x <<" " <<  y << endl;
                return 0;
            }
            y -= 1;
            break;
        case R:
            if (y == W) {
                cout << x <<" " <<  y << endl;
                return 0;
            }
            y += 1;
            break;
        
        default:
            break;
        }
    }
    cout << -1 << endl;
    return 0;
}
