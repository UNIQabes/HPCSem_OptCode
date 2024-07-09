CC = gcc
CFLAGS = 

bin/%: %.c
	${CC} ${CFLAGS} $< -o $@


