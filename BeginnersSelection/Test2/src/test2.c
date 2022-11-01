#include <stdio.h>
#include <ctype.h>

#define MAX_INT     5

void print_err(char ms) {
    printf("%c is not right!!!\n", ms);
}

int main (int argc, char *argv[]) {
    char ch;
    int count = 0;
    int num_count[2] = {0};
    char a_buf[MAX_INT + 1] = "";
    char b_buf[MAX_INT + 1] = "";
    int a = 0;
    int b = 0;

    while ((ch = getchar()) != '\n') {
        if (count == 0) {
            if (ch == ' ' && a_buf != "") {
                count++;
                continue;
            }
            a_buf[num_count[count]] = ch;
            num_count[count]++;
            if (num_count[count] > MAX_INT) {
                print_err('a');
                break;
            }
        } else {
            if (ch == ' ') {
                continue;
            }
            b_buf[num_count[count]] = ch;
            num_count[count]++;
            if (num_count[count] > MAX_INT) {
                print_err('b');
                break;
            }
        }
    }

    int i;
    for (i=0; i<num_count[0]; i++) {
        if (isdigit(a_buf[i])) {
            a = a * 10 + (a_buf[i] - '0');
        } else {
            print_err('a');
            break;
        }
    }
    for (i=0; i<num_count[1]; i++) {
        if (isdigit(b_buf[i])) {
            b = b * 10 + (b_buf[i] - '0');
        } else {
            print_err('b');
            break;
        }
    }

    if (a % 2 != 0 && b % 2 != 0) {
        printf("Odd\n");
    } else {
        printf("Even\n");
    }
    return 0;
}