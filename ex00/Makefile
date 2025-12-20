NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

SCRS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all = $(NAME)

$(NAME) = $(OBJS)
    $(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
    @echo "COMPILING DONE!!"

clean:
    $(RM) $(OBJS)
    @ "Cleanup Files Objs"

fclean: clean
    $(RM) $(NAME)
    @ "CLEANUP DONE!!"

re: fclean $(NAME)
    @"Cleaning and Recompiling .."



.PHONY: all clean fclean rePHONY: all clean fclean re

