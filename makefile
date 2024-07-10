CC = gcc
CFLAGS = -mavx2

bin/%: %.c
	${CC} ${CFLAGS} $< -o $@

.PHONY:all

all: bin/main_orig bin/main_swapLoop bin/main_blocking  bin/main_orig_blocking bin/main_avx2 
