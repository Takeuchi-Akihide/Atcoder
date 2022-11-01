#include <bits/stdc++.h>
#include "test.h"
using namespace std;

int main(int argc, char *argv[]) {
    testBuiltin_popcountll();
    return 0;
}

int testBitset() {
    // 例 1: A or B を計算します。なお、A と B は string 型で 2 進数で与えられます。
    string A; cin >> A;
    string B; cin >> B;

    bitset<2000> A1(A);
    bitset<2000> B1(B);
    bitset<2000> ans = (A1 | B1);

    bool flag = false;
    for (int i = 1999; i >= 0; i--) {
        if (ans[i] == 1) flag = true;
        if (flag == true) cout << ans[i];
    }
    cout << endl;
    return 0;
}

int testBuiltin_popcountll() {
    // 例 1: x を 2 進数表記したときに、1 であるビットの個数を出力する。
    long long x;
    cin >> x;
    cout << __builtin_popcountll(x) << endl;
    return 0;
}

int testNext_permutation() {
    // N 個の都市があり、都市 i から j まで移動するのにかかる時間は A[i][j] 分
    // 全ての都市を訪れるのに何分かかるか？　ただし、どの都市から出発、どの都市に到着してもよい。
    // A[i][j] = A[j][i], A[i][i] = 0
    int N, A[12][12], B[12], perm[12], ans = 2000000000;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> A[i][j];
    }
    for (int i = 0; i < N; i++) B[i] = i + 1;

    do {
        int sum = 0;
        for (int i = 0; i < N - 1; i++) {
            sum += A[B[i]][B[i + 1]];
        }
        ans = min(ans, sum);
    } while(next_permutation(B, B + N));

    cout << ans << endl;
    return 0;
}

int testFind() {
    // 例 1: a[1], a[2], ..., a[N] を受け取る。その後、Q 個の質問を受け取る。
    // 各質問は (l, r, x) の組から成り、a[l], a[l+1], ..., a[r] の中で x が存在しない場合 -1
    // そうでない場合、存在する位置（ポインタではない）を出力する。
    int N, Q, a[1009];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        int f = find(a + l, a + r + 1, x) - a;
        if (f == r + 1) cout << "-1" << endl; // 存在しない場合
        else cout << f << endl; // 存在する場合
    }
    return 0;
}

int testCount(){
    // 例 1: 配列 a に含まれる 1 の個数、2 の個数を出力する（それぞれ　4, 3 と出力されます）
    int a[10] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 1};
    cout << count(a, a + 10, 1) << endl;
    cout << count(a, a + 10, 2) << endl;

    // 例 2: b[1], b[2], ..., b[N] を受け取り、その後 Q 個の質問を受け取る。
    // 各質問に対し、b[l], b[l+1], ..., b[r] の中で x が何個あるかを出力する。
    int b[1009], N, Q;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> b[i];
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << count(b + l, b + r + 1, x) << endl;
    }
    return 0;
}

int testAssert() {
    // 例 1: a[i] + a[j] = X を満たす (i, j) [i < j] の個数を列挙する
    // N > 10000 の場合実行時間が間に合わない（TLE する）のでランタイムエラーを起こすようにする
    int N, X, cnt, a[10009];
    cin >> N >> X;
    for (int i = 1; i <= N; i++) cin >> a[i];
    assert(N <= 10000);

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (a[i] + a[j] == X) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

int testTuple() {
    // 例 1: tuple の基本
    tuple<int, int, int> A;
    cin >> get<0>(A) >> get<1>(A) >> get<2>(A);
    cout << get<0>(A) + get<1>(A) + get<2>(A) << endl;

    // 例 2: vector にも tuple を入れられます、この例はソートするプログラムです
    vector<tuple<double, int, int>> B; int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        double p1; int p2, p3;
        cin >> p1 >> p2 >> p3;
        B.push_back(make_tuple(p1, p2, p3));
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) printf("%.5lf %d %d\n", get<0>(B[i]), get<1>(B[i]), get<2>(B[i]));
    return 0;
}

int testPair() {
    // 例 1: N 人の成績と名前を入力して、成績の大きい順にソートする
    int N;
    pair<int, string> a[109];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i].second; // 名前を入力する
        cin >> a[i].first; // 成績を入力する
    }
    sort(a, a + N, greater<pair<int, string>>());
    for (int i = 0; i < N; i++) {
        cout << "Name = " << a[i].second << ", Score = " << a[i].first << endl;
    }
    return 0;
}

