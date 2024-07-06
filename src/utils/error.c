/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:43:51 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/06 02:04:44 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/make_gen.h"

int	error(int err_type)
{
	if (err_type == EXISTING_MAKEFILE)
		ft_putstr_fd(EXISTING_PRINT, 2);
	else if (err_type ==  MALLOC_FAIL)
		ft_putstr_fd(ALLOCATION_FAIL, 2);
	return (0);
}