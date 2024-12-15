SRC = main.cpp
OBJ = main.o
CC = g++
# SFML_DIR = /opt/homebrew/Cellar/sfml/2.6.1
FLAGS = -std=c++17
# VIEWFLAGS = -std=c++17 -I$(SFML_DIR)/include -L$(SFML_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system
NAME = run

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

test: test.o
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(FLAGS) -c $^

re:
	@ make clean
	@ make all

clean:
	@ rm -rf $(OBJ)
	@ rm -rf $(NAME)
	@ rm -rf test
	@ rm -rf test.o

reset:
	cat base.cpp > main.cpp