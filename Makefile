SRCS_VECTOR		=	vector.cpp		
SRCS_MAP		=	map.cpp		
SRCS_FTVECTOR		=	ft_vector.cpp		
SRCS_FTMAP		=	ft_map.cpp		


VECTOR	= vector
MAP		= map
FTVECTOR	= ft_vector
FTMAP		= ft_map

CXX		= clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM		= rm -rf

SRCS_PATH			=	./srcs/
OBJS_PATH			=	.objs/
INC					= -I includes/containers/vector -I includes/containers/map -I includes/iterators


OBJS_VECTOR		= $(addprefix $(OBJS_PATH),$(SRCS_VECTOR:.cpp=.o))
OBJS_MAP		= $(addprefix $(OBJS_PATH),$(SRCS_MAP:.cpp=.o))

OBJS_FTVECTOR		= $(addprefix $(OBJS_PATH),$(SRCS_FTVECTOR:.cpp=.o))
OBJS_FTMAP		= $(addprefix $(OBJS_PATH),$(SRCS_FTMAP:.cpp=.o))

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@ mkdir -p $(OBJS_PATH)
	@ mkdir -p results
	$(CXX) $(INC) $(CXXFLAGS) -c $< -o $@

all: $(VECTOR) $(MAP) $(FTVECTOR) $(FTMAP)

$(VECTOR): $(OBJS_VECTOR)
	$(CXX) $(OBJS_VECTOR) $(INC) -o $(VECTOR)

$(MAP): $(OBJS_MAP)
	$(CXX) $(OBJS_MAP) $(INC) -o $(MAP)

$(FTVECTOR): $(OBJS_FTVECTOR)
	$(CXX) $(OBJS_FTVECTOR) $(INC) -o $(FTVECTOR)

$(FTMAP): $(OBJS_FTMAP)
	$(CXX) $(OBJS_FTMAP) $(INC) -o $(FTMAP)

clean: 
	$(RM) $(OBJS_VECTOR) $(OBJS_MAP) $(OBJS_FTVECTOR) $(OBJS_FTMAP) $(OBJS_PATH)
	$(RM) results

fclean: clean
	$(RM) $(VECTOR) $(MAP) $(FTVECTOR) $(FTMAP)

re: clean all

.PHONY: all clean fclean re