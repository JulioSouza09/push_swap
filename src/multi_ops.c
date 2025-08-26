/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:49:45 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/26 09:50:06 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, "ra");
	rotate(b, "rb");
	ft_putendl_fd("rr", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, "rra");
	reverse_rotate(b, "rrb");
	ft_putendl_fd("rrr", 1);
}
