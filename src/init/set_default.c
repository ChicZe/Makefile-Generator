/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:08:48 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/08 01:37:07 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/make_gen.h"

char	*get_name(void)
{
	char	*name;
	char	*cwd = getcwd(0, 0);
	if (!cwd)
		return (0);
	 name = ft_strdup(ft_strrchr(cwd, '/'));
	ft_free(cwd);
	if (!name)
		return (error(ALLOCATION_FAIL), NULL);
	char *ret = ft_strdup(name + 1);
	ft_free(name);
	return (ret);
}

char	*get_src(void)
{
	FILE	*cmd;
	char	buf[256];
	char	*srcs;
	char	*temp;

	srcs = ft_strdup("");
	cmd = popen(GET_C_FILES, "r");
	if (!cmd)
		return (error(GENERIC_ERROR), NULL);
	while (fgets(buf, sizeof(buf), cmd) != 0) {
		temp = ft_strdup(srcs);
		ft_free(srcs);
		srcs = ft_strjoin(temp, buf + 2);
		free(temp);		
	}
	pclose(cmd);
	return (format_src(srcs));
}