int testSet() {
    // 例 1: set に対して色々な操作を行う（1 個目は "End"、2 個目は "46" と出力される）
    set<int> Set;
    Set.insert(37); // その時点での Set の要素は {37}
    Set.insert(15); // その時点での Set の要素は {15, 37}
    Set.insert(37); // その時点での Set の要素は {15, 37}
    auto itr1 = Set.lower_bound(40);
    if (itr1 == Set.end()) cout << "End" << endl;
    else cout << (*itr1) << endl;
    Set.erase(37); // その時点での Set の要素は {15}
    Set.insert(46); // その時点での Set の要素は {15, 46}
    auto itr2 = Set.lower_bound(20);
    if (itr2 == Set.end()) cout << "End" << endl;
    else cout << (*itr2) << endl;

    // 例 2: a[1],a[2],...,a[N] を小さい順に出力する（同じ要素が複数ある場合 1 回だけ出力する）
    set<int> b; int N, a[100009];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) b.insert(a[i]);
    auto itr = b.begin();
    while (itr != b.end()) {
        cout << (*itr) << endl;
        itr++;
    }
    return 0;
}

int testLower_bound() {
    // 例 1: a[i] < x となるような i が何個あるのかを O(log N) で計算する
    int N, a[100009];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);

    int x;
    cin >> x;
    cout << lower_bound(a, a + N, x) - a << endl;
    return 0;
}

int testMap() {
    map<string, int> Map;
    Map["qiita"] = 777;
    Map["algorithm"] = 1111;
    Map["competitive_programming"] = 1073741824;

    cout << Map["algorithm"] << endl; // 1111 と出力される
    cout << Map["tourist"] << endl; // まだ何も書き込まれていないので、0 と出力される
    return 0;
}

int testPriorityQueue() {
    // 例 1: Q に色々な操作を行う（x1 = 116, x2 = 110, x3 = 122, x4 = 2 となります）
    priority_queue<int, vector<int>, greater<int>> Q;   // 最も小さい値を取り出したい場合
    // priority_queue<int, vector<int>, less<int>> Q;   // 最も大きい値を取り出したい場合
    Q.push(116); // この時点で、小さい順に {116}
    Q.push(145); // この時点で、小さい順に {116, 145}
    Q.push(122); // この時点で、小さい順に {116, 122, 145}
    int x1 = Q.top();
    Q.push(110); // この時点で、小さい順に {110, 116, 122, 145}
    int x2 = Q.top();
    Q.pop(); // この時点で、小さい順に {116, 122, 145}
    Q.pop(); // この時点で、小さい順に {122, 145}
    int x3 = Q.top();
    int x4 = Q.size();

    cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
    return 0;
}

int testQueue() {
    // 例 1: a に色々な操作を行う（x1 = 179, x2 = 173, x3 = 156, x4 = 3, x5 = 0 となります）
    queue<int> a;
    a.push(179); // その時点で前から順に {179}
    a.push(173); // その時点で前から順に {179, 173}
    a.push(156); // その時点で前から順に {179, 173, 156}
    int x1 = a.front();
    a.pop(); // その時点で前から順に {173, 156}
    a.push(117); // その時点で前から順に {173, 156, 117}
    a.push(202); // その時点で前から順に {173, 156, 117, 202}
    int x2 = a.front();
    a.pop(); // その時点で前から順に {156, 117, 202}
    int x3 = a.front();
    int x4 = a.size();
    int x5 = 0; if (a.empty()) x5 = 10000;

    cout << x1 << " " << x2 << " "<< x3 << " " << x4 << " " << x5 << endl;
    return 0;
}

int testStack() {
    // 例 1: a に色々な操作を行う（x1 = 156, x2 = 202, x3 = 117, x4 = 3, x5 = 0 となります）
    stack<int> a;
    a.push(179); // その時点で下から順に {179}
    a.push(173); // その時点で下から順に {179, 173}
    a.push(156); // その時点で下から順に {179, 173, 156}
    int x1 = a.top();
    a.pop(); // その時点で下から順に {179, 173}
    a.push(117); // その時点で下から順に {179, 173, 117}
    a.push(202); // その時点で下から順に {179, 173, 117, 202}
    int x2 = a.top();
    a.pop(); // その時点で下から順に {179, 173, 117}
    int x3 = a.top();
    int x4 = a.size();
    int x5 = 0; if (a.empty()) x5 = 10000;

    cout << x1 << " " << x2 << " "<< x3 << " " << x4 << " " << x5 << endl;
    return 0;
}

