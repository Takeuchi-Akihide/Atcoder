#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       105
#define MAX_A       pow(10, 9)

// #define DEBUG

typedef struct Data {
    long long A;
    long long B;
} _Data;

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
	if (((_Data *)n1)->A > ((_Data *)n2)->A)
	{
		return 1;
	}
	else if (((_Data *)n1)->A < ((_Data *)n2)->A)
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

int main (int argc, char *argv[]) {
    int i, j, k;

    /* Nの取得 */
    long long Input1[2];
    getNumbers(2, MAX_N, 1, Input1);

    long long N = Input1[0];
    long long K = Input1[1];

    /* A,Bの取得 */
    long long dp[MAX_N][4][4] = {0};
    long long sum[MAX_N] = {0};
    _Data data[MAX_N];
    // long long A[MAX_N], B[MAX_N];
    for (i=0; i<K; i++) {
        get1Number(N, 1, &data[i].A);
        get1Number(3, 1, &data[i].B);
    }

    qsort(data, K, sizeof(_Data), cmpnum);

    int inum[4];
    int count = 0;
    if (data[count].A == 1) {
        dp[1][data[count].B][data[count].B/3+1] = 1;
        count++;
    } else {
        for (i=1; i<=3; i++) {
            dp[1][i][i%3+1] = 1;
        }
    }
    for (i=2; i<=N; i++) {
        inum[1] = dp[i-1][1][1] + dp[i-1][1][2] + dp[i-1][1][3];
        inum[2] = dp[i-1][2][1] + dp[i-1][2][2] + dp[i-1][2][3];
        inum[3] = dp[i-1][3][1] + dp[i-1][3][2] + dp[i-1][3][3];
        if (data[count].A == i) {
            for (k=1; k<=3; k++) {
                if (data[count].B == k) {
                    dp[i][data[count].B][k] = inum[data[count].B] - dp[i-1][k][k];
                } else {
                    dp[i][data[count].B][k] = inum[k];                  
                }
                dp[i][data[count].B][k] %= 10000;
                sum[i] += dp[i][data[count].B][k];
                sum[i] %= 10000;
            }
            count++;
        } else {
            for (j=1; j<=3; j++) {
                for (k=1; k<=3; k++) {
                    if (j == k) {
                        dp[i][j][k] = inum[j] - dp[i-1][k][k];
                    } else {
                        dp[i][j][k] = inum[k];                        
                    }
                    dp[i][j][k] %= 10000;
                    sum[i] += dp[i][j][k];
                    sum[i] %= 10000;
                }
            }
        }
    }
    // for (i=1; i<=N; i++) {
    //     printf("%d: ", i);
    //     for (j=1; j<=3; j++) {
    //         for (k=1; k<=3; k++) {
    //             printf("[%d %d]=%lld ", j, k, dp[i][j][k]);
    //         }
    //     }
    //     printf("\n");
    // }

    printf("%lld\n", sum[N]%10000);
    return 0;
}
