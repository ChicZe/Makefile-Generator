/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:09:16 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/07 18:31:40 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/make_gen.h"

void	quit(t_make *make)
{
	t_vars *vars;
	t_flags *flags;

	vars = make->variables;
	flags = make->flag;
	ft_free(vars->all);
	ft_free(vars->clean);
	ft_free(vars->compilation);
	ft_free(vars->fclean);
	ft_free(vars->libft);
	ft_free(vars->link);
	ft_free(vars->name);
	ft_free(vars->include);
	ft_free(vars->src);
	ft_free(vars);
	ft_free(flags);
	//close(make->fd);
	exit(error_status);
}
