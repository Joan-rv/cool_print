#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char** argv) {
    char* s = NULL;
    int delay = 10;
    // two or three arguments
    if (argc >= 2 && argc <= 3) {
        s = argv[1];
        if (argc == 3) {
            delay = atoi(argv[2]);
        }
    } else {
        fprintf(stderr,
                "USAGE: cool_print TEXT [DELAY]\nNote that DELAY is in ms\n");
        return -1;
    }
    size_t len = strlen(s);
    char* p = malloc(len + 1);
    memset(p, 0, len + 1);
    srand(time(NULL));
    for (size_t i = 0; i < len; i++) {
        if (!isprint(s[i])) {
            fprintf(stderr, "Charachter \"%c\" not allowed\n", s[i]);
            return -1;
        }
    }
    for (size_t i = 0; i < len; i++) {
        while (p[i] != s[i]) {
            p[i] = rand() % 255;
            while (!isprint(p[i])) {
                p[i] = rand() % 255;
            }
            printf("\r%s", p);
            fflush(stdout);
            usleep(1000 * delay);
        }
    }
    puts("");
    free(p);
}
