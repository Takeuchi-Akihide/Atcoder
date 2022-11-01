#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       200000
#define MAX_A       pow(10, 9)

#define DEBUG


long long A[MAX_N] = {0};
long long B[MAX_N] = {0};
long long query[MAX_N][4];

int getDigit(int num);
int StrToInt(char* str, int num);
int getNumbers(int n, int max, int min, long long *result);
void print_err(char *ms);

void print_err(char *ms) {
#if defined DEBUG
    printf("ERROR  %s!!!\n", ms);
#endif
}

int getDigit(int num) {
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
    int max_digit = getDigit(max);

    while ((ch = getchar())) {
        if (ch == ' ' || ch == '\n') {
            if (buf[0] != '\0') {
                result[count] = StrToInt(buf, num_count);
                if (result[count] < min || result[count] > max) {
                    print_err("Num big or small");
                    return false;
                }
                count++;
                if (count > n) {       /* 標準入力に記載された整数がn個を超えたらエラー */
                    print_err("Num Count Over");
                    return false;
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
        if (num_count > max_digit) {   /* 数字の桁数がmax_intを超えたらエラー */
            print_err("Maxint Over");
            return false;
        }
    }

    if (count != n) {
        printf("count:%d, n:%d\n", count, n);
        print_err("count != n");
        return false;
    }
    return true;
}

int StrToInt(char* str, int num) {
    int i;
    int n = 0;
    for (i=0; i<num; i++) {
        if (isdigit(str[i])) {
            n = n * 10 + (str[i] - '0');
        } else {
            print_err("Input Number");
            break;
        }
    }
    return n;
}

long long checkGCD(long long a, long long b);
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


int main (int argc, char *argv[]) {
    int i;

    /* Nの取得 */
    long long NQ[2];
    if (getNumbers(2, MAX_N, 1, NQ) == false) {
        return 1;
    }

    int N = (int) NQ[0];
    int Q = (int) NQ[1];

    /* A,Bの取得 */
    if (getNumbers(N, MAX_A, 1, A) == false) {
        return 1;
    }
    if (getNumbers(N, MAX_A, 1, B) == false) {
        return 1;
    }

    /* クエリの取得 */
    for (i=0; i<Q; i++) {
        if (getNumbers(4, MAX_N, 1, query[i]) == false) {
            return 1;
        }
    }

    int h1, h2, w1, w2;
    int ih, iw;
    long long gcd, gcd1, gcd2 = 0;

    for (i=0; i<Q; i++) {
        h1 = query[i][0];
        h2 = query[i][1];
        w1 = query[i][2];
        w2 = query[i][3];
        gcd1 = A[h1-1] + B[w1-1];
        for (ih=h1-1; ih<h2; ih++) {
            gcd2 = A[ih] + B[w1-1];
            gcd = checkGCD(gcd1, gcd2);
            gcd1 = gcd;
            if (gcd1 == 1) {
                break;
            }
        }
        for (iw=w1; iw<w2; iw++) {
            gcd2 = A[h1-1] + B[iw];
            gcd = checkGCD(gcd1, gcd2);
            gcd1 = gcd;
            if (gcd1 == 1) {
                break;
            }
        }
        printf("%lld\n", gcd1);
    }
    return 0;
}
