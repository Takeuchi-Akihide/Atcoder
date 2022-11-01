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
    int i, j;
    int A[105] = {0};
    int N;
    int count = 0;
    for (i=0; i<5; i++) {
        cin >> N;
        A[N]++;
    }
    for (i=0; i<=100; i++) {
        if (A[i] > 0) count++;
    }
    cout << count << endl;
    return 0;
}