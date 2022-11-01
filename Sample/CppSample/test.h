#ifndef TEST_H_
#define TEST_H_


void testMinMax();      /* min/max */
void testabs();         /* abs */
void testsincostan();   /* sin/cos/tan */
void testSwap();        /* swap */
void testGCD();         /* 最大公約数 */
void testTime();        /* 時間計測 */
void testReverse();     /* 配列を逆向きにする */
void testSort();        /* 配列をsort */
int testVector();       /* 動的配列。詳細な具体例はAdvanced/Day4 */
int testStack();        /* stack */
int testQueue();        /* queue */
int testPriorityQueue();/* 昇順/降順にできるqueue */
int testMap();          /* key-value型の動的配列。詳細な具体例はAdvanced/Day5 */
int testLower_bound();  /* 二分探索 */
int testSet();          /* 同じ値を1つだけとれる動的配列。詳細な具体例はAdvanced/Day5 */
int testPair();         /* 2つの要素をペアとする配列。 */
int testTuple();        /* 好きな数の要素をペアとする配列。 */
int testAssert();       /* 条件を満たさないときにアサートを出す */
int testCount();        /* a[l], a[l+1], ..., a[r-1] の中で、x となるようなものの個数を整数型で返す */
int testFind();         /* a[l], a[l+1], ..., a[r] の中で x が存在する場所を返す */
int testNext_permutation(); /* 次の順列を生成する */
int testBuiltin_popcountll();   /* bitが1となる個数を返す */
int testBitset();       /* bit演算を扱うときに用いる */
 

#endif /* TEST_H_ */
