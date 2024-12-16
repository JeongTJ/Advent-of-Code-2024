
SRCS := \
	main.cpp

OBJS := $(SRCS:.cpp=.o)
INCLUDE := ./include
CXX := c++ -std=c++17
SFMLFLAGS = -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
NAME := run

SUBJECTNAME := "2024 12 14 - 1"
RED := \033[31m
GREEN := \033[32m
BLUE := \033[34m
WHITE := \033[0m

.PHONY: all clean fclean re

all :
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make all$(WHITE)"
	@ make $(NAME)

re : fclean all
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make re$(WHITE)"

$(NAME) : $(OBJS)
	@ $(CXX) $(CXXFLAGS) $(SFMLFLAGS) $^ -o $@

%.o : %.cpp
	@ $(CXX) $(CXXFLAGS) $(SFMLFLAGS) -c $^ -I$(INCLUDE) -o $@

fclean :
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make fclean$(WHITE)"
	@ make clean
	@ rm -rf $(NAME)

clean :
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make clean$(WHITE)"
	@ rm -rf $(OBJS)
