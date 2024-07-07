/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:43:51 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/07 18:31:43 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/make_gen.h"

int	error(char *error_msg)
{
	error_status = 1;
	ft_putstr_fd(error_msg, STDERR_FILENO);
	return (0);
}