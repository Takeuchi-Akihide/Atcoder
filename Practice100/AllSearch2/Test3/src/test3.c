#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INT     19
#define MAX_N       3000
#define MAX_XY      5000

#define DEBUG

typedef struct {
    int area;
    int i;
    int j;
    int x1;
    int y1;
    int x2;
    int y2;
} AREA_INFO_T;

int getDigit(long long unsigned int num);
long long unsigned int StrToInt(char* str, int num);
int getNumbers(int n, int max, int min, int *result);
int getCharacters(int max, char *result);
void print_err(char *ms);
int max(int a, int b);
int cmpnum(const void * a, const void * b);
// bool isSquare(int i1, int i2, int i3, int i4, AREA_INFO_T *area_info);

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

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

// 並べ替え基準を示す関数(降順)
int cmpnum(const void * a, const void * b)
{
    if (((AREA_INFO_T*)a)->area < ((AREA_INFO_T*)b)->area) {
        return 1;
    } else {
        return -1;
    }
}

bool isSquare(int i1, int i2, int i3, int i4, AREA_INFO_T *area_info) {
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;

    if (area_info[i1].i == area_info[i2].i && area_info[i1].j == area_info[i3].i &&
        area_info[i2].j == area_info[i4].i && area_info[i3].j == area_info[i4].j)
    {
        x3 = area_info[i4].x2;
        y3 = area_info[i4].y2;
        x4 = area_info[i4].x1;
        y4 = area_info[i4].y1;
    } else if (
        (area_info[i1].i == area_info[i2].i && area_info[i1].j == area_info[i3].i &&
        area_info[i2].j == area_info[i4].j && area_info[i3].j == area_info[i4].i) ||
        (area_info[i1].i == area_info[i2].i && area_info[i1].j == area_info[i3].j &&
        area_info[i2].j == area_info[i4].j && area_info[i3].i == area_info[i4].i))
    {
        x3 = area_info[i4].x1;
        y3 = area_info[i4].y1;
        x4 = area_info[i4].x2;
        y4 = area_info[i4].y2;
    }
    else {
        return false;
    }
    x1 = area_info[i1].x1;
    y1 = area_info[i1].y1;
    x2 = area_info[i1].x2;
    y2 = area_info[i1].y2;

    printf("(%d, %d) (%d, %d) (%d, %d) (%d, %d) \n", x1, y1, x2, y2, x3, y3, x4, y4);
    
    int dif1 = x2 - x1;
    int dif2 = y1 - y2;
    if (((x2 - dif2 == x3) && (x1 - dif2 == x4) && (y2 - dif1 == y3) && (y1 - dif1 == y4)) ||
        ((x2 + dif2 == x3) && (x1 + dif2 == x4) && (y2 + dif1 == y3) && (y1 + dif1 == y4)))
    {
        return true;
    }
    return false;
}

int main (int argc, char *argv[]) {
    int i, j, k, l;
    int i1, i2, i3, i4;
    int x1, x2, y1, y2;
    // int x3[2], x4[2], y3[2], y4[2];
    long long unsigned int area_max = 0;
    long long unsigned int area;

    /* nの取得 */
    int n;
    if (getNumbers(1, MAX_N, 1, &n) == false) {
        return 1;
    }

    int xy[MAX_N][2];
    for (i=0; i<n; i++) {
        if (getNumbers(2, MAX_XY, 0, xy[i]) == false) {
            return 1;
        }
    }

    AREA_INFO_T area_info[100000];
    int count_n = 0;

    for (i=0; i<n-1; i++) {
        x1 = xy[i][0];
        y1 = xy[i][1];
        for (j=i+1; j<n; j++) {
            x2 = xy[j][0];
            y2 = xy[j][1];
            int dif1 = x2 - x1;
            int dif2 = y1 - y2;
            area_info[count_n].area = dif1 * dif1 + dif2 * dif2;
            area_info[count_n].i = i;
            area_info[count_n].j = j;
            area_info[count_n].x1 = x1;
            area_info[count_n].y1 = y1;
            area_info[count_n].x2 = x2;
            area_info[count_n].y2 = y2;
            count_n++;
        }
    }

    // printf("%d\n", area_info[0].area);


    qsort(area_info, count_n, sizeof(AREA_INFO_T), cmpnum);
    for (i=0; i<count_n; i++) {
        printf("%d %d\n", i, area_info[i].area);
    }

    int count = 0;
    while(1) {
        if (count == count_n) {
            break;
        }

        int now_area = area_info[count].area;
        int count_areaNum = 0;
        while (now_area == area_info[count].area) {
            count++;
            count_areaNum++;
        }
        if (count_areaNum < 4) {
            count_areaNum = 0;
            continue;
        }
        printf("count:%d count_areaNum:%d\n", count, count_areaNum);
        int before_count = count - count_areaNum;
        for (i1=before_count; i1<count-3; i1++) {
            for (i2=i1+1; i2<count-2; i2++) {
                for (i3=i2+1; i3<count-1; i3++) {
                    for (i4=i3+1; i4<count; i4++) {
                        if (isSquare(i1, i2, i3, i4, area_info)) {
                            area_max = area_info[i1].area;
                        }
                    }
                }
            }
        }
        if (area_max > 0 || count == count_n) {
            break;
        }
    }
    printf("%llu\n", area_max);
    return 0;

#if 0
    for (i=0; i<n-1; i++) {
        x1 = xy[i][0];
        y1 = xy[i][1];
        for (j=i+1; j<n; j++) {
            x2 = xy[j][0];
            y2 = xy[j][1];
            int dif1 = x2 - x1;
            int dif2 = y1 - y2;
            area = dif1 * dif1 + dif2 * dif2;
            if (area > area_max) {
                k = 0;
                while(k < 2) {
                    bool isfind3 = false;
                    bool isfind4 = false;
                    x3[k] = x2 - dif2;
                    x4[k] = x1 - dif2;
                    y3[k] = y2 - dif1;
                    y4[k] = y1 - dif1;
                    if (x3[k] < 0 || x4[k] < 0 || y3[k] < 0 || y4[k] < 0) {
                        dif1 *= -1;
                        dif2 *= -1;
                        k++;
                        continue;
                    }
                    for (l=0; l<n; l++) {
                        if (xy[l][0] == x3[k] && xy[l][1] == y3[k]) {
                            isfind3 = true;
                        }
                        else if (xy[l][0] == x4[k] && xy[l][1] == y4[k]) {
                            isfind4 = true;
                        }
                        if (isfind3 && isfind4) {
                            area_max = area;
                            break;
                        }
                    }
                    if (!isfind3 || !isfind4) {
                        dif1 *= -1;
                        dif2 *= -1;
                        k++;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    printf("%llu\n", area_max);
    return 0;
#endif
}
