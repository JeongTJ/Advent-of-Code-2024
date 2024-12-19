SRCS1 := \
	main1.cpp

SRCS2 := \
	main2.cpp

OBJS1 := $(SRCS1:.cpp=.o)
OBJS2 := $(SRCS2:.cpp=.o)

INCLUDE := ./include
CXX := c++ -std=c++17
# SFMLFLAGS = -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

NAME1 := run1
NAME2 := run2
NAME := run

SUBJECTNAME := "2024 12 01"
RED := \033[31m
GREEN := \033[32m
BLUE := \033[34m
WHITE := \033[0m

.PHONY: all 1 2 clean fclean re

all : $(NAME1) $(NAME2)
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make all$(WHITE)"

1 : $(NAME1)
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make 1$(WHITE)"

2 : $(NAME2)
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make 2$(WHITE)"

re : fclean all
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make re$(WHITE)"

$(NAME1) : $(OBJS1)
	@ $(CXX) $(CXXFLAGS) $(SFMLFLAGS) $^ -o $@
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)Build $(NAME1) Complete$(WHITE)"

$(NAME2) : $(OBJS2)
	@ $(CXX) $(CXXFLAGS) $(SFMLFLAGS) $^ -o $@
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)Build $(NAME2) Complete$(WHITE)"

%.o : %.cpp
	@ $(CXX) $(CXXFLAGS) $(SFMLFLAGS) -c $< -I$(INCLUDE) -o $@

fclean : clean
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make fclean$(WHITE)"
	@ rm -rf $(NAME1) $(NAME2)

clean :
	@ echo "[$(BLUE)$(SUBJECTNAME)$(WHITE)] $(GREEN)make clean$(WHITE)"
	@ rm -rf $(OBJS1) $(OBJS2)
