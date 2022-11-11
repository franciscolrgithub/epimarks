# This is the Makefile

CPPFLAGS = 
CC = gcc
CPPFLAGS = 
CFLAGS = -Wall -Wextra -std=c99 -O2
LDFLAGS = 
LDLIBS = 

SRC = file.c utils.c
OBJ = ${SRC:.c=.o}

file: ${OBJ}

.PHONY: clean

clean:	
		${RM} file
		${RM} ${OBJ}
		#${RM} *.txt

#END
