#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <map>
using namespace std;
using namespace atcoder;
using ll = long long;
#define MAX_N   100005

int main(void) {
    int i;
    int N;
    cin >> N;
    map<int,int, std::greater<int>> A;
    int tmp;
    for (i=0; i<N; i++) {
        cin >> tmp;
        A[tmp]++;
    }
    vector<int> ans(N, 0);
    int num = 0;
    auto iter = A.begin();
    while (iter != A.end()) {
        ans[num] = iter->second;
        num++;
        ++iter;
    }
    for (i=0; i<N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}