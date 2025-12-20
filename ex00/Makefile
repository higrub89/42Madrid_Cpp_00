NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "COMPILING DONE!!"

clean:
	$(RM) $(OBJS)
	@echo "Cleanup Files Objs"

fclean: clean
	$(RM) $(NAME)
	@echo "CLEANUP DONE!!"

re: fclean all

.PHONY: all clean fclean re
