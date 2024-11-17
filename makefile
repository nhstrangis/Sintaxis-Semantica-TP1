EXEC_NAME = calcu

SRC = main.c scanner.c stack.c queue.c operator.c atoi.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -g

$(EXEC_NAME): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC_NAME)