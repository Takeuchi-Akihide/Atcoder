/*  ProbD.c
 *  https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e
 *  第7回日本情報オリンピック予選
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_R       10
#define MAX_C       10000

#define DEBUG

void print_err(char *ms);
int getDigit(long long num);
int getNumbers(int n, int max, int min, long long *result);
int get1Number(int max, int min, long long *result);
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

/* 標準入力から、空白/改行が来るまで整数1つを読み取る */
int get1Number(int max, int min, long long *result) {
    int num_count = 0;
    char ch;
    char buf[MAX_INT+1] = "";
    int max_digit = getDigit(max);

    while ((ch = getchar()) != ' ') {
        if (ch == '\n') {
            break;
        }

        buf[num_count] = ch;
        num_count++;
        if (num_count > max_digit) {   /* 数字の桁数がmax_intを超えたらエラー */
            print_err("Maxint Over");
            return false;
        }
    }
    
    *result = StrToInt(buf, num_count);
    if (*result < min || *result > max) {
        print_err("Num big or small");
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
    int i, j;
    int ir;
    int count = 0;
    int sum = 0;
    int max = 0;

    /* R,Cの取得 */
    long long RC[2];
    if (getNumbers(2, MAX_C, 1, RC) == false) return 1;
    long long R = RC[0];
    long long C = RC[1];

    /* a_ijの取得 */
    long long a[MAX_R][MAX_C];
    for (i=0; i<R; i++) {
        if (getNumbers(C, 1, 0, a[i]) == false) return 1;
    }

    for (ir=0; ir<pow(2, R); ir++) {
        sum = 0;
        long long a_calc[MAX_R][MAX_C];
        for (i=0; i<R; i++) {
            if ((ir & (1 << i)) == 0) {
                for (j=0; j<C; j++) {
                    a_calc[i][j] = a[i][j];
                }
            } else {
                for (j=0; j<C; j++) {
                    a_calc[i][j] = 1 - a[i][j];
                }
            }
        }
        for (i=0; i<C; i++) {
            count = 0;
            for (j=0; j<R; j++) {
                count += (int)a_calc[j][i];
            }
            if (count > R - count) {
                sum += count;
            } else {
                sum += (R - count);
            }
        }
        if (sum > max) {
            max = sum;
        }
    }
    printf("%d\n", max);
    return 0;
}
