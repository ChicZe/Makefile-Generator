/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:26:31 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/08 02:07:18 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/make_gen.h"

int	write_makefile(t_make *make)
{
	t_vars *vars;
	int		ret;

	vars = make->variables;
	//? write name of the program
	ret = write(make->fd, "NAME = ", 7);
	ret = write(make->fd, vars->name, ft_strlen(vars->name));
	ret = write(make->fd, "\n", 1);
	ret = write(make->fd, "\n", 1);
	//? write libft if present
	ret = write (make->fd, "LIBFT_PATH = ", 13);
	ret = write(make->fd, vars->libft, ft_strlen(vars->libft));
	ret = write(make->fd, "\n", 1);
	ret = write (make->fd, "LIBFT = $(addprefix, LIBFT_PATH, libft.a)", 41);
	ret = write(make->fd, "\n", 1);
	ret = write(make->fd, "\n", 1);
	/*ret = write(make->fd, vars->include_var, ft_strlen(vars->include_var))
	ret = write(make->fd, "\n", 1);
	ret = write(make->fd, "\n", 1);*/
	//? write sources files
	ret = write (make->fd, "SRC =", 5);
	printf("vars->src = %s\n", vars->src);
	ret = write(make->fd, vars->src, ft_strlen(vars->src));
	ret = write(make->fd, "\n", 1);
	ret = write(make->fd, "\n", 1);
	//? write object files
	ret = write(make->fd, OBJS, ft_strlen(OBJS));
	ret = write(make->fd, "\n", 1);
	ret = write(make->fd, "\n", 1);
	//? write compilation flags
	write (make->fd, "COMPILATION = ", 14);
	ret = write(make->fd, vars->compilation, ft_strlen(vars->compilation));
	ret = write(make->fd, "\n", 1);
	ret = write(make->fd, "\n", 1);
	//? write 'all' rule
	ret = write (make->fd, "all: $(NAME)\n\t\t", 13);
	ret = write(make->fd, vars->all, ft_strlen(vars->all));
	ret = write(make->fd, "\n", 1);
	ret = write(make->fd, "\n", 1);
	//? write 'clean' rule
	ret = write (make->fd, "clean:\n\t\t", 9);
	ret = write(make->fd, vars->clean, ft_strlen(vars->clean));
	ret = write(make->fd, "\n", 1);
	ret = write(make->fd, "\n", 1);
	//? write 'fclean' rule
	ret = write (make->fd, "fclean: clean\n\t\t", 16);
	ret = write(make->fd, vars->fclean, ft_strlen(vars->fclean));
	ret = write(make->fd, "\n", 1);
	ret = write(make->fd, "\n", 1);
	//? write '.PHONY'
	ret = write(make->fd, ".PHONY: all clean fclean\n", 24);
	ret = write(make->fd, "\n", 1);
	if (ret ==  -1)
		return (error("Fatal Error: Something went wrong with write()"));
	return (1);
}

int	create_file(t_make *make)
{
	make->fd = open("Makefile", O_RDONLY);
	if (make->fd != -1)
		return (error(EXISTING_MAKEFILE));
	make->fd = open("Makefile", O_RDWR | O_CREAT, 0777);
	if (make->fd == -1)
		return (0);
	return (1);
}
