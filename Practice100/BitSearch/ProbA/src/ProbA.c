#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       20
#define MAX_Q       200
#define MAX_A       2000

#define DEBUG

long long A[MAX_N];
long long m[MAX_Q];

void print_err(char *ms);
int getDigit(long long num);
int getNumbers(int n, int max, int min, long long *result);
int getCharacters(int max, char *result);
int cmpnum(const void * n1, const void * n2);
long long StrToInt(char* str, long long num);

void print_err(char *ms) {
#if defined DEBUG
    printf("ERROR  %s!!!\n", ms);
#endif
}

int getDigit(long long num) {
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
int getNumbers(int n, int max, int min, long long *result) {
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


/* 昇順に並び替え */
int cmpnum(const void * n1, const void * n2)
{
	if (*(int *)n1 > *(int *)n2)
	{
		return 1;
	}
	else if (*(int *)n1 < *(int *)n2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
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

long long StrToInt(char* str, long long num) {
    long long i;
    long long n = 0;
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

long long checkGCD(long long a, long long b);
long long checkGCD(long long a, long long b) {
    long long r, tmp;
    
    /* 自然数 a > b を確認・入替 */
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    
    /* ユークリッドの互除法 */
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}


int main (int argc, char *argv[]) {
    int i;
    bool isFind;
    int bit, _bit;
    long long sum = 0;
    int nowBit;

    /* Nの取得 */
    long long n;
    if (getNumbers(1, MAX_N, 1, &n) == false) {
        return 1;
    }

    if (getNumbers(n, MAX_A, 1, A) == false) {
        return 1;
    }

    /* Qの取得 */
    long long q;
    if (getNumbers(1, MAX_N, 1, &q) == false) {
        return 1;
    }

    if (getNumbers(q, MAX_A, 1, m) == false) {
        return 1;
    }

    for (i=0; i<q; i++) {
        isFind = false;
        bit = 0;
        while(isFind == false) {
            nowBit = 0;
            sum = 0;
            bit++;
            _bit = bit;
            // printf("bit: %d\n", bit);
            while (_bit) {
                // printf("_bit: %d\n", _bit);
                if (_bit & 0x01 == 1) {
                    sum += A[nowBit];
                }
                nowBit++;
                _bit >>= 1;
            }
            // printf("sum: %lld\n", sum);
            if (sum == m[i]) {
                printf("yes\n");
                isFind = true;
                break;
            }
            if ((bit == pow(2, n) - 1) && isFind == false) {
                printf("no\n");
                break;
            }
        }
    }
    return 0;
}
