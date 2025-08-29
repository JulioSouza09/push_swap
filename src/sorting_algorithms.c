/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:42:56 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/28 16:46:40 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if (!a || !*a)
		return ;
	if ((*a)->content < (*a)->next->content)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int	max;

	if (!a || !*a)
		return ;
	max = get_max(a);
	if (max == (*a)->content)
		ra(a);
	while (!is_sorted(a))
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
		if (!is_sorted(a))
			rra(a);
	}
}

void	sort_stack(int a_size, t_stack **a, t_stack **b)
{
	if (a_size == 2)
		sort_two(a);
	else if (a_size == 3)
		sort_three(a);
	(void)b;
}
