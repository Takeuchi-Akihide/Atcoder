/*  ProbE.c
 *  https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b
 *  square869120Contest#4
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_NK      15
#define MAX_A       pow(10,9)

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
    int in;
    long long count = 0;
    long long sum = 0;
    long long max = pow(10,9)*MAX_NK;
    long long nowHeight;

    /* N,Kの取得 */
    long long NK[2];
    if (getNumbers(2, MAX_NK, 1, NK) == false) return 1;
    long long N = NK[0];
    long long K = NK[1];

    /* aの取得 */
    long long a[MAX_NK];
    if (getNumbers(N, MAX_A, 1, a) == false) return 1;

    // bit探索 0bit目は1(先頭は必ず見えるため)
    for (in=1; in<pow(2, N); in+=2) {
        sum = 0;
        count = 0;
        for (i=0; i<N; i++) {
            if ((in & (1 << i)) != 0) {
                count++;
            }
        }
        // printf("in:%d, count:%lld\n", in, count);
        if (count >= K) {
            // bitの合計がK以上の場合のみ計算する
            // 2-N番目のうち、bitが立っているものを見る建物とみなして金額を足していく
            nowHeight = a[0];
            for (i=1; i<N; i++) {
                if ((in & (1 << i)) != 0) {
                    // printf("nowHeight:%lld\n", nowHeight);
                    // printf("i a[%d]:%lld\n", i, a[i]);
                    if (nowHeight + 1 > a[i]) {
                        sum += (nowHeight + 1 - a[i]);
                        nowHeight++;
                        // printf("sum:%lld\n", sum);
                    }
                }
                if (nowHeight < a[i]) {
                    nowHeight = a[i];
                }
            }
            if (sum < max) {
                max = sum;
            }
        }
    }
    printf("%lld\n", max);
    return 0;
}
