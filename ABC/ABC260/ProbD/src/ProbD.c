#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       200005
#define MAX_A       pow(10, 9)

// #define DEBUG

int get1Number(int max, int min, long long *result);
void print_err(char *ms);
int getDigit(long long num);
int getNumbers(int n, int max, int min, long long *result);
int getCharacters(int max, char *result);
int cmpnum(const void * n1, const void * n2);
long long StrToInt(char* str, long long num);
long long binarySearchNum(long long x, long long *array, long long n);
long long checkGCD(long long a, long long b);
int getMin (int a, int b);

void print_err(char *ms) {
#if defined DEBUG
    printf("ERROR  %s!!!\n", ms);
#endif
}

/* 標準入力から、空白/改行が来るまで整数1つを読み取る */
int get1Number(int max, int min, long long *result) {
    int num_count = 0;
    char ch;
    char buf[MAX_INT+1] = "";

    while ((ch = getchar()) != ' ') {
        if (ch == '\n') {
            break;
        }
        buf[num_count] = ch;
        num_count++;
        if (num_count > MAX_INT) {   /* 数字の桁数がmax_intを超えたらエラー */
            print_err("Maxint Over");
        }
    }
    
    *result = StrToInt(buf, num_count);
    if (*result < min || *result > max) {
        print_err("Num big or small");
    }
    return true;
}

int getDigit(long long num) {
    if (num == 0) {
        return 1;
    }
    
    int digit = 0;
    while (num > 0) {
        num /= 10;
        digit++;
    }
    return digit;
}

/* 標準入力から空白を挟んでn個の整数を受け取り、配列に入れて返す */
int getNumbers(int n, int max, int min, long long *result) {
    int count = 0;
    int num_count = 0;
    char ch;
    char buf[MAX_INT+1] = "";

    while ((ch = getchar())) {
        if (ch == ' ' || ch == '\n') {
            if (buf[0] != '\0') {
                result[count] = StrToInt(buf, num_count);
                if (result[count] < min || result[count] > max) {
                    print_err("Num big or small");
                }
                count++;
                if (count > n) {       /* 標準入力に記載された整数がn個を超えたらエラー */
                    print_err("Num Count Over");
                }
                num_count = 0;
            }
            if (ch == ' ') {          
                continue;
            } else {
                break;
            }
        }

        buf[num_count] = ch;
        num_count++;
        if (num_count > MAX_INT) {   /* 数字の桁数がmax_intを超えたらエラー */
            print_err("Maxint Over");
        }
    }

    if (count != n) {
        print_err("count != n");
        // printf("count:%d, n:%d\n", count, n);
    }
    return true;
}


/* 昇順に並び替え */
int cmpnum(const void * n1, const void * n2)
{
	if (*(long long *)n1 > *(long long *)n2)
	{
		return 1;
	}
	else if (*(long long *)n1 < *(long long *)n2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

/* 標準入力から受け取った文字列を配列に入れて返す */
int getCharacters(int max, char *result) {
    int count = 0;
    char ch;

    while ((ch = getchar()) != '\n') {
        if (ch == ' ') {
            continue;
        }
        result[count] = ch;
        count++;
        if (count >= max) {
            print_err("too much S");
        }
    }
    result[count] = '\0'; 
    return true;
}

int getMin (int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

long long StrToInt(char* str, long long num) {
    long long i;
    long long n = 0;
    bool isMinus = false;
    for (i=0; i<num; i++) {
        if (i == 0 && str[i] == '-') {
            isMinus = true;
        }
        else if (isdigit(str[i])) {
            n = n * 10 + (str[i] - '0');
        } else {
            print_err("Input Number");
        }
    }
    if (isMinus) {
        n *= -1;
    }
    return n;
}

long long checkGCD(long long a, long long b) {
    long long r, tmp;
    
    /* 自然数 a > b を確認・入替 */
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    
    /* ユークリッドの互除法 */
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

/* array[i-1]<x<=array[i] のとき、iを返す */
/* arrayは昇順に並べ替えておく */
long long binarySearchNum(long long x, long long *array, long long n) {
    long long min = 0;
    long long max = n;
    long long mid;
    while (min <= max) {
        mid = (min + max) / 2;
        if (mid == 0 && x <= array[mid]) {
            return mid;
        } else if 
            ((mid == n-1 && array[mid] < x) ||
             (array[mid] < x && x <= array[mid+1])) {
            return mid + 1;
        } else if (array[mid] < x) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
}

typedef struct {
    int n;
    int P;
    int nextN;
    int beforeN;
    int fudaN;
    bool isTop;
    int turn;
} _Fuda;        /* 整数nが書かれたカードの情報 */

int ba[MAX_N][MAX_N];
int omote[MAX_N];

int main (int argc, char *argv[]) {
    int i, j;

    /* Nの取得 */
    long long Input1[2];
    getNumbers(2, MAX_N, 1, Input1);

    int N = (int)Input1[0];
    int K = (int)Input1[1];

    /* A,Bの取得 */
    long long P[MAX_N];
    _Fuda fuda[MAX_N];
    for (i=0; i<N; i++) {
        get1Number(MAX_N, 1, &P[i]);
        fuda[P[i]].n = i + 1;
        fuda[P[i]].fudaN = 0;
        fuda[P[i]].isTop = false;
        fuda[P[i]].nextN = 0;
        fuda[P[i]].beforeN = 0;
        fuda[P[i]].turn = -1;
    }


    for (i=0; i<N; i++) {    
        int before = tansaku(P[i]);
        if (before != 0) {
            
        }

    }

    int before;
    for (i=0; i<N; i++) {
        // 見えているもののうち、P[i]以上の最小値を探す
        isfound = false;
        printf("isTop: ");
        for (j=1; j<=N; j++) {
            printf("%d ", fuda[j].isTop);
        }
        printf("\nnextN: ");
        for (j=1; j<=N; j++) {
            printf("%d ", fuda[j].nextN);
        }
        printf("\n");
        for (j=P[i]+1; j<=N; j++) {
            if (fuda[j].isTop == true) {
                before = j;
                isfound = true;
                break;
            }
        }
        if (isfound) {
            fuda[before].nextN = P[i] + 1;
            fuda[before].isTop = false;
            fuda[P[i]].isTop = true;
            fuda[P[i]].fudaN = fuda[before].fudaN + 1;
            fuda[P[i]].beforeN = before;
        } else {
            fuda[P[i]].isTop = true;
            fuda[P[i]].fudaN = 1;
            fuda[P[i]].beforeN = 0;
        }
        if (fuda[P[i]].fudaN == K) {
            fuda[P[i]].isTop = false;
            fuda[P[i]].turn = i;
            before = fuda[P[i]].beforeN;
            while(before != 0) {
                fuda[before].turn = i;
                before = fuda[before].beforeN;
                printf("P[i]:%lld before:%d\n", P[i], before);
            }
        }
    }
    for (i=0; i<N; i++) {
        printf("%d\n", fuda[i].turn);
    }   

    return 0;
}
