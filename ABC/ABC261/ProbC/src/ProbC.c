#include <iostream>
#include <map>
#include <string>
using namespace std;
#define MAX_N   200005

int main() {
    int N;
    cin >> N;
    map<string,int>cnt;
    string S[MAX_N];
    for (int i=0; i<N; i++) {
        cin >> S[i];
    }
    for (int i=0; i<N; i++) {
        if(cnt[S[i]] == 0) {
            cout << S[i] << endl;
        } else {
            cout << S[i] << "(" << cnt[S[i]] << ")" << endl;
        }
        cnt[S[i]]++;
    }
    return 0;
}