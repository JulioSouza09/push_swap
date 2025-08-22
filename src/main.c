/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:37:12 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/22 15:58:35 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
	t_stack	**head;

	head = malloc(sizeof(t_stack *));
	if (!head)
		return (1);
	*head = NULL;
	if(fill_stack(head, argc, argv))
	{
		ft_putendl_fd("Error", 2);
		free_stack(head);
		return (2);
	}
	print_stack(head);
	free_stack(head);
	return (0);
}
