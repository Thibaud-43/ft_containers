SRCS		=	mainVector.cpp		\


NAME	= vector

CXX		= clang++
CXXFLAGS = -Wall -Wextra -Werror 

RM		= rm -rf

SRCS_PATH	=	./
OBJS_PATH	=	.objs/
INC			= -I includes/


OBJS		= $(addprefix $(OBJS_PATH),$(SRCS:.cpp=.o))

$(OBJS_PATH)%.o: %.cpp
	@ mkdir -p $(OBJS_PATH)
	$(CXX) $(INC) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(INC) -o $(NAME)

clean: 
	$(RM) $(OBJS) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re