/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_datas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:46:08 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/07 02:49:42 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/make_gen.h"

int	libft_flag(t_vars *vars, char *libft)
{
	if (!ft_strncmp(libft, "no", 3))
	{
		ft_free(vars->libft);
		vars->libft = ft_strdup("");
	}
	else
	{
		ft_free(vars->libft);
		char *path = ft_strdup(libft);
		vars->libft = ft_strjoin("LIBFT_PATH = ", path);
		ft_free(path);
	}
	return (1);
}

int	name_flag(t_vars *vars, char *name)
{
	if (!name)
		return (error(NAME_USAGE));
	ft_free(vars->name);
	vars->name = ft_strdup(name);
	return (1);
}

int	flags_manager(t_make *make, char *flag, int type)
{
	int		fail;
	char	**key_value;
	t_vars	*vars;

	key_value = ft_split(flag, '=');
	if (!key_value)
		return (error(MALLOC_FAIL));
	vars = make->variables;
	if (type == 1)
		fail = name_flag(vars, key_value[1]);
	else if (type == 2)
		fail = libft_flag(vars, key_value[1]);
	else if (type == 3)
		;//
	else if (type == 4)
		;//
	else if (type == 5)
		;//
	else if (type == 6)
		return (0);
	free_matrix(key_value);
	if (!fail)
		return (0);
	return (1);	
}