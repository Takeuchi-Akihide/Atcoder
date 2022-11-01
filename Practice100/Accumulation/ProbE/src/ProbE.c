#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_HW      130
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
int getMin (int a, int b);

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

int getMin (int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

void push(int x, int *heap, int *sz) {
    int i = *sz++;
    while(i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= x) break;
        heap[i] = heap[p];
        p = i;
    }
    heap[i] = x;
}

int pop(int *heap, int *sz) {
    int ret = heap[0];
    int x = heap[--(*sz)];
    int i = 0;
    while (i*2+1 < *sz) {
        int a = i * 2 + 1;
        int b = i * 2 + 2;
        if (b < *sz && heap[b] < heap[a]) {
            a = b;
        }
        if (heap[a] >= x) break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
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

    /* Nの取得 */
    long long Input1[4];
    getNumbers(4, MAX_A, 1, Input1);
    int H = (int)Input1[0];
    int W = (int)Input1[1];
    long long K = Input1[2];
    long long V = Input1[3];

    long long A[MAX_HW][MAX_HW];
    for (i=1; i<=H; i++) {
        for (j=1; j<=W; j++) {
            get1Number(MAX_A, 1, &A[i][j]);
        }
    }
    for (i=1; i<=H; i++) {
        for (j=1; j<=W; j++) {
            A[i][j] += K;
        }
    }
    // for (i=0; i<H; i++) {
    //     sumRow[i][0] = A[i][0];
    //     sumHW[0][i] = A[0][i];
    // }

    long long sumRow[MAX_HW][MAX_HW];
    long long sumHW[MAX_HW][MAX_HW];
    for (i=1; i<=H; i++) {
        for (j=1; j<=W; j++) {
            sumRow[i][j] = sumRow[i][j-1] + A[i][j];
        }
    }
    for (i=1; i<=H; i++) {
        for (j=1; j<=W; j++) {
            sumHW[i][j] = sumHW[i-1][j] + sumRow[i][j];
        }
    }

    int max = 0;
    int ui, di, li, ri;
    for (ui=1; ui<=H; ui++) {
        for (di=ui; di<=H; di++) {
            for (li=1; li<=W; li++) {
                for (ri=li; ri<=W; ri++) {
                    int size = (di-ui+1) * (ri-li+1);
                    if (size <= max) {
                        continue;
                    }
                    long long price = sumHW[di][ri] - sumHW[di][li-1] - sumHW[ui-1][ri] + sumHW[ui-1][li-1];
                    if (price <= V) {
                        max = size;
                    }
                }
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
