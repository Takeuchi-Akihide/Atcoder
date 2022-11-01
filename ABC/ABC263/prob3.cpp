#include <bits/stdc++.h>
using namespace std;


vector<int> buf;

void dfs(int i, const int size, const int range_start, const int range_end)
{
    if (i == size) {
        // ここで所望の作業を行う
        for(int i = 0; i < buf.size()-1; ++i){
            cout << buf[i] << " ";
        }
        cout << buf[buf.size()-1] << endl;
    }
    else{
        for(int j = range_start; j <= range_end; ++j){
            buf[i] = j;
            dfs(i + 1, size, j+1, range_end);
        }
    }
}

int main(void)
{
    int i, j, k;
    int N, M;
    cin >> N >> M;
    
    buf.resize(N);
    dfs(0, N, 1, M);

    return 0;
}
