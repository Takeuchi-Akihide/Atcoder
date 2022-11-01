#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX_M       100005
#define MOD         998244353

int main() {
    int i, j, k;
    int N, M;
    int A, B;
    vector<pair<int, int>> dxy;
    cin >> N >> M;
    for (i=0; i<3; i++) {
        cin >> A >> B;
        dxy.push_back({A, B});
    }

    // 障害物がある場所を登録
    set<pair<int, int>>S;
    for (i=0; i<M; i++) {
        cin >> A >> B;
        S.insert({A, B});
    }
    // dp[a][b] := (i回ワープ実行時に)dxy[0]をa回、dxy[1]をb回、dxy[2]をi-a-b回使った時の移動経路の数
    // new_dp[a][b] := (i+1回ワープ実行時に)dxy[0]をa回、dxy[1]をb回、dxy[2]をi+1-a-b回使った時の移動経路の数
    // new_dp=dpとすることを繰り返しながら、i=0~Nまで回す
    vector<vector<ll>> dp(1, vector<ll>(1));    // 1*1の2次元配列。
    dp[0][0] = 1;
    for (i=0; i<N; i++) {
        vector<vector<ll>> new_dp(i+2, vector<ll>(i+2));        // (i+2)*(i+2)の2次元配列。
        for (ll a=0; a<=i; a++) for(ll b=0; b<=i-a; b++) {
            ll x = a * dxy[0].first + b * dxy[1].first + (i - a - b) * dxy[2].first;
            ll y = a * dxy[0].second + b * dxy[1].second + (i - a - b) * dxy[2].second;
            // dp[a][b]には上記定義が書かれているので、i=i+1のときの値を追加する
            // new_dpには、a=0~i+1, b=0~i+1の全領域が埋まる
            for (k=0; k<3; k++) {
                if (S.find({x+dxy[k].first, y+dxy[k].second}) == S.end()) {
                    new_dp[a+(k==0)][b+(k==1)] += dp[a][b];
                    new_dp[a+(k==0)][b+(k==1)] %= MOD;
                }
            }
        }
        swap(dp, new_dp);
    }

    ll ans = 0;
    for (int a=0; a<=N; a++) for (int b=0; b<=N; b++) {
        ans += dp[a][b];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
