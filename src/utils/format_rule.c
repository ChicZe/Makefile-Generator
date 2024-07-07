/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_rule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:26:24 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/07 19:57:10 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/make_gen.h"

char	*align_src(char *str)
{
	char	*temp;
	char	*formatted;

	temp = ft_strdup(str);
	formatted = ft_strjoin(temp, " \\\n\t\t");
	ft_free(temp);
	ft_free(str);
	return  (formatted);
}

char	*format_src(char *src)
{
	char	*formatted_src;
	int		i;
	char	**c_files;
	char	*temp;
	int		curr_len;

	curr_len = 0;
	formatted_src = ft_strdup("");
	i = -1;
	c_files = ft_split(src, '\n');
	while (c_files[++i])
	{
		temp = ft_strjoin(formatted_src, " ");
		curr_len += ft_strlen(c_files[i]);
		if (curr_len > MAX_FILE_LEN)
		{
			formatted_src = align_src(formatted_src);
			ft_free(temp);
			temp = ft_strdup(formatted_src);
			curr_len = 0;
		}
		ft_free(formatted_src);
		formatted_src = ft_strjoin(temp, c_files[i]);
		ft_free(temp);
	}
	ft_free(src);
	free_matrix(c_files);
	return (formatted_src);
}
