/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:19:52 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/06 18:20:12 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/make_gen.h"

int	create_name(t_make	*make, char *name)
{
	t_vars *vars;

	vars = make->variables;
	if (!name)
	{
		char *cwd = getcwd(0, 0);
		if (!cwd)
			return (0); 
		vars->name = ft_strdup(ft_strrchr(cwd, '/'));
		free(cwd);
		if (!vars->name)
			return (errror(ALLOCATION_FAIL));
	}
	else
		vars->name = ft_strdup(name);
	return (1);
}
