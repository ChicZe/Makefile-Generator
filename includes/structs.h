/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:21:21 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/08 02:08:16 by ciusca           ###   ########.fr       */
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

typedef	struct s_include
{
	char				*var_name;
	char				*path;
	char				*include_file;
	struct s_include	*next;
}				t_include;


typedef struct s_vars
{
	char		*name;
	char		*src;
	char		*compilation;
	char		*link;
	char		*libft;
	char		*include;
	char		*include_var;
	char		*all;
	char		*clean;
	char		*fclean;
}				t_vars;

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