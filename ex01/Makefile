# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ageels <ageels@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/15 14:13:01 by ageels        #+#    #+#                  #
#    Updated: 2023/05/25 16:46:02 by ageels        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = Serialization

FLAGS = -I. -Wall -Werror -Wextra -std=c++98

HDR = Serialization.hpp \
	Data.hpp \

SRC = main.cpp \
	Serialization.cpp \

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