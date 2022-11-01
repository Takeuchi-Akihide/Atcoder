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
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    map<string, int> Tmap;
    string T;
    int Ssize = 0;
    for (i=0; i<N; i++) {
        cin >> S;
        Ssize += S.size();
    }
    Ssize += (N-1);
    for (i=0; i<M; i++) {
        cin >> T;
        Tmap[T] = 1;
    }
    vector<int> nums(N);
    iota(nums.begin(), nums.end(), 0);

    do {
        T = "";
        int it = 0;
        for (int value : nums) {
            it++;
            T.append(S[value]);
            if (it != N) {
                
            }
        }
    } while (next_permutation(nums.begin(), nums.end()));

    cout << max << endl;
    return 0;
}