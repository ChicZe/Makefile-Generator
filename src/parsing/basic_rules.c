/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:28:40 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/09 19:16:55 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/make_gen.h"

int	setup_fclean(t_vars *vars)
{
	char	*temp;

	if (vars->libft)
	{
		temp = ft_strdup(vars->fclean);
		ft_free(vars->fclean);
		vars->fclean = ft_strjoin(temp, "make -C $(LIBFT_PATH) fclean\n\t\t");
		ft_free(temp);
	}
	temp = ft_strdup(vars->fclean);
	vars->fclean = ft_strjoin(temp, "rm -rf $(NAME)");
	ft_free(temp);
	return (1);
}

int	setup_clean(t_vars *vars)
{
	char	*temp;
	
	if (vars->libft)
	{
		temp = ft_strdup(vars->clean);
		ft_free(vars->clean);
		vars->clean = ft_strjoin(temp, "make -C $(LIBFT_PATH) clean\n\t\t");
		ft_free(temp);
	}
	temp = ft_strdup(vars->clean);
	vars->clean = ft_strjoin(temp, "rm -rf $(OBJS)");
	printf("clean = %s\n", vars->clean);
	ft_free(temp);
	return (1);
}

int	setup_all(t_vars *vars)
{
	char	*temp;
	
	vars->all = ft_strdup("%.o: %.c\n\t\t$(COMPILE) -c $< -o $@\
	\n$(NAME): $(OBJS)\n\n\t\t");
	//manage_includes(0, 0);
	temp = ft_strdup(vars->all);
	ft_free(vars->all);
	if (vars->libft)
	{
		vars->all = ft_strjoin(temp, "make -C $(LIBFT_PATH)\n\t\t");
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
	setup_clean(vars);
	setup_fclean(vars);
	return (1);	
}
