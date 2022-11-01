#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NINT    3
#define MAX_N       200
#define MAX_AINT    9

#define DEBUG

int StrToInt(char* str, int num);
int getNumbers(int n, int max_int, int *result);
void print_err(char *ms);

void print_err(char *ms) {
#if defined DEBUG
    printf("ERROR  %s!!!\n", ms);
#endif
}

/* 標準入力から空白を挟んでn個の整数を受け取り、配列に入れて返す */
int getNumbers(int n, int max_int, int *result) {
    int count = 0;
    int num_count = 0;
    char ch;
    char buf[MAX_AINT+1] = "";
    // int result[n];

    while ((ch = getchar())) {
        if (ch == ' ' || ch == '\n') {
            if (buf[0] != '\0') {
                result[count] = StrToInt(buf, num_count);
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
        if (num_count > max_int) {   /* 数字の桁数がmax_intを超えたらエラー */
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

    /* Nの取得 */
    int n = 0;
    if (getNumbers(1, MAX_NINT, &n) == false) {
        return 1;
    }
    if (n < 1 || n > 200) {
        print_err("N is big or small");
        return 1;
    }

    /* Aの取得 */
    int a[MAX_N] = {0};
    if (!getNumbers(n, MAX_AINT, a)) {
        return 1;        
    }

    int isDivide = true;
    int divideCount = 0;
    while (1) {
        for (i=0; i<n; i++) {
            if (a[i] % 2 == 0) {
                a[i] >>= 1;
            } else {
                isDivide = false;
                break;
            }
        }
        if (isDivide == false) {
            break;
        }
        divideCount++;
    }

    printf("%d\n", divideCount);
    return 0;
}