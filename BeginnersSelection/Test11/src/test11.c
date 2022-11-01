#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_INT     6
#define MAX_TXY     100000
#define MAX_N       100000

#define DEBUG

int getDigit(int num);
int StrToInt(char* str, int num);
int getNumbers(int n, int max, int min, int *result);
void print_err(char *ms);
bool checkPlan(int *now, int *dest);

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

bool checkPlan(int *now, int *dest) {
    int t = dest[0] - now[0];
    int x = abs(dest[1] - now[1]);
    int y = abs(dest[2] - now[2]);

    int buf = t - (x + y);

    if ( (buf >= 0) && (buf % 2 == 0) && (t >= x) && (t >= y) ) {
        return true;
    } else {
        return false;
    }
}

int main (int argc, char *argv[]) {
    int i;
    int TXY[MAX_TXY+1][3];
    bool isMove = true;

    /* Nの取得 */
    int N;
    if (getNumbers(1, MAX_N, 1, &N) == false) {
        return 1;
    }

    /* T,X,Yの取得 */
    TXY[0][0] = 0;
    TXY[0][1] = 0;
    TXY[0][2] = 0;
    for (i=1; i<=N; i++) {
        if (getNumbers(3, MAX_TXY, 0, TXY[i]) == false) {
            return 1;
        }
    }

    for (i=0; i<N; i++) {
        if (checkPlan(TXY[i], TXY[i+1]) == false) {
            isMove = false;
            break;
        }
    }

    if (isMove == true) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

