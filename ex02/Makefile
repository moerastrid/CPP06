# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ageels <ageels@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/15 14:13:01 by ageels        #+#    #+#                  #
#    Updated: 2023/05/25 17:29:02 by ageels        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = Identify_real_type

FLAGS = -I. -Wall -Werror -Wextra -std=c++98

HDR = Base.hpp \
	A.hpp \
	B.hpp \
	C.hpp \

SRC = main.cpp \
	Base.cpp \
	A.cpp \
	B.cpp \
	C.cpp \

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME) : $(OBJ) $(HDR)
	c++ $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR) : 
	mkdir -pv $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -fr $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re