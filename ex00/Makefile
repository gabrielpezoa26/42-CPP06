NAME = convert
OBJECTS = objects/main.o objects/ScalarConverter.o

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

objects/ScalarConverter.o: ScalarConverter.cpp
	$(CC) $(CFLAGS) -c ScalarConverter.cpp -o objects/ScalarConverter.o

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)


#for debugging
char:all
	./$(NAME) c
int:all
	./$(NAME) 42
float:all
	./$(NAME) 0.0f
double:all
	./$(NAME) 4.2



val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

re: fclean all