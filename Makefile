CC?=clang
CFLAGS?=-Wall -Wextra -O2

cool_print: cool_print.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm cool_print
