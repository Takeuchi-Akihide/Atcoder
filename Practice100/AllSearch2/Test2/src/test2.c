#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INT     30000
#define MAX_N       30000

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


int main (int argc, char *argv[]) {
    int i, j;
    int rank[3];
    int count = 0;

    /* Nの取得 */
    int N;
    if (getNumbers(1, MAX_N, 4, &N) == false) {
        return 1;
    }

    /* Sの取得 */
    char S[MAX_INT+1];
    if (getCharacters(MAX_INT+1, S) == false) {
        return 1;
    }

    for (i=0; i<1000; i++) {
        rank[2] = i / 100;
        rank[1] = (i - rank[2]*100) / 10;
        rank[0] = i - (rank[2]*100 + rank[1]*10);
        int rankNum = 2;
        for (j=0; j<N; j++) {
            if (S[j] == rank[rankNum] + '0') {
                if (rankNum == 0) {
                    count++;
                    break;
                }
                rankNum--;
            }
        }
    }
    
    printf("%d\n", count);
    return 0;
}


