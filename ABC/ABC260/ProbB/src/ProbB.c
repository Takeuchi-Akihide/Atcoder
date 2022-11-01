#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       1005
#define MAX_A       100

// #define DEBUG

typedef struct {
    long long Math;
    long long English;
    long long sum;
    int n;
    int mathNum;
    int engNum;
    int sumNum;
    bool isPath;
} _Score;

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


/* 降順に並び替え */
int cmpnumMath(const void * n1, const void * n2)
{
	if ((*(_Score *)n1).Math > (*(_Score *)n2).Math)
	{
		return -1;
	}
	else if ((*(_Score *)n1).Math < (*(_Score *)n2).Math)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* 英語降順に並び替え */
int cmpnumEnglish(const void * n1, const void * n2)
{
	if ((*(_Score *)n1).English > (*(_Score *)n2).English)
	{
		return -1;
	}
	else if ((*(_Score *)n1).English < (*(_Score *)n2).English)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/* 合計降順に並び替え */
int cmpnumSum(const void * n1, const void * n2)
{
	if ((*(_Score *)n1).sum > (*(_Score *)n2).sum)
	{
		return -1;
	}
	else if ((*(_Score *)n1).sum < (*(_Score *)n2).sum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/* 番号昇順に並び替え */
int cmpnum(const void * n1, const void * n2)
{
	if ((*(_Score *)n1).n > (*(_Score *)n2).n)
	{
		return 1;
	}
	else if ((*(_Score *)n1).n < (*(_Score *)n2).n)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
/* 昇順に並び替え */
int cmpnumF(const void * n1, const void * n2)
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


int main (int argc, char *argv[]) {
    int i, j;

    /* Nの取得 */
    long long Input1[4];
    getNumbers(4, MAX_N, 0, Input1);

    int N = (int)Input1[0];
    int X = (int)Input1[1];
    int Y = (int)Input1[2];
    int Z = (int)Input1[3];

    /* A,Bの取得 */
    // long long A[MAX_N], B[MAX_N];
    _Score scores[MAX_N];
    for (i=0; i<N; i++) {
        get1Number(MAX_A, 0, &scores[i].Math);
        scores[i].n = i + 1;
        scores[i].mathNum = 0;
        scores[i].engNum = 0;
        scores[i].sumNum = 0;
        scores[i].isPath = false;
    }
    for (i=0; i<N; i++) {
        get1Number(MAX_A, 0, &scores[i].English);
        scores[i].sum = scores[i].Math + scores[i].English;
    }

    int passNum = 1;
    int same[MAX_N];
    for (i=0; i<N; i++) {
        same[i] = 0;
    }

    qsort(scores, N, sizeof(_Score), cmpnum);
    qsort(scores, N, sizeof(_Score), cmpnumMath);
    for (i=0; i<N; i++) {
        if (passNum <= X) {
            scores[i].isPath = true;
            passNum++;
        }
    }
    passNum = 1;
    qsort(scores, N, sizeof(_Score), cmpnum);
    qsort(scores, N, sizeof(_Score), cmpnumEnglish);
    for (i=0; i<N; i++) {

        if (passNum <= Y && scores[i].isPath == false) {
            scores[i].isPath = true;
            passNum++;
        }
    }
    passNum = 1;
    qsort(scores, N, sizeof(_Score), cmpnum);
    qsort(scores, N, sizeof(_Score), cmpnumSum);
    for (i=0; i<N; i++) {
        scores[i].sumNum = i + 1;
        if (passNum <= Z && scores[i].isPath == false) {
            scores[i].isPath = true;
            passNum++;
        }
    }
    qsort(scores, N, sizeof(_Score), cmpnum);

    for (i=0; i<N; i++) {
        if (scores[i].isPath) {
            printf("%d\n", scores[i].n);
        }
    }
    return 0;
}
