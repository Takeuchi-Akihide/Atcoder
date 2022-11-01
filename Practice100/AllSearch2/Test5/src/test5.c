#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       1000
#define MAX_M       200
#define MAX_XY      1000000

#define DEBUG

int getDigit(long long unsigned int num);
long long unsigned int StrToInt(char* str, int num);
int getNumbers(int n, int max, int min, int *result);
int getCharacters(int max, char *result);
void print_err(char *ms);
int max(int a, int b);
bool isFindStars(unsigned long long int xy, unsigned long long int *xPlusy, int n);
    
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

bool isFindStars(unsigned long long int xy, unsigned long long int *xPlusy, int n) {
    
    int lowid, midid, highid;

    highid = n-1;
    lowid = 0;

    while (lowid <= highid) {
        midid = (lowid + highid) / 2;
        if (xPlusy[midid] == xy) {
            return true;
        } else if (xPlusy[midid] < xy) {
            lowid = midid + 1;
        } else {
            highid = midid - 1;
        }
    }
    return false;
}

int cmpnum(const void * n1, const void * n2)
{
	if (*(long *)n1 > *(long *)n2)
	{
		return 1;
	}
	else if (*(long *)n1 < *(long *)n2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main (int argc, char *argv[]) {
    int i, j;
    int move_x, move_y;
    bool isFind = false;

    /* mの取得 */
    int m;
    if (getNumbers(1, MAX_M, 1, &m) == false) {
        return 1;
    }

    /* 探したい星座の座標を取得 */
    int xy_m[MAX_M][2];
    int stars[MAX_M][2];
    for (i=0; i<m; i++) {
        if (getNumbers(2, MAX_XY, 0, xy_m[i]) == false) {
            return 1;
        }
        stars[i][0] = xy_m[i][0] - xy_m[0][0];
        stars[i][1] = xy_m[i][1] - xy_m[0][1];
    }
    // for (i=0; i<m; i++) {
    //     printf("xy_m %d %d\n", xy_m[i][0], xy_m[i][1]);
    //     printf("stars %d %d\n", stars[i][0], stars[i][1]);
    // }

    /* Nの取得 */
    int n;
    if (getNumbers(1, MAX_N, 1, &n) == false) {
        return 1;
    }
    
    /* 星の座標を取得 */
    int xy_n[MAX_N][2];
    unsigned long long int xPlusy[MAX_N];
    for (i=0; i<n; i++) {
        if (getNumbers(2, MAX_XY, 0, xy_n[i]) == false) {
            return 1;
        }
        xPlusy[i] = (unsigned long long int) xy_n[i][0] * MAX_XY + (unsigned long long int) xy_n[i][1];
    }

    qsort(xPlusy, n, sizeof(long long int), cmpnum);
    // for (i=0; i<n; i++) {
    //     printf("after %lld\n", xPlusy[i]);
    // }

    /* 検索 */
    for (i=0; i<n; i++) {
        for (j=1; j<m; j++) {
            // printf("%d %d\n",  xy_n[i][0],  xy_n[i][1]);
            isFind = true;
            unsigned long long int xy = (unsigned long long int) (xy_n[i][0] + stars[j][0]) * MAX_XY + (unsigned long long int) (xy_n[i][1] + stars[j][1]);
            // printf("%lld\n", xy);
            if (isFindStars(xy, xPlusy, n) == false) {
                isFind = false;
                break;
            }
        }

        if (isFind) {
            move_x = xy_n[i][0] - xy_m[0][0];
            move_y = xy_n[i][1] - xy_m[0][1];
            break;
        }
    }
    printf("%d %d\n", move_x, move_y);
    return 0;
}
