# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 00:37:58 by ciusca            #+#    #+#              #
#    Updated: 2024/07/06 01:53:26 by ciusca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = makegen

LIBFT_PATH = libft/
LIBFT = libft/libft.a

INIT_SRC = init_structs.c
CREATE_SRC = create_file.c
UTILS_SRC = error.c
MAIN = main.c

INIT = $(addprefix init/, $(INIT_SRC))
CREATE = $(addprefix create/, $(CREATE_SRC))
UTILS = $(addprefix utils/, $(UTILS_SRC))

FILES = $(MAIN) $(INIT) $(CREATE) $(UTILS)

SRC = $(addprefix src/, $(FILES))

OBJS = ${SRC:.c=.o}

COMPILE = cc -Wall -Wextra -Werror -g

RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
MAGENTA = "\033[1;35m"
CYAN = "\033[1;36m"
WHITE = "\033[1;37m"
NONE = "\033[0m"

all: ${NAME}
%.o: %.c
		$(COMPILE) -I $(LIBFT_PATH) -c $< -o $@

${NAME}: ${OBJS}
		make -C ${LIBFT_PATH}
		$(COMPILE) $(OBJS) -o $(NAME) $(LIBFT)
		rm -rf $(OBJS)
		make -C $(LIBFT_PATH) clean
		@echo $(YELLOW)compilation completed!$(NONE)

fclean:
		@rm -rf $(NAME)
		@make -C $(LIBFT_PATH) fclean

re: fclean all


.PHONY: all fclean

.SILENT:

.DEFAULT:
	@echo "Usage: to do"