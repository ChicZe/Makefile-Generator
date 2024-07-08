/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:28:40 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/08 02:18:53 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/make_gen.h"

int	setup_all(t_vars *vars)
{
	char	*temp;
	
	vars->all = ft_strdup("%.o: %.c\n\t\t$(COMPILE) -c $< -o %@\
	\n\n$(NAME): $(OBJS)\n\t\t");
	//manage_includes(0, 0);
	temp = ft_strdup(vars->all);
	ft_free(vars->all);
	if (vars->libft)
	{
		vars->all = ft_strjoin(temp, "make -C $(LIBFT_PATH)\n");
		ft_free(temp);
		temp = ft_strjoin(vars->all, "$(COMPILE) $(OBJS) -o $(NAME) $(LIBFT)");
		ft_free(vars->all);
		vars->all = ft_strdup(temp);
	}
	else
		vars->all = ft_strjoin(temp, "$(COMPILE) $(OBJS) -o $(NAME)");
	ft_free(temp);
	//vars->all = ft_strjoin(temp, "-c $< -o $@");
	return (1);
}

int	setup_basic_rules(t_make *make)
{
	t_vars	*vars;
	t_flags	*flags;

	flags = make->flag;
	(void)flags;
	vars = make->variables;
	setup_all(vars);
	
	return (1);	
}
