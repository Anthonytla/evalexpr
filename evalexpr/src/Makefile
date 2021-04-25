CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
SRC = ast.c main.c evalexpr.c lexer.c parser.c queue.c token.c
OBJ = $(SRC:.c=.o)
TARGET = evalexpr

all: $(TARGET)

clean:
	$(RM) $(OBJ) $(TARGET) *~

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lreadline -lm -o $(TARGET)
