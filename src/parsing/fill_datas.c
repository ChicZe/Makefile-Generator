/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_datas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:46:08 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/10 11:03:02 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/make_gen.h"

int	update(t_make *make)
{
	(void)make;
	//TODO: add update flag to update new '.c' files
	return (0);
}

int	include_flag(t_vars *vars, char *path)
{
	char	*temp;
	char	*name;
	char	*trimmed;
	char	*var;

	if (!path || !ft_strchr(path, '/'))
		return (error("Insert a valid path"));
	
	name = ft_strrchr(path, '/') + 1;	
	trimmed = ft_strtrim(ft_strrchr(path, '/') + 1, ".a");
	temp = ft_strdup(vars->include);
	ft_free(vars->include);
	var = var_declaration(trimmed);
	vars->include = ft_strjoin(temp, var);
	ft_free(var);
	ft_free(temp);
	temp = ft_strjoin(vars->include, " ");
	ft_free(vars->include);
	vars->include = ft_strdup(temp);
	ft_free(temp);
	//temp = ft_strtrim(path, name);
	//ft_free(name);
	name = ft_strjoin(trimmed, "_PATH");
	ft_free(trimmed);
	temp = ft_strdup(vars->include);
	vars->include = ft_strjoin(temp, var_declaration(name));
	ft_free(name);
	return (0);
}

int	link_flag(t_vars *vars, char *link)
{
	if (!link)
		return (error(LINK_USAGE));
	ft_free(vars->link);
	char	*temp;
	temp = ft_strjoin(vars->compilation, " ");
	ft_free(vars->compilation);
	vars->compilation = ft_strjoin(temp, link);
	ft_free(temp);
	return (1);
}

int	compile_flag(t_vars *vars, char *compilation)
{
	if (!compilation)
		return (error(COMPILE_USAGE));
	ft_free(vars->compilation);
	vars->compilation = ft_strdup(compilation);
	return (1);
}

int	libft_flag(t_vars *vars, char *libft)
{
	if (!libft)
		return (error(LIBFT_USAGE));
	if (!ft_strncmp(libft, "no", 3))
	{
		ft_free(vars->libft);
		vars->libft = 0;
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

	fail = 0;
	key_value = ft_split(flag, '=');
	if (!key_value)
		return (error(MALLOC_FAIL));
	vars = make->variables;
	if (type == 1)
		fail = name_flag(vars, key_value[1]);
	else if (type == 2)
		fail = libft_flag(vars, key_value[1]);
	else if (type == 3)
		fail = compile_flag(vars, key_value[1]);
	else if (type == 4)
		fail = link_flag(vars, key_value[1]);
	else if (type == 5)
		fail = update(make);
	else if (type == 6)
		fail = include_flag(vars, key_value[1]);
	free_matrix(key_value);
	if (!fail)
		return (0);
	return (1);	
}
