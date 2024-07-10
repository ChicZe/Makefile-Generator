/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:21:21 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/10 00:44:12 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#define	TOTAL_FLAGS 6

typedef	struct	s_all_flags
{
	char	*flag_name;
	char	*description;
	int		type;
}				t_all_flags;

typedef struct s_vars
{
	int			n_flags;
	char		*name;
	char		*src;
	char		*compilation;
	char		*link;
	char		*libft;
	char		*include;
	char		*declaration; // declare the variables for the additional includes
	char		*all;
	char		*clean;
	char		*fclean;
}				t_vars;

/* maybe i dont need this */
typedef struct s_flags
{
	int	name;
	int	libft;
	int	compile;
	int	libs;
	int	update;
	int	link;
}				t_flags;

typedef struct s_make
{
	char	**flags;
	char	*input;
	int		fd;
	char	**c_src;
	t_vars	*variables;
	t_flags	*flag;
}				t_make;


#endif