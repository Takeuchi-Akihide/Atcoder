#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INT     19
#define MAX_T       10000
#define MAX_N       pow(10, 18)

// #define DEBUG

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

bool minus1char(char *beforeNum, int cyclicNum);
bool minus1char(char *beforeNum, int cyclicNum) {
    // printf("beforeNum:%s\n", beforeNum);
    int i;
    int digit = strlen(beforeNum);
    int amari;
    long long unsigned int num = StrToInt(beforeNum, cyclicNum) - 1;
    int digit2 = getDigit(num);
    // printf("digit:%d, digit2:%d\n", digit, digit2);
    if (digit2 != cyclicNum || num == 0) {
        return false;
    }
    for (i=digit2-1; i>=0; i--) {
        amari = num % 10;
        beforeNum[i] = amari + '0';
        num /= 10;
    }
    // printf("afterNum:%s\n", beforeNum);
    return true;
}

long long unsigned int calcMaxNum(char *num, int digit);
long long unsigned int calcMaxNum(char *num, int digit) {
    int i, j, k;
    long long unsigned int max = 0;
    int cycleTime;
    long long unsigned int choiceNum;
    long long unsigned int beforeNum = StrToInt(num, digit);
    char cyclicNum[MAX_INT+1] = "";
    char cyclicNum2[MAX_INT+1] = "";

    for (i=1; i<=digit/2; i++) {
        if (digit % i == 0) {
            cycleTime = digit / i;
            // printf("i:%d, cycleTime:%d\n", i, cycleTime);
            /* iごとの周期の場合の最大値を求める */
            for (k=0; k<cycleTime; k++) {
                for (j=0; j<i; j++) {
                    cyclicNum[j + k * i] = num[j];
                }
            }
            // printf("cyclicNum:%s\n", cyclicNum);
            cyclicNum[digit] = '\0';
            choiceNum = StrToInt(cyclicNum, digit);
            if (beforeNum >= choiceNum) {
                // printf("%d choiceNum:%llu\n", __LINE__, choiceNum);
                if (choiceNum > max) {
                    max = choiceNum;
                }
            } else {
                for (k=0; k<cycleTime; k++) {
                    if (minus1char(cyclicNum, i) == false) {
                        // printf("len_cyclicNum:%ld\n", strlen(cyclicNum));
                        for (j=0; j<digit-1; j++) {
                            cyclicNum2[j] = '9';
                        }
                        cyclicNum2[digit-1] = '\0';
                    } else {
                        for (k=0; k<cycleTime; k++) {
                            for (j=0; j<i; j++) {
                                cyclicNum2[j + k * i] = cyclicNum[j];
                            }
                        }
                        cyclicNum2[digit] = '\0';
                    }
                }
                choiceNum = StrToInt(cyclicNum2, digit);
                if (beforeNum >= choiceNum) {
                    // printf("%d choiceNum:%llu\n", __LINE__, choiceNum);
                    if (choiceNum > max) {
                        max = choiceNum;
                    }
                } 
            }
        }
    }
    return max;
}

int main (int argc, char *argv[]) {
    int i;
    int digit;
    long long unsigned int answer;

    /* Tの取得 */
    int T;
    if (getNumbers(1, MAX_T, 1, &T) == false) {
        return 1;
    }

    /* N[i]の取得 */
    char N[MAX_T][MAX_INT+1];
    for (i=0; i<T; i++){
        if (getCharacters(MAX_INT+1, N[i]) == false) {
            return 1;
        }
    }
    
    for (i=0; i<T; i++){
        digit = strlen(N[i]);
        answer = calcMaxNum(N[i], digit);
        printf("%llu\n", answer);
    }
    return 0;
}


