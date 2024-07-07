# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 00:37:58 by ciusca            #+#    #+#              #
#    Updated: 2024/07/07 19:02:43 by ciusca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = makegen

LIBFT_PATH = libft/
LIBFT = libft/libft.a

INIT_SRC = init_structs.c set_default.c
CREATE_SRC = create_file.c
UTILS_SRC = error.c close_program.c messages.c format_rule.c
PARSING_SRC = parse_flag.c fill_datas.c
MAIN = main.c

PARSING = $(addprefix parsing/, $(PARSING_SRC))
INIT = $(addprefix init/, $(INIT_SRC))
CREATE = $(addprefix create/, $(CREATE_SRC))
UTILS = $(addprefix utils/, $(UTILS_SRC))

FILES = $(MAIN) $(INIT) $(CREATE) $(UTILS) $(PARSING)

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
		@echo $(YELLOW)compilation completed!$(NONE)

valgrind: all
		@valgrind --leak-check=full --show-leak-kinds=all ./makegen
	

clean:
		rm -rf $(OBJS)
		make -C $(LIBFT_PATH) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIBFT_PATH) fclean

re: fclean all


.PHONY: all clean fclean

.SILENT:

.DEFAULT:
	@echo "Usage: to do"