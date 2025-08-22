/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:03:04 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/22 16:07:58 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
