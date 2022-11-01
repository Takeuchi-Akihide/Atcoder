#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INT     19
#define MAX_ABC     5000
#define MAX_XY      100000

#define DEBUG

int getDigit(long long unsigned int num);
long long unsigned int StrToInt(char* str, int num);
int getNumbers(int n, int max, int min, int *result);
int getCharacters(int max, char *result);
void print_err(char *ms);

void print_err(char *ms) {
#if defined DEBUG
    printf("ERROR  %s!!!\n", ms);
#endif
}

int getDigit(long long unsigned int num) {
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
            return false;
        }
    }
    result[count] = '\0'; 
    return true;
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

long long unsigned int StrToInt(char* str, int num) {
    int i;
    long long unsigned int n = 0;
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

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}


int main (int argc, char *argv[]) {
    int ia, ib, iab;
    long long unsigned int sum = 0;

    /* A-C, X,Yの取得 */
    int ABCXY[5];
    if (getNumbers(5, MAX_XY, 1, ABCXY) == false) {
        return 1;
    }
    int A = ABCXY[0];
    int B = ABCXY[1];
    int AB = ABCXY[2];
    int X = ABCXY[3];
    int Y = ABCXY[4];
    int bigXY = max(X, Y);
    long long unsigned int min = AB * bigXY * 2;

    for (iab=0; iab<=bigXY; iab++) {    // ABピザを買う枚数(の半分)
        ia = X - iab;                   // Aピザを買う枚数
        ib = Y - iab;                   // Bピザを買う枚数
        sum = 0;
        sum += iab * AB * 2;
        if (ib >= 0) {
            sum += ib * B;
        }
        if (ia >= 0) {
            sum += ia * A;
        }
        if (min > sum) {
            min = sum;
        }
    }

    printf("%llu\n", min);
    return 0;
}
