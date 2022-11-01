#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_S  100000
// #define DEBUG

char *T_list[] = {"dream", "dreamer", "erase", "eraser"};

int repeat_SameCheck(char* S, int S_len);
int getCharacters(int max, char *result);
void print_err(char *ms);

void print_err(char *ms) {
#if defined DEBUG
    printf("ERROR  %s!!!\n", ms);
#endif
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


int SameCheck(char* S, int S_len) {

    int T_size = sizeof(T_list)/sizeof(T_list[0]);
    int T_len;
    char tmp[8];
    int i;
    while (1) {
        bool isSameFlg = false;
        if (S_len <= 4) {
            break;
        }
        for (i=0; i<T_size; i++) {
            T_len = strlen(T_list[i]);
            if (S_len >= T_len) {
                strncpy(tmp, &S[S_len-T_len], T_len);
                if (strncmp(tmp, T_list[i], T_len) == 0) {
                    S_len -= T_len;
                    isSameFlg = true;
                }
            }
        }
        if (isSameFlg == false) {
            return false;
        }
    }
    if (S_len == 0) {
        return true;
    }
    return false;
}

int main (int argc, char *argv[]) {
    /* Sの取得 */
    char S[MAX_S+1];
    if (getCharacters(MAX_S+1, S) == false) {
        return 1;
    }
    int S_len = strlen(S);
    if (S_len < 4) {
        printf("NO\n");
        return 0;
    }
    if (SameCheck(S, S_len) == true) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
