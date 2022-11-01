#include <stdio.h>
#include <ctype.h>

#define MAX_INT     4
#define MAX_CHAR    100

void print_err(char ms) {
    printf("%c is not right!!!\n", ms);
}

int main (int argc, char *argv[]) {
    char ch;
    int count = 0;
    int num_count[4] = {0};
    char a_buf[MAX_INT + 1] = "";
    char b_buf[MAX_INT + 1] = "";
    char c_buf[MAX_INT + 1] = "";
    int a = 0;
    int b = 0;
    int c = 0;
    char s[MAX_CHAR + 1] = "";

    while (ch = getchar()) {
        if (ch == '\n') {
            // num_count = 0;
            count++;
        }
        if (count >= 4) break;
        
        if (count == 0) {
            if (ch == '\n' || ch == ' ') {
                continue;
            }
            a_buf[num_count[count]] = ch;
            num_count[count]++;
            if (num_count[count] > MAX_INT) {
                print_err('a');
                break;
            }
        } else if (count == 1) {
            if (ch == ' ' && b_buf != "") {
                count++;
                continue;
            }
            b_buf[num_count[count]] = ch;
            num_count[count]++;
            if (num_count[count] > MAX_INT) {
                print_err('b');
                break;
            }
        } else if (count == 2) {
            if (ch == ' ') {
                continue;
            }
            c_buf[num_count[count]] = ch;
            num_count[count]++;
            if (num_count[count] > MAX_INT) {
                print_err('c');
                break;
            }
        } else {
            if (ch == '\n') {
                continue;
            }
            s[num_count[count]] = ch;
            num_count[count]++;
            if (num_count[count] > MAX_CHAR) {
                print_err('s');
                break;
            }
        }
    }

    int i;
    for (i=0; i<num_count[0]; i++) {
        if (isdigit(a_buf[i])) {
            a = a * 10 + (a_buf[i] - '0');
        }
    }
    for (i=0; i<num_count[1]; i++) {
        if (isdigit(b_buf[i])) {
            b = b * 10 + (b_buf[i] - '0');
        }
    }
    for (i=0; i<num_count[2]; i++) {
        if (isdigit(c_buf[i])) {
            c = c * 10 + (c_buf[i] - '0');
        }
    }
    s[num_count[3]] = '\0';

    printf("%d %s\n", a + b + c, s);
    return 0;
}