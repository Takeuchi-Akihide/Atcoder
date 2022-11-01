#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       1000
#define HASH        10007

// #define DEBUG

void print_err(char *ms);
int getNumbers(int n, int max, int min, long long *result);
long long StrToInt(char* str, long long num);

void print_err(char *ms) {
#if defined DEBUG
    printf("ERROR  %s!!!\n", ms);
#endif
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


enum {
    JOI_J = 0,
    JOI_O,
    JOI_I,
    JOI_MAX,
};

int main (int argc, char *argv[]) {
    int i, j, k;

    /* Nの取得 */
    long long Input1;
    getNumbers(1, MAX_N, 1, &Input1);
    int N = (int)Input1;

    /* A,Bの取得 */
    int KeyP[MAX_N];
    char ch;
    for (i=0; i<N; i++) {
        ch = getchar();
        switch (ch)
        {
        case 'J':
            KeyP[i] = JOI_J;
            break;
        case 'O':
            KeyP[i] = JOI_O;
            break;
        case 'I':
            KeyP[i] = JOI_I;
            break;        
        default:
            break;
        }
    }
    while((ch = getchar()) != '\n');

    int dp[MAX_N][1<<JOI_MAX] = {0};
    for (i=1; i<(1<<JOI_MAX); i++) {
        if ((i & (1<<JOI_J)) && (i & (1<<KeyP[0]))) {
            dp[0][i] = 1;
        }
    }
    for (i=1; i<N; i++) {
        for (j=1; j<(1<<JOI_MAX); j++) {
            if ((j & (1<<KeyP[i])) == 0) {
                dp[i][j] = 0;
                continue;
            }
            for (k=1; k<(1<<JOI_MAX); k++) {
                if ((j & k) != 0) {
                    dp[i][j] += dp[i-1][k];
                }
            }
            dp[i][j] %= HASH;
        }
    }
    // for (i=0; i<N; i++) {
    //     printf("[%d]  ", i+1);
    //     for (j=0; j<(1<<JOI_MAX); j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    int res = 0;
    for (i=0; i<(1<<JOI_MAX); i++) {
        res += dp[N-1][i];
    }
    res %= HASH;
    

    printf("%d\n", res);
    return 0;
}
