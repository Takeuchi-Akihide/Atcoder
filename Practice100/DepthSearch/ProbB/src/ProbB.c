#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT     19
#define MAX_W       50
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

typedef struct Graph {
    long long c;
    long long k;
    long long v[5];
    int nowv;
    bool isfound;
    bool iscomp;
    int beforeD;
} _Graph;

int main (int argc, char *argv[]) {
    int i, j;
    int iw, ih;
    long long ans[1000] = {0};
    int num = 0;

    while (true) {
        /* w,hの取得 */
        long long WH[2];
        getNumbers(2, MAX_W, 1, WH);

        long long w = WH[0];
        long long h = WH[1];
        if (w == 0 && h == 0) {
            break;
        }

        _Graph data[MAX_W*MAX_W];
        long long c[MAX_W];
        int count = 0;
        for (ih=0; ih<h; ih++) {
            getNumbers(w, 1, 0, c);
            for (iw=0; iw<w; iw++) {
                data[count].c = c[iw];
                data[count].k = 0;
                data[count].nowv = 0;
                data[count].iscomp = false;
                data[count].isfound = false;
                count++;
            }
        }

        for (i=0; i<count; i++) {
            ih = i / w;
            iw = i - ih*w;
            if ((iw+1 < w) && data[i+1].c == 1) {
                data[i].v[data[i].k] = i+1;
                data[i].k++;
            }
            if ((ih+1 < h)) {
                if ((iw-1 >= 0) && data[i+w-1].c == 1) {
                    data[i].v[data[i].k] = i+w-1;
                    data[i].k++;
                }
                if (data[i+w].c == 1) {
                    data[i].v[data[i].k] = i+w;
                    data[i].k++;
                }
                if ((iw+1 < w) && data[i+w+1].c == 1) {
                    data[i].v[data[i].k] = i+w+1;
                    data[i].k++;
                }
            }
            // printf("i=%d\t", i);
            // for (j=0; j<data[i].k; j++) {
            //     printf("%lld ", data[i].v[j]);
            // }
            // printf("\n");
        }
        
        for (i=0; i<count; i++) {
            int foundData[MAX_W*MAX_W] = {0};
            bool isNew = false;
            // printf("%d\t", i);
            if (data[i].c == 0) {
                // printf("sea\n");
                continue;
            }

            if (data[i].iscomp) {
                // printf("still found\n");
                continue;
            } else {
                // printf("new island\n");
                isNew = true;
                // ans[num]++;
            }
            long long nowD = i;
            long long beforeD;

            while (data[i].iscomp == false) {
                if (data[nowD].nowv < data[nowD].k) {
                    beforeD = nowD;
                    nowD = data[nowD].v[data[nowD].nowv];
                    data[beforeD].nowv++;
                    data[nowD].beforeD = beforeD;
                    if (data[nowD].isfound) {
                        isNew = false;
                    }
                    // printf("data:%lld->%lld\n", beforeD, nowD);
                } else {
                    foundData[nowD] = 1;
                    data[nowD].iscomp = true;
                    // printf("data:%lld->%d, complete\n", nowD, data[nowD].beforeD);
                    nowD = data[nowD].beforeD;
                }
            }
            for (j=0; j<count; j++) {
                if (foundData[j] == 1) {
                    data[j].isfound = true;
                }
            }
            if (isNew) {
                ans[num]++;
            }
        }
        num++;
    }
    for (i=0; i<num; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
