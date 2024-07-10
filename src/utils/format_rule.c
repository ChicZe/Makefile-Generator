/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_rule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:26:24 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/10 01:23:16 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/make_gen.h"

/*char	**tokenize_include(char	*path)
{
	char	*cmd;
	char	*temp;
	char	*include[2];
	char	*name;

	cmd = ft_strjoin("ls ", path);
	temp = ft_strdup(cmd);
	ft_free(cmd);
	cmd = ft_strjoin(temp, " | grep *.a");
	ft_free(temp);
	name = get_cmd_output(cmd);
	temp = ft_strjoin(ft_strmapi(name - 2, ft_toupper), " = "); 
	char *var = ft_strjoin(temp, name);
	ft_free(temp);
	include[0] = ft_strdup(var);
	ft_free(var);
	return (include);
}*/


char	*var_declaration(char *name)
{
	char	*temp;
	char	*new_var;
	char	*upper_name;
	
	if (!name)
		return (0);
	upper_name = upper_str(name);
	temp = ft_strjoin("(", upper_name);
	new_var = ft_strjoin(temp, ")");
	ft_free(temp);
	ft_free(upper_name);
	return (new_var);
}

char	*get_cmd_output(char *cmd)
{
	FILE	*bash_cmd;
	char	buf[256];
	char	*out;

	out = 0;
	bash_cmd = popen(cmd, "r");
	if (!cmd)
		return (error(GENERIC_ERROR), NULL);
	while (fgets(buf, sizeof(buf), bash_cmd) != 0) {
		out = ft_strdup(buf);
		break ;
	}
	ft_free(cmd);
	pclose(bash_cmd);
	return (out);
}

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
