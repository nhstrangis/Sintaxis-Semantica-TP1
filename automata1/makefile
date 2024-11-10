EXEC_NAME = automata1

SRC = main.c scanner.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -g

$(EXEC_NAME): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC_NAME)