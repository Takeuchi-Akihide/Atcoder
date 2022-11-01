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
    float A, B;
    cin >> A >> B;
    float ans = B / A;
    
    cout << fixed << std::setprecision(3) << ans << endl;
    return 0;
}