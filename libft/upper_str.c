/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:13:56 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/09 20:16:55 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*upper_str(char *str)
{
	int		i;
	char	*new_str;

	new_str = ft_calloc(sizeof(char *), ft_strlen(str));
	if (!new_str)
		return (0);
	i = -1;
	while (str[++i])
		new_str[i] = ft_toupper(str[i]);
	return (new_str);
}