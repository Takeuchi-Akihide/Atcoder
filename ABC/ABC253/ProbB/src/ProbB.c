#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_INT     3
#define MAX_HW      100

#define DEBUG

int getDigit(int num);
int StrToInt(char* str, int num);
int getNumbers(int n, int max, int min, int *result);
int getCharacters(int max, char *result);
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

int main (int argc, char *argv[]) {
    int ih, iw;
    int maru1[2];
    int maru2[2];
    bool isFind = false;

    /* H,Wの取得 */
    int HW[2];
    if (getNumbers(2, MAX_HW, 2, HW) == false) {
        return 1;
    }

    /* Siの取得 */
    char Si[MAX_HW+1][MAX_HW+1];
    for (ih=0; ih<HW[0]; ih++) {
        if (getCharacters(HW[1]+1, Si[ih]) == false) {
            return 1;
        }
    }

    for (ih=0; ih<HW[0]; ih++) {
        for (iw=0; iw<HW[1]; iw++) {
            if (Si[ih][iw] == 'o') {
                if (isFind == false) {
                    maru1[0] = ih;
                    maru1[1] = iw;
                    isFind = true;
                } else {
                    maru2[0] = ih;
                    maru2[1] = iw;
                }
            }
        }
    }

    printf("%d\n", abs(maru1[0] - maru2[0]) + abs(maru1[1] - maru2[1]));
    return 0;
}

