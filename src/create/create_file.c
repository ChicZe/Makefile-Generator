/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:26:31 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/06 02:03:51 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/make_gen.h"

int	create_file(t_make *make)
{
	int	fd;

	fd = open("Makefile", O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (error(EXISTING_MAKEFILE));
	}	
	fd = open("Makefile", O_RDWR | O_CREAT, 0777);
	if (fd == -1)
		return (0);
	make->fd = fd;
	return (1);
}
