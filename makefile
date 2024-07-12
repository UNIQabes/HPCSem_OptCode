CC = gcc
CFLAGS = -mavx2

bin/%: %.c
	${CC} ${CFLAGS} $< -o $@

.PHONY:all

all: bin/main_orig bin/main_swapLoop bin/main_blocking bin/main_blocking_188  bin/main_orig_blocking bin/main_avx2 bin/main_unroll bin/main_unroll_8 bin/main_unroll_20

all_blocking: bin/main_blocking bin/main_blocking_188 bin/main_blocking_288 bin/main_blocking_488 bin/main_blocking_2088 bin/main_blocking_4088 bin/main_blocking_20088 bin/main_blocking_2840 bin/main_blocking_8840 
