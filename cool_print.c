#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char** argv) {
    char* s = NULL;
    if (argc >= 2) {
        s = argv[1];
    } else {
        return -1;
    }
    size_t len = strlen(s);
    char* p = malloc(len + 1);
    memset(p, 0, len + 1);
    srand(time(NULL));
    for (size_t i = 0; i < len; i++) {
        if (!isprint(s[i])) {
            printf("Charachter \"%c\" not allowed\n", s[i]);
            return -1;
        }
        while (p[i] != s[i]) {
            p[i] = rand() % 255;
            while (!isprint(p[i])) {
                p[i] = rand() % 255;
            }
            printf("\r%s", p);
            fflush(stdout);
            usleep(10000);
        }
    }
    puts("");
}
