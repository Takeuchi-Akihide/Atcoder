#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
#define MAX_N   100005
#define MAX_A   1000001

int main(int argc, char *argv[]) {
    int N;
    int max = 0;
    int maxNum = 0;
    cin >> N;
    for (int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > max) {
            max = tmp;
            maxNum = i + 1;
        }
    }
    cout << maxNum << endl;
    return 0;
}