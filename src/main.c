/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:37:12 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/24 19:55:45 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp)
	{
		ft_printf("content: %d\t", tmp->content);
		if (tmp->next)
			ft_printf("next: %d\t\t", tmp->next->content);
		if (tmp->previous)
			ft_printf("previous: %d", tmp->previous->content);
		ft_printf("\n");
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_prepr	ini;
	t_stack	**a;
	t_stack	**b;

	if (argc == 1)
		return (1);
	a = create_stack();
	if (!a)
		return (1);
	b = create_stack();
	if (!b)
		return (2);
	if (prep_input(&ini, argc, argv) || fill_stack(a, ini.len, ini.input))
	{
		ft_putendl_fd("Error", 2);
		free_stack(a);
		if (ini.is_freeable)
			free_matrix(ini.input);
		return (3);
	}
	if (ini.is_freeable)
		free_matrix(ini.input);
	push(b, a);
	push(b, a);
	push(b, a);
	print_stack(a);
	ft_printf("\n");
	print_stack(b);
	ft_printf("\n");
	rrr(a, b);
	print_stack(a);
	ft_printf("\n");
	print_stack(b);
	ft_printf("\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
