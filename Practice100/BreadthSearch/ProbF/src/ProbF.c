#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_HW      55

// #define DEBUG

int get1Number(int max, int min, long long *result);
void print_err(char *ms);
int getDigit(long long num);
int getNumbers(int n, int max, int min, long long *result);
int getCharacters(int max, char *result);
int cmpnum(const void * n1, const void * n2);
long long StrToInt(char* str, long long num);
long long binarySearchNum(long long x, long long *array, long long n);
long long checkGCD(long long a, long long b);

void print_err(char *ms) {
#if defined DEBUG
    printf("ERROR  %s!!!\n", ms);
#endif
}

/* 標準入力から、空白/改行が来るまで整数1つを読み取る */
int get1Number(int max, int min, long long *result) {
    int num_count = 0;
    char ch;
    char buf[MAX_INT+1] = "";

    while ((ch = getchar()) != ' ') {
        if (ch == '\n') {
            break;
        }
        buf[num_count] = ch;
        num_count++;
        if (num_count > MAX_INT) {   /* 数字の桁数がmax_intを超えたらエラー */
            print_err("Maxint Over");
        }
    }
    
    *result = StrToInt(buf, num_count);
    if (*result < min || *result > max) {
        print_err("Num big or small");
    }
    return true;
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

    while ((ch = getchar())) {
        if (ch == ' ' || ch == '\n') {
            if (buf[0] != '\0') {
                result[count] = StrToInt(buf, num_count);
                if (result[count] < min || result[count] > max) {
                    print_err("Num big or small");
                }
                count++;
                if (count > n) {       /* 標準入力に記載された整数がn個を超えたらエラー */
                    print_err("Num Count Over");
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
        if (num_count > MAX_INT) {   /* 数字の桁数がmax_intを超えたらエラー */
            print_err("Maxint Over");
        }
    }

    if (count != n) {
        print_err("count != n");
        // printf("count:%d, n:%d\n", count, n);
    }
    return true;
}


/* 昇順に並び替え */
int cmpnum(const void * n1, const void * n2)
{
	if (*(long long *)n1 > *(long long *)n2)
	{
		return 1;
	}
	else if (*(long long *)n1 < *(long long *)n2)
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
        }
    }
    result[count] = '\0'; 
    return true;
}

long long StrToInt(char* str, long long num) {
    long long i;
    long long n = 0;
    bool isMinus = false;
    for (i=0; i<num; i++) {
        if (i == 0 && str[i] == '-') {
            isMinus = true;
        }
        else if (isdigit(str[i])) {
            n = n * 10 + (str[i] - '0');
        } else {
            print_err("Input Number");
        }
    }
    if (isMinus) {
        n *= -1;
    }
    return n;
}

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

/* array[i-1]<x<=array[i] のとき、iを返す */
/* arrayは昇順に並べ替えておく */
long long binarySearchNum(long long x, long long *array, long long n) {
    long long min = 0;
    long long max = n;
    long long mid;
    while (min <= max) {
        mid = (min + max) / 2;
        if (mid == 0 && x <= array[mid]) {
            return mid;
        } else if 
            ((mid == n-1 && array[mid] < x) ||
             (array[mid] < x && x <= array[mid+1])) {
            return mid + 1;
        } else if (array[mid] < x) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
}

int main (int argc, char *argv[]) {
    int i, j;
    bool isFind = false;

    /* Nの取得 */
    long long HW[2];
    getNumbers(2, MAX_HW, 1, HW);

    long long H = HW[0];
    long long W = HW[1];
    
    int s[2] = {1, 1};
    int g[2] = {H, W};

    /* zahyoの取得 */
    int zahyo[MAX_HW][MAX_HW];
    int blackNum = 0, whiteNum = 0;
    char buf[MAX_HW];
    for (i=1; i<=H; i++) {
        for(j=1; j<=W; j++) {
            scanf("%c", &buf[j]);
            if (buf[j] == '.') {
                zahyo[i][j] = 1;
                whiteNum++;
            } else {
                zahyo[i][j] = 0;
                blackNum++;
            }
        }
        char ch;
        while ((ch = getchar()) != '\n');
    }

    // printf("zahyo\n");
    // for (i=0; i<=H+1; i++) {
    //     printf("%d:  ", i);
    //     for(j=0; j<=W+1; j++) {
    //         printf("%d ", zahyo[i][j]);
    //     }
    //     printf("\n");
    // }


    int distance[MAX_HW][MAX_HW] = {0};
    distance[s[0]][s[1]] = 1;
    int time = 1;
    while(1) {
        for(i=1; i<=H; i++) {
            for(j=1; j<=W; j++) {
                if (distance[i][j] == time) {
                    if (zahyo[i-1][j] == 1 && distance[i-1][j] == 0) {
                        distance[i-1][j] = time + 1;
                    }
                    if (zahyo[i][j-1] == 1 && distance[i][j-1] == 0) {
                        distance[i][j-1] = time + 1;
                    }
                    if (zahyo[i+1][j] == 1 && distance[i+1][j] == 0) {
                        distance[i+1][j] = time + 1;
                    }
                    if (zahyo[i][j+1] == 1 && distance[i][j+1] == 0) {
                        distance[i][j+1] = time + 1;
                    }
                }
            }
        }
        time++;
        if (distance[g[0]][g[1]] != 0) {
            isFind = true;
            break;
        }
        if (time > W * H) {
            isFind = false;
            break;
        }
    }
    if (isFind) {
        printf("%d\n", whiteNum - distance[g[0]][g[1]]);
    } else {
        printf("-1\n");
    }
    return 0;
}
