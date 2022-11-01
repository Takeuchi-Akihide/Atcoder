#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       200000

#define DEBUG

int getDigit(int num);
int StrToInt(char* str, int num);
int getNumbers(int n, int max, int min, int *result);
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
int getNumbers(int n, int max, int min, int *result) {
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

int main (int argc, char *argv[]) {
    int i, j, k;
    int count = 0;
    int result = 0;
    int p = 1;
    int q;

    /* Nの取得 */
    int N;
    if (getNumbers(1, MAX_N, 1, &N) == false) {
        return 1;
    }

    for (i=1; i<=N; i++) {
        /* iを平方数で割っていき、平方数に含まれない値を算出する(=p) */
        q = (int) sqrt(i);
        while(q >= 2) {
            if (i % (q*q) == 0) {
                break;
            }
            q--;
        }

        p = i / (q*q);

        /* N以下の数のうち、p*平方数であるものの数をcountに追加する */
        count += (int) sqrt((int) N/p);

    }

    printf("%d\n", count);
    return 0;
}
