/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:28:56 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/06 02:05:40 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/make_gen.h"

void	init_vars(t_vars *vars)
{
	vars->compilation = 0;
	vars->link = 0;
	vars->name = 0;
	vars->src = 0;
}

t_flags	*init_flags(t_flags *flags)
{
	flags->compile = 0;
	flags->libft = 0;
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