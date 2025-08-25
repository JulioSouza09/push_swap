/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:37:14 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/25 19:06:59 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->previous && tmp->previous->content > tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_two(t_stack **a)
{
	if (!a || !*a)
		return ;
	if ((*a)->content > (*a)->next->content)
		ft_putendl_fd(swap(a, "sa"), 1);
}

void	sort_three(t_stack **a)
{
	if (!a || !*a)
		return ;
	while (!is_sorted(a))
	{
		if ((*a)->content > (*a)->next->content)
			ft_putendl_fd(swap(a, "sa"), 1);
		if (!is_sorted(a))
			ft_putendl_fd(reverse_rotate(a, "rra"), 1);
	}
}

void	execute_single(t_stack **a, t_stack **b, char *op);

void	sort_four(t_stack **a, t_stack **b);

void	sort_stack(int a_size, t_stack **a, t_stack **b)
{
	if (a_size == 2)
		sort_two(a);
	if (a_size == 3)
		sort_three(a);
	(void)b;
}
