NAME = identify
OBJECTS = objects/main.o objects/Base.o objects/A.o objects/B.o objects/C.o

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = objects

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

$(OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

objects/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o objects/main.o

objects/Base.o: Base.cpp
	$(CC) $(CFLAGS) -c Base.cpp -o objects/Base.o

objects/A.o: A.cpp
	$(CC) $(CFLAGS) -c A.cpp -o objects/A.o

objects/B.o: B.cpp
	$(CC) $(CFLAGS) -c B.cpp -o objects/B.o

objects/C.o: C.cpp
	$(CC) $(CFLAGS) -c C.cpp -o objects/C.o


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)


run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

re: fclean all