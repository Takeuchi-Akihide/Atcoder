#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_HW      1005
#define MAX_N       10

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

long long getTime(int zahyo[][MAX_HW], int *start, int *goal);
    
long long getTime(int zahyo[][MAX_HW], int *start, int *goal) {
    int list[MAX_HW*10][2] = {0};
    int distance[MAX_HW][MAX_HW] = {0};
    list[0][0] = start[0];
    list[0][1] = start[1];
    int listNum = 1;
    int i, x, y;
    int time = 1;
    distance[list[0][0]][list[0][1]] = 1;
    while (1) {
        int nextList[MAX_HW*10][2];
        int nextNum = 0;
        time++;
        for (i=0; i<listNum; i++) {
            x = list[i][0];
            y = list[i][1];
            if (zahyo[x-1][y] == 1 && distance[x-1][y] == 0) {
                distance[x-1][y] = time;
                nextList[nextNum][0] = x-1;
                nextList[nextNum][1] = y;
                nextNum++;
            }
            if (zahyo[x][y-1] == 1 && distance[x][y-1] == 0) {
                distance[x][y-1] = time;
                nextList[nextNum][0] = x;
                nextList[nextNum][1] = y-1;
                nextNum++;
            }
            if (zahyo[x+1][y] == 1 && distance[x+1][y] == 0) {
                distance[x+1][y] = time;
                nextList[nextNum][0] = x+1;
                nextList[nextNum][1] = y;
                nextNum++;
            }
            if (zahyo[x][y+1] == 1 && distance[x][y+1] == 0) {
                distance[x][y+1] = time;
                nextList[nextNum][0] = x;
                nextList[nextNum][1] = y+1;
                nextNum++;
            }
        }
        if (distance[goal[0]][goal[1]] != 0) {
            return distance[goal[0]][goal[1]] - 1;
        } else {
            for (i=0; i<nextNum; i++) {
                // printf("[%d %d] ", nextList[i][0], nextList[i][1]);
                list[i][0] = nextList[i][0];
                list[i][1] = nextList[i][1];
            }
            // printf("\n");
            listNum = nextNum;
        }
    }

}

int main (int argc, char *argv[]) {
    int i, j;

    /* Nの取得 */
    long long HWN[3];
    getNumbers(3, MAX_HW, 1, HWN);
    long long H = HWN[0];
    long long W = HWN[1];
    long long N = HWN[2];

    int zahyo[MAX_HW][MAX_HW] = {0};
    // int start[2];
    int goal[MAX_N][2];
    char buf[MAX_HW];
    char ch;
    for (i=1; i<=H; i++) {
        for (j=1; j<=W; j++) {
            scanf("%c", &buf[j]);
            if (buf[j] > '0' && buf[j] <= '9') {
                goal[buf[j]-'0'][0] = i;
                goal[buf[j]-'0'][1] = j;
                zahyo[i][j] = 1;
            } else if (buf[j] == 'S') {
                goal[0][0] = i;
                goal[0][1] = j;
                zahyo[i][j] = 1;
            } else if (buf[j] == '.') {
                zahyo[i][j] = 1;
            } else if (buf[j] == 'X') {
                zahyo[i][j] = 0;
            }
        }
        while ((ch = getchar()) != '\n');
    }

    long long time = 0;
    for (i=1; i<=N; i++) {
        // printf("[%d %d] -> [%d %d]\n", start[0], start[1], goal[i][0], goal[i][1]);
        time += getTime(zahyo, goal[i-1], goal[i]);
    }
    printf("%lld\n", time);
    return 0;
}