int testVector() {
    // 例 1: a に色々な操作を行う（x1 = 105, x2 = 2, x3 = 146 となります）
    vector<int> a; // その時点で a は空
    a.push_back(121); // その時点で a = {121}
    a.push_back(105); // その時点で a = {121, 105}
    a.push_back(193); // その時点で a = {121, 105, 193}
    int x1 = a[1];
    a.pop_back(); // その時点で a = {121, 105}
    int x2 = a.size();
    a.push_back(146); // その時点で a = {121, 105, 146}
    int x3 = a[2];
    cout << x1 << " " << x2 << " " << x3 << endl;
    return 0;
}

void testSort() {
    // 例 1: 配列 a の 1～4 番目を大きい順に並び替えます。{8, 7, 4, 3, 1, 6, 2, 5} に変化。
    int a[8] = {8, 3, 7, 1, 4, 6, 2, 5};
    sort(a + 1, a + 5, greater<int>());
    for (int i = 0; i < 8; i++) cout << a[i] << " ";
    cout << endl;

    // 例 2: {b[0], b[1], ..., b[N-1]} を入力し、小さい順に並び替えて出力します。
    int N, b[100009];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> b[i];
    sort(b, b + N);
    for (int i = 0; i < N; i++) cout << b[i] << " ";
    cout << endl;
    return;
}

void testReverse() {
    // 例 1: 配列 a の 2～6 番目の要素を逆順にします。{8, 3, 2, 6, 4, 1, 7, 5} に変化します。
    int a[8] = {8, 3, 7, 1, 4, 6, 2, 5};
    reverse(a + 2, a + 7);
    for (int i = 0; i < 8; i++) cout << a[i] << " ";
    cout << endl;

    // 例 2: {b[0], b[1], ..., b[N-1]} を入力し、逆順にしたうえで出力します。
    int N, b[1009];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> b[i];
    reverse(b, b + N);
    for (int i = 0; i < N; i++) cout << b[i] << " ";
    cout << endl;
    return;
}

void testTime() {
    // 例 1: 実行にかかる時間を計測する
    int ti = clock();
    for (int i = 1; i <= 100000; i++) cout << i << endl;
    printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return;
}

void testGCD() {
    // 例 1: 2 つの整数 a, b を入力し、a と b の最大公約数と最小公倍数を出力する
    int a, b;
    cin >> a >> b;
    cout << __gcd(a, b) << endl;
    cout << a / __gcd(a, b) * b << endl;
    return;
}

void testabs() {
    long long a, b;
    cin >> a >> b;
    printf("%lld\n", abs(a - b));
    return;
}

void testsincostan() {
    double pi = 3.141592653589793238;
    double x;
    cin >> x;
    printf("%.12lf\n", sin(x / 180.0 * pi));
    printf("%.12lf\n", cos(x / 180.0 * pi));
    printf("%.12lf\n", tan(x / 180.0 * pi));
    return;
}

void testMinMax() {
    // 例 1: 103, 168, 103 の中で最も大きい値を出力する : 168 が出力される
    cout << max({103, 168, 103}) << endl;

    // 例 2: {c[1], c[2], ..., c[N]} の最小値を出力する方法 1 つ目
    int N, c[100009], minx = 2147483647;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> c[i];
    for (int i = 1; i <= N; i++) minx = min(minx, c[i]);
    cout << minx << endl;

    // 例 3: {c[1], c[2], ..., c[N]} の最小値を出力する方法 2 つ目
    cout << *min_element(c + 1, c + N + 1) << endl;
    return;
}

void testSwap() {
    // 例 1: 2 つの変数 a, b を入れ替え、出力する
    int a, b;
    cin >> a >> b;
    swap(a, b);
    cout << a << " " << b << endl;

    // 例 2: バブルソートによって、{c[1], c[2], ..., c[N]} を小さい順に並び替え、出力する
    int N, c[1009];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> c[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++) {
            if (c[j] > c[j + 1]) swap(c[j], c[j + 1]);
        }
    }
    for (int i = 1; i <= N; i++) cout << c[i] << endl;
    return;
}
