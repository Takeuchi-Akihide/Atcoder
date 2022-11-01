#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, k;
    bool isBlack = false;
    int R, C;
    cin >> R >> C;
    if (R % 2 == 1) {
        switch (R)
        {
        case 1:
        case 15:
            isBlack = true;
            break;
        case 3:
        case 13:
            if (C == 2 || C == 14) {
            } else {
                isBlack = true;
            }
            break;
        case 5:
        case 11:
            if (C == 2 || C == 4 || C == 12 || C == 14) {
            } else {
                isBlack = true;
            }
        case 7:
        case 9:
            if (C != 8 && C % 2 == 0) {
            } else {
                isBlack = true;
            }
        default:
            break;
        }
    } else {
        switch (R)
        {
        case 2:
        case 14:
            if (C == 1 || C == 15) {
                isBlack = true;
            }
            break;
        case 4:
        case 12:
            if (C == 1 || C == 3 ||C == 13 || C == 15) {
                isBlack = true;
            }
            break;
        case 6:
        case 10:
            if (C == 1 || C == 3 || C == 5 || C == 11 || C == 13 || C == 15) {
                isBlack = true;
            }
        case 8:
            if (C % 2 == 1) {
                isBlack = true;
            }
        default:
            break;
        }
    }
    if (isBlack) {
        cout << "black" << endl;
    } else {
        cout << "white" << endl;
    }
    return 0;
}
