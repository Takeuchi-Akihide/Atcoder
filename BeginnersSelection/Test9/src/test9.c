#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_INT     8
#define MAX_Y       20000000
#define MAX_N       100

#define X_YEN       10000
#define Y_YEN       5000
#define Z_YEN       1000
#define MIN_YEN     1000

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
    int ix, iy, iz;
    bool isFind = false;
    int sum;

    /* N,Yの取得 */
    int NY[2];
    if (getNumbers(2, MAX_Y, 1, NY) == false) {
        return 1;
    }

    int N = NY[0];
    if (N > 2000) {
        print_err("N is big or small");
    }

    int Y = NY[1];
    if (1000 > Y || Y % 1000 != 0) {
        print_err("Y is not right");
    }

    int y_divided = Y / MIN_YEN;
    int x_yen = X_YEN/MIN_YEN;
    int y_yen = Y_YEN/MIN_YEN;
    int z_yen = Z_YEN/MIN_YEN;
    
    for (ix=0; ix<=N && !isFind; ix++) {
        for (iy=0; iy<=N-ix && !isFind; iy++) {
            iz = N - ix - iy;
            sum = ix * x_yen + iy * y_yen + iz * z_yen;
            if (sum == y_divided) {
                isFind = true;
            }
        }
    }

    if (isFind == false) {
        ix = 0;
        iy = 0;
        iz = -1;
    }

    printf("%d %d %d\n", ix-1, iy-1, iz);
    return 0;
}