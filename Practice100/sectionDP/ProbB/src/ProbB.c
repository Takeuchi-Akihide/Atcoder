#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       2000
#define MAX_A       pow(10, 9)
#define max(a, b)   ((a) > (b) ? (a) : (b))
#define min(a, b)   ((a) < (b) ? (a) : (b))

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


// int rec(int l, int r);
// int rec(int l, int r) {
//     if (dp[l][r] != -1) return dp[l][r];

//     if (abs(l - r) <= 1) return 0;

//     int res = 0;
//     if (llabs(w[l] - w[r-1]) <= 1 && rec(l+1, r-1) == r - l - 2) {
//         res = r - l;
//     }

//     for (int mid=l+1; mid<=r-1; mid++) {
//         res = max(res, rec(l, mid) + rec(mid, r));
//     }
//     dp[l][r] = res;
//     return res;
// }

int nextTo(int i, int N);
int nextTo(int i, int N) {
    if (i + 1 >= N) {
        return i + 1 - N;
    } else {
        return i + 1;
    }
}

int backTo(int i, int N);
int backTo(int i, int N) {
    if (i - 1 < 0) {
        return i - 1 + N;
    } else {
        return i - 1;
    }
}

long long dp[MAX_N][MAX_N];
int main (int argc, char *argv[]) {
    int i, j;

    /* Nの取得 */
    long long N;
    getNumbers(1, MAX_N, 1, &N);

    /* wの取得 */
    long long A[MAX_N];
    for (i=0; i<N; i++) {
        getNumbers(1, MAX_A, 1, &A[i]);
    }

    for (i=0; i<N; i++) {
        dp[i][i] = A[i];
        dp[i][nextTo(i, N)] = max(A[i], A[nextTo(i, N)]);
    }
    int l, r, m;
    for (i=2; i<N; i++) {
        for (l=0; l<N; l++) {
            r = l + i;
            if (r >= N) {
                r -= N;
            }
            long long tmp1, tmp2;
            // A[l]を選択した場合
            if (A[nextTo(l, N)] > A[r]) {
                tmp1 = A[l] + dp[nextTo(nextTo(l, N), N)][r];
            } else {
                tmp1 = A[l] + dp[nextTo(l, N)][backTo(r, N)];
            }
            // A[r]を選択した場合
            if (A[l] > A[backTo(r, N)]) {
                tmp2 = A[r] + dp[nextTo(l, N)][backTo(r, N)];
            } else {
                tmp2 = A[r] + dp[l][backTo(backTo(r, N), N)];
            }
            dp[l][r] = max(tmp1, tmp2);
        }
    }
    // for (i=0; i<=N; i++) {
    //     printf("[%d]: ", i);
    //     for (j=0; j<=N; j++) {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    long long maxN = 0;
    for (i=0; i<N; i++) {
        if (dp[i][backTo(i, N)] > maxN) {
            maxN = dp[i][backTo(i, N)];
        }
    }
    printf("%lld\n", maxN);
    return 0;
}
