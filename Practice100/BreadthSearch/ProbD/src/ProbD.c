#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_WH      105
#define MAX_A       pow(10, 9)

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

enum {
    NOT_YET = 0,
    NAIRIKU,
    NOT_NAIRIKU,
    CHECKING,
};

void nextTo(int now[2], int i, int next[2]);
void nextTo(int now[2], int i, int next[2]) {
    switch (i)
    {
    case 0:
        next[0] = now[0] - 1;
        next[1] = now[1];
        break;
    case 1:
        next[0] = now[0] + 1;
        next[1] = now[1];
        break;
    case 2:
        next[0] = now[0] - 1 + (now[1] % 2);
        next[1] = now[1] - 1;
        break;
    case 3:
        next[0] = now[0] + (now[1] % 2);
        next[1] = now[1] - 1;
        break;
    case 4:
        next[0] = now[0] - 1 + (now[1] % 2);
        next[1] = now[1] + 1;
        break;
    case 5:
        next[0] = now[0] + (now[1] % 2);
        next[1] = now[1] + 1;
        break;
    
    default:
        break;
    }
}

long long W;
long long H;
int zahyo[MAX_WH][MAX_WH] = {0};
int isChecked[MAX_WH][MAX_WH] = {0};
int checkisNairiku(int now[2], int isNairiku[][MAX_WH]);
int checkisNairiku(int now[2], int isNairiku[][MAX_WH]){
    int i;
    int x = now[0];
    int y = now[1];
    isNairiku[x][y] = CHECKING;
    if (x <= 1 || x >= W || y <= 1 || y >= H ) {
        isNairiku[x][y] = NOT_NAIRIKU;
        return NOT_NAIRIKU;
    }

    int next[2];
    for (i=0; i<6; i++) {
        nextTo(now, i, next);
        if (isNairiku[next[0]][next[1]] == NOT_YET) {
            if (zahyo[next[0]][next[1]] == 0 && checkisNairiku(next, isNairiku) == NOT_NAIRIKU) {
                isNairiku[x][y] = NOT_NAIRIKU;
                return NOT_NAIRIKU;
            }
        } else if (isNairiku[next[0]][next[1]] == NOT_NAIRIKU){
            if (zahyo[next[0]][next[1]] == 0) {
                isNairiku[x][y] = NOT_NAIRIKU;
                return NOT_NAIRIKU;
            }
        }
    }
    if (isNairiku[x][y] != NOT_NAIRIKU) {
        isNairiku[x][y] = NAIRIKU;
        return NAIRIKU;
    }
}

int main (int argc, char *argv[]) {
    int i, j, k;
    int isNairiku[MAX_WH][MAX_WH];
    int now[2];
    int next[2];

    /* Nの取得 */
    long long WH[2];
    getNumbers(2, MAX_WH, 1, WH);
    W = WH[0];
    H = WH[1];

    /* 座標の取得 */
    long long buf;
    for (i=1; i<=H; i++) {
        for (j=1; j<=W; j++) {
            get1Number(MAX_WH, 1, &buf);
            zahyo[j][i] = (int)buf;
        }
    }
    // printf("zahyo\n");
    // for (i=0; i<=H+1; i++) {
    //     printf("%d:  ", i);
    //     for (j=0; j<=W+1; j++) {
    //         printf("%d ", zahyo[j][i]);
    //     }
    //     printf("\n");
    // }

    for (i=0; i<=H+1; i++) {
        for (j=0; j<=W+1; j++) {
            now[0] = j;
            now[1] = i;
            checkisNairiku(now, isNairiku);
        }
    }
    // printf("isNairiku\n");
    // for (i=0; i<=H+1; i++) {
    //     printf("%d:  ", i);
    //     for (j=0; j<=W+1; j++) {
    //         printf("%d ", isNairiku[j][i]);
    //     }
    //     printf("\n");
    // }

    int distance = 0;
    for (i=1; i<=H; i++) {
        for (j=1; j<=W; j++) {
            if (zahyo[j][i] == 1) {
                now[0] = j;
                now[1] = i;
                // printf("zahyo: [%d %d] next: ", j, i);
                int before = distance;
                for (k=0; k<6; k++) {
                    nextTo(now, k, next);
                    // printf("[%d %d] = ", next[0], next[1]);
                    if ((zahyo[next[0]][next[1]] == 0 && isNairiku[next[0]][next[1]] == NOT_NAIRIKU)) {
                        // printf("1 ");
                        distance++;
                    // } else {
                    //     printf("0 ");
                    }
                }
                // printf("%d\n", distance - before);
            }
        }
    }
    printf("%d\n", distance);
    return 0;
}
