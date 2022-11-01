/*条件を満たす部分配列
説明
solution 関数には int 型の配列 nums が引数として与えられています。
任意のインデックス i に対して、以下の条件を満たす 部分配列 の数を solution 関数の戻り値として int 型の配列で返すプログラムを作成してください。

nums[i] の値は部分配列内で最大の値をとる唯一の要素である
部分配列の最初、または最後の要素は nums[i] である
例えば以下のような例が与えられたとします。

[3,4,1,6,2]
インデックス i=1 の時、条件を満たす部分配列の一部として次のようなものが挙げられます。

[3,4],[4],[4,1]
なぜなら上記の例は全て nums[1] が最大値であり、 nums[1] が最初、または最後の要素だからです。
返り値には、任意のインデックス i の時、条件を満たす部分配列の数を含む配列が期待されているため、上記の例の時返り値は以下のようになります。
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> nums) {
    vector<int> ans(nums.size(), 1);
    int i, j;
    for (i=0; i<nums.size(); i++) {
        // 左側を探索
        for (j=i-1; j>=0; j--) {
            if (nums[j] >= nums[i]) {
                break;
            } else {
                ans[i]++;
            }
        }
        // 右側を探索
        for (j=i+1; j<nums.size(); j++) {
            if (nums[j] >= nums[i]) {
                break;
            } else {
                ans[i]++;
            }
        }
    }
    return ans;
}

/* dpの亜種 */
/* https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_d */
int main (int argc, char *argv[]) {
    int N;
    cin >> N;
    vector<int> nums(N);
    int i;
    for (i=0; i<N; i++) {
        cin >> nums[i];
    }
    vector<int> ans(N);
    ans = solution(nums);
    for (i=0; i<N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
