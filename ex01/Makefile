NAME = serializer
OBJECTS = objects/main.o objects/Serializer.o objects/Data.o objects/utils.o

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

objects/Serializer.o: Serializer.cpp
	$(CC) $(CFLAGS) -c Serializer.cpp -o objects/Serializer.o

objects/Data.o: Data.cpp
	$(CC) $(CFLAGS) -c Data.cpp -o objects/Data.o

objects/utils.o: utils.cpp
	$(CC) $(CFLAGS) -c utils.cpp -o objects/utils.o


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)


run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

re: fclean all