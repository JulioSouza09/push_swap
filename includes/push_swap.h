/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:07:43 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/22 16:03:55 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TEST "Header file is working correctly!\n"

#include "libft.h"

typedef struct	s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

/***** Stack utils *****/
t_stack	*create_new_node(int content);
void	free_stack(t_stack **head);
void	push_to_stack(t_stack **head, t_stack *node);
int		fill_stack(t_stack **head, int argc, char **argv);

/***** Utils *****/
char	*skip_spaces(char *str);
long	ft_atol(char *str);

#endif
