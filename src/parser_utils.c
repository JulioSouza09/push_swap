/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:43:10 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/25 15:22:28 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prep_input(t_prepr *vars, int argc, char **argv)
{
	vars->is_freeable = 0;
	vars->len = argc - 1;
	vars->input = &argv[1];
	if (argc == 2)
	{
		vars->is_freeable = 1;
		vars->input = ft_split(argv[1], ' ');
		if (!vars->input)
			return (2);
		vars->len = count_matrix(vars->input);
		if (vars->len == 0)
		{
			free_matrix(vars->input);
			return (3);
		}
	}
	return (0);
}

int	is_duplicate(t_stack **head, int nbr)
{
	t_stack	*tmp;

	if (!*head)
		return (0);
	tmp = *head;
	while (tmp)
	{
		if (tmp->content == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char	*skip_spaces(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	return (str);
}

long	ft_atol(char *str)
{
	long	result;
	int		sig;

	result = 0;
	sig = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * (long)sig);
}
