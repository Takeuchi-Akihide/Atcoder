#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       1005
#define MAX_K       100005

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

void push(int x, int *heap, int *sz) {
    int i = *sz++;
    while(i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= x) break;
        heap[i] = heap[p];
        p = i;
    }
    heap[i] = x;
}

int pop(int *heap, int *sz) {
    int ret = heap[0];
    int x = heap[--(*sz)];
    int i = 0;
    while (i*2+1 < *sz) {
        int a = i * 2 + 1;
        int b = i * 2 + 2;
        if (b < *sz && heap[b] < heap[a]) {
            a = b;
        }
        if (heap[a] >= x) break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
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

enum {
    J = 0,
    O,
    I,
    MAX_JOI,
};

int map[MAX_N][MAX_N];
long long sumJOI[MAX_N][MAX_N][MAX_JOI];
long long sumRow[MAX_N][MAX_N][MAX_JOI];
long long ans[MAX_K][MAX_JOI];

int main (int argc, char *argv[]) {
    int i, j, k;

    /* Nの取得 */
    long long Input1[2];
    getNumbers(2, MAX_N, 1, Input1);
    int M = (int)Input1[0];
    int N = (int)Input1[1];
    long long K;
    getNumbers(1, MAX_K, 1, &K);

    char ch;
    for (i=1; i<=M; i++) {
        for (j=1; j<=N; j++) {
            ch = getchar();
            switch (ch)
            {
            case 'J':
                map[i][j] = J;
                break;
            case 'O':
                map[i][j] = O;
                break;
            case 'I':
                map[i][j] = I;
                break;            
            default:
                break;
            }
        }
        ch = getchar();
    }

    for (i=1; i<=M; i++) {
        for (j=1; j<=N; j++) {
            for (k=0; k<MAX_JOI; k++) {
                sumRow[i][j][k] = sumRow[i][j-1][k] + (map[i][j] == k);
            }
        }
    }
    for (i=1; i<=M; i++) {
        for (j=1; j<=N; j++) {
            for (k=0; k<MAX_JOI; k++) {
                sumJOI[i][j][k] = sumJOI[i-1][j][k] + sumRow[i][j][k];
            }
        }
    }

    for (i=0; i<K; i++) {
        long long Input2[4];
        getNumbers(4, MAX_N, 1, Input2);
        int s_m = (int)Input2[0];
        int s_n = (int)Input2[1];
        int g_m = (int)Input2[2];
        int g_n = (int)Input2[3];

        for (j=0; j<MAX_JOI; j++) {
            ans[i][j] = sumJOI[g_m][g_n][j] - sumJOI[s_m-1][g_n][j] - sumJOI[g_m][s_n-1][j] + sumJOI[s_m-1][s_n-1][j]; 
        }
    }

    for (i=0; i<K; i++) {
        printf("%lld %lld %lld\n", ans[i][J], ans[i][O], ans[i][I]);
    }

    return 0;
}
