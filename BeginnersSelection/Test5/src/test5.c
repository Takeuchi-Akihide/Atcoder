#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INT     5
#define A_YEN       500
#define B_YEN       100
#define C_YEN       50

// #define DEBUG

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
    // int result[n];

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
    int ia, ib, ic;
    int count = 0;
    int sum;

    /* Aの取得 */
    int A_500 = 0;
    if (getNumbers(1, 50, 0, &A_500) == false) {
        return 1;
    }

    /* Bの取得 */
    int B_100 = 0;
    if (getNumbers(1, 50, 0, &B_100) == false) {
        return 1;
    }

    /* Cの取得 */
    int C_50 = 0;
    if (getNumbers(1, 50, 0, &C_50) == false) {
        return 1;
    }

    /* Xの取得 */
    int X = 0;
    if (getNumbers(1, 20000, 50, &X) == false) {
        return 1;
    }
    if (X % 50 != 0) {
        print_err("X is 50n");
        return false;
    }
    int a_yen = A_YEN/C_YEN;
    int b_yen = B_YEN/C_YEN;
    int c_yen = C_YEN/C_YEN;
    X = X/C_YEN;

    for (ia=0; ia<=A_500; ia++) {
        for (ib=0; ib<=B_100; ib++) {
            for (ic=0; ic<=C_50; ic++) {
                sum = ia * a_yen + ib * b_yen + ic * c_yen;
                if (sum == X) { 
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);
    return 0;
}