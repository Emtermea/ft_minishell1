# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 20:46:37 by etermeau          #+#    #+#              #
#    Updated: 2015/12/23 18:24:56 by emtermea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1

LIB = libft/

HEADER = includes/

DIRSRC = srcs/

FLAGS = -Wall -Wextra -Werror

SRC = 	main.c			\
		list.c			\
		read.c			\
		env_to_list.c			\
		builtin_set_env.c			\
		builtin_env.c		\
		builtin_unset_env.c		\
		builtin_cd.c		\
		builtin_echo.c		\
		builtin_pwd.c		\
		builtin_exit.c		\
		parse_command.c			\
		exec.c			\
		misc.c			\

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -s -C $(LIB)
	gcc $(FLAGS) -o $(NAME) $^ -L$(LIB) -lft

%.o: $(DIRSRC)%.c
	gcc $(FLAGS) -o $@ -c $< -I$(LIB)Includes -I$(HEADER)

clean:
	rm -f $(OBJ)
	make clean -s -C $(LIB)

fclean: clean
	rm -f $(NAME)
	make fclean -s -C $(LIB)

re: fclean all
