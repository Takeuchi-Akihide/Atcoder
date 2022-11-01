#include <stdio.h>
#include <ctype.h>

#define MAX_INT     3

void print_err(char ms) {
    printf("%c is not right!!!\n", ms);
}

int main (int argc, char *argv[]) {
    char ch;
    int num_count = 0;
    int count = 0;
    char a_buf[MAX_INT + 1] = "";

    while ((ch = getchar()) != '\n') {
        if (ch == ' ') continue;

        a_buf[num_count] = ch;
        num_count++;
        
        if (num_count > MAX_INT) {
            print_err('a');
            break;
        }
    }

    int i;
    for (i=0; i<num_count; i++) {
        if (a_buf[i] == '0') {
            ;
        } else if (a_buf[i] == '1') {
            count++;
        } else {
            print_err('b');
            break;
        }
    }
    printf("%d\n", count);
    return 0;
}