SRCS_VECTOR		=	vector.cpp		
SRCS_MAP		=	map.cpp		



VECTOR	= vector
MAP		= map

CXX		= clang++
CXXFLAGS = -Wall -Wextra -Werror 

RM		= rm -rf

SRCS_PATH			=	./srcs/
OBJS_PATH			=	.objs/
INC					= -I includes/containers/vector -I includes/containers/map -I includes/iterators


OBJS_VECTOR		= $(addprefix $(OBJS_PATH),$(SRCS_VECTOR:.cpp=.o))
OBJS_MAP		= $(addprefix $(OBJS_PATH),$(SRCS_MAP:.cpp=.o))

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@ mkdir -p $(OBJS_PATH)
	$(CXX) $(INC) $(CXXFLAGS) -c $< -o $@

all: $(VECTOR) $(MAP)

$(VECTOR): $(OBJS_VECTOR)
	$(CXX) $(OBJS_VECTOR) $(INC) -o $(VECTOR)

$(MAP): $(OBJS_MAP)
	$(CXX) $(OBJS_MAP) $(INC) -o $(MAP)

clean: 
	$(RM) $(OBJS_VECTOR) $(OBJS_MAP) $(OBJS_PATH)

fclean: clean
	$(RM) $(VECTOR) $(MAP)

re: clean all

.PHONY: all clean fclean re