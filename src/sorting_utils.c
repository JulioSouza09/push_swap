/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:37:14 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/25 15:43:55 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack **a)
{
	t_stack	*i;
	int		min;

	if (!*a)
		return ;
	i = *a;
	min = i->content;
	while (i->next)
	{
		if (min > i->content)
			min = i->content;
		i = i->next;
	}
	ft_printf("min = %d\n", min);
}
