/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:19:48 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/07 02:45:07 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/make_gen.h"

t_all_flags flags_database[TOTAL_FLAGS] = {
    {"name", "Chose the program name", 1},
    {"libft", "Disable/Enable libft", 2},
    {"compile", "Add different compilation flags", 3},
    {"link", "Add a link on compilation", 4},
	{"update", "Update new c files", 5},
	{"include", "Include an additionale library {path/to/library}", 6}
};

int	existing_flag(char *flag)
{
	int	i;

	i = -1;
	while (++i < TOTAL_FLAGS)
	{
		if (!ft_strncmp(flag, flags_database[i].flag_name, ft_strlen(flag)))
			return (flags_database[i].type);
	}
	return (0);
}

int	check_flags(char *flag)
{
	int		type;
	char	**flag_value;
	
	flag_value = ft_split(flag, '=');
	if (!flag_value)
		return (error(MALLOC_FAIL));
	type = existing_flag(flag_value[0]);
	if (!type)
		return (0);
	printf("type = %d\n", type);
	free_matrix(flag_value);
	return (type);
}

int	parse_flags(t_make *make, int argc, char **argv)
{
	int		i;
	char	*flag;
	int		type;

	i = 0;
	while (++i < argc)
	{
		flag = ft_strtrim(argv[i], "\"");
		if (!flag)
			return (error(MALLOC_FAIL));
		type = check_flags(flag);	// check if the flag exist and return the type corrisponding to the correct flag
		if (!type)
			return (ft_free(flag), 0);
		else if (type == 5 && argc > 2)
			return (error(UPDATE_USAGE));
		if (!flags_manager(make, flag, type))	// perform the actual flag given the argument and the corrisponding type
			return (ft_free(flag), 0);
		ft_free(flag);
	}
	return (1);
}
