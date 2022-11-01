#include <bits/stdc++.h>
using namespace std;
#define MAX_A   13

int A[MAX_A][MAX_A];
int B[MAX_A][MAX_A];

int main(void)
{
    int i, j;
    int h, w;
    int H1, H2, W1, W2;
    cin >> H1 >> W1;
    for (h=1; h<=H1; h++) {
        for (w=1; w<=W1; w++) {
            cin >> A[h][w];
        }
    }
    cin >> H2 >> W2;
    for (h=1; h<=H2; h++) {
        for (w=1; w<=W2; w++) {
            cin >> B[h][w];
        }
    }

    for (h=0; h<pow(2, H1); h++) {
        for (w=0; w<pow(2, W1); w++) {
            vector<int> hvec, wvec;
            for(int i = 1; i <= H1; i++) if((h & (1<<(i-1))) == 0) hvec.push_back(i);
            for(int i = 1; i <= W1; i++) if((w & (1<<(i-1))) == 0) wvec.push_back(i);
            if(hvec.size() != H2 || wvec.size() != W2) continue;

            bool match = true;
            for (i=1; i<=H2; i++) {
                for (j=1; j<=W2; j++) {
                    if (A[hvec[i-1]][wvec[j-1]] != B[i][j]) {
                        match = false;
                        break;
                    }
                }
            }
            if (match) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
