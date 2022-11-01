#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_INT     3
#define MAX_A       100
#define MAX_N       100

// #define DEBUG

int getDigit(int num);
int StrToInt(char* str, int num);
int getNumbers(int n, int max, int min, int *result);
void print_err(char *ms);
int cmpnum(const void * n1, const void * n2);

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
    // int result[n];

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

//	並べ替え基準を示す関数(降順)
int cmpnum(const void * n1, const void * n2)
{
	if (*(int *)n1 > *(int *)n2)
	{
		return -1;
	}
	else if (*(int *)n1 < *(int *)n2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main (int argc, char *argv[]) {
    int i;
    int sum = 0;

    /* Nの取得 */
    int n;
    if (getNumbers(1, MAX_N, 1, &n) == false) {
        return 1;
    }

    /* N個のaの取得 */
    int a[MAX_N];
    if (getNumbers(n, MAX_A, 1, a) == false) {
        return 1;
    }

    qsort(a, n, sizeof(int), cmpnum);

    for (i=0; i<n; i++) {
        if (i % 2 == 0) {
            sum += a[i];
        } else {
            sum -= a[i];
        }
    }

    printf("%d\n", sum);
    return 0;
}