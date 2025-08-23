/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:07:43 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/23 12:14:31 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_prepr
{
	char	**input;
	int		is_freeable;
	int		len;
}	t_prepr;

/***** Stack utils *****/
t_stack	*create_new_node(int content);
t_stack	**create_stack(void);
void	free_stack(t_stack **head);
void	push_to_stack(t_stack **head, t_stack *node);
int		fill_stack(t_stack **head, int argc, char **argv);

/***** Parser utils *****/
char	*skip_spaces(char *str);
long	ft_atol(char *str);
int		is_duplicate(t_stack **head, int nbr);
int		prep_input(t_prepr *vars, int argc, char **argv);

/***** Utils *****/
void	free_matrix(char **matrix);
int		count_matrix(char **matrix);

#endif
