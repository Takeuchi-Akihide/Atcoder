#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_INT     10
#define MAX_N       1000000000

#define DEBUG

int getDigit(int num);
int StrToInt(char* str, int num);
int getNumbers(int n, int max, int min, unsigned long long int *result);
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
int getNumbers(int n, int max, int min, unsigned long long int *result) {
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

unsigned long long int mgc(unsigned long long int a, unsigned long long int b);
unsigned long long int mgc(unsigned long long int a, unsigned long long int b) {
    unsigned long long int r, tmp, x;
    x = a * b;

    /* 自然数 a > b を確認・入替 */
    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }

    /* ユークリッドの互除法 */
    r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }

    return x / b;
}

int main (int argc, char *argv[]) {

    /* NABの取得 */
    unsigned long long int NAB[3];
    if (getNumbers(3, MAX_N, 3, NAB) == false) {
        return 1;
    }

    /* 総和を算出 */
    unsigned long long int sum;
    sum = NAB[0] * (NAB[0] + 1) / 2;
    // printf("sum: %lld\n", sum);

    /* Aの倍数の総和を算出 */
    unsigned long long int max_A, max_B, max_AB;
    unsigned long long int sum_A, sum_B, sum_AB;
    max_A = NAB[0]/ NAB[1];
    sum_A =  max_A * (max_A + 1) / 2 * NAB[1];
    // printf("sum_A: %lld\n", sum_A);
    
    /* Bの倍数の総和を算出 */
    max_B = NAB[0]/ NAB[2];
    sum_B =  max_B * (max_B + 1) / 2 * NAB[2];
    // printf("sum_B: %lld\n", sum_B);

    /* AとBの最小公倍数を算出 */
    unsigned long long int AandB;
    AandB = mgc(NAB[1], NAB[2]);
    max_AB = NAB[0]/ AandB;
    sum_AB =  max_AB * (max_AB + 1) / 2 * AandB;
    // printf("sum_AB: %lld\n", sum_AB);

    unsigned long long int result;
    result = sum - (sum_A + sum_B - sum_AB);

    printf("%llu\n", result);
    return 0;
}
