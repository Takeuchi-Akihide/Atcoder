#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_INT     3
#define MAX_N       100

#define DEBUG

int getDigit(int num);
int StrToInt(char* str, int num);
int getNumbers(int n, int max, int min, int *result);
int getCharacters(int max, char *result);
int checkTime(char num, char S[][11], int N);
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

int checkTime(char num, char S[][11], int N) {
    int now = 0;
    int result = 0;
    int fCheck[MAX_N] = {0};
    int checkNum = 0;
    int i;

    while (1) {
        for (i=0; i<N; i++) {
            if (fCheck[i] == 1) {
                continue;
            }
            if (S[i][now] == num) {
                fCheck[i] = 1;
                checkNum++;
                break;
            }
        }
        if (checkNum == N) {
            // printf("num:%c, result:%d\n", num, result);
            break;
        } else {
            now++;
            result++;
            if (now >= 10) {
                now -= 10;
            }
        }
    }
    return result;
}

int main (int argc, char *argv[]) {
    int i;
    int minSec[10] = {0};

    /* Nの取得 */
    int N;
    if (getNumbers(1, MAX_N, 1, &N) == false) {
        return 1;
    }

    /* S_iの取得 */
    char S[MAX_N][11];
    for (i=0; i<N; i++) {
        if (getCharacters(11, S[i]) == false) {
            return 1;
        }
    }

    for (i=0; i<10; i++) {
        char i_c = i + '0';
        minSec[i] = checkTime(i_c, S, N);
    }

    int min = N * 10;
    for (i=0; i<10; i++) {
        if (min > minSec[i]) {
            min = minSec[i];
        }
    }

    printf("%d\n", min);
    return 0;
}

