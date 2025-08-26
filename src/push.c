/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:56:58 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/26 10:06:09 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	tmp = pop_from_stack(src);
	if (!tmp)
		return ;
	push_to_stack(dst, tmp);
}

void	pa(t_stack **a, t_stack **b)
{
	push (a, b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **b, t_stack **a)
{
	push (b, a);
	ft_putendl_fd("pb", 1);
}
