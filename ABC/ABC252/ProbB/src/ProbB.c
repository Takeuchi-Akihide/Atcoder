#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_INT     3
#define MAX_NK      100

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
    int i;
    int max_A = 0;
    bool isEat = false;

    /* N,Kの取得 */
    int NK[2];
    if (getNumbers(2, MAX_NK, 1, NK) == false) {
        return 1;
    }

    /* Aの取得 */
    int A[MAX_NK] = {0};
    if (getNumbers(NK[0], MAX_NK, 1, A) == false) {
        return 1;
    }

    /* Bの取得 */
    int B[MAX_NK] = {0};
    if (getNumbers(NK[1], NK[0], 1, B) == false) {
        return 1;
    }

    /* Aの最大値を取得 */
    for (i=0; i<NK[0]; i++) {
        if (max_A < A[i]) {
            max_A = A[i];
        }
    }

    /* 嫌いな食品を食べる可能性を確認 */
    for (i=0; i<NK[1]; i++) {
        if (A[B[i]-1] == max_A) {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");
    return 0;
}

