/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:21:21 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/06 01:31:16 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vars
{
	char	*name;
	char	**src;
	char	*compilation;
	char	*link;
}				t_vars;

typedef struct s_flags
{
	int	libft;
	int	compile;
	int	libs;
	int	update;
	int	link;
}				t_flags;

typedef struct s_make
{
	char	*input;
	int		fd;
	t_vars	*variables;
	t_flags	*flag;
}				t_make;


#endif