/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:28:56 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/07 19:27:26 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/make_gen.h"

static void	init_vars(t_vars *vars)
{
	vars->name = get_name();
	vars->libft = ft_strdup(LIBFT_PATH);
	vars->src = get_src();
	//printf("vars->src = %s\n", vars->src);
	vars->compilation = ft_strdup(DEFAULT_FLAGS);
	vars->link = 0;
	vars->all = 0;
	vars->include = 0;
	vars->clean = 0;
	vars->fclean = 0;
}

static t_flags	*init_flags(t_flags *flags)
{
	flags->compile = 0;
	flags->libft = 0;
	flags->name = 42;
	flags->libs = 0;
	flags->link = 0;
	flags->update = 0;
	return (flags);
}

int	init_all(t_make *make)
{
	t_vars	*vars;
	t_flags *flags;
	//(void)vars;
	//make = malloc(sizeof(t_make));
	//if (!make)
		//return (error(MALLOC_FAIL));
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (error(MALLOC_FAIL));
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (error(MALLOC_FAIL));
	make->flag = flags;
	make->variables = vars;
	init_flags(flags);
	init_vars(vars);
	return (1);
}
