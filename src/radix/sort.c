/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:32:29 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/08 12:53:09 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack	*ft_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	num;
	int	bits;
	int	size;

	i = -1;
	bits = ft_max_bits(a);
	size = ft_stack_size(a);
	while (++i < bits)
	{
		j = -1;
		while (++j < size)
		{
			num = a-> num;
			if (((num >> i) & 1) == 1)
				ft_r(a);
			else
				b = ft_p(a, b);
		}
		while (ft_stack_size(a) < size)
			ft_p(b, a);
		a = ft_top(a);
	}
	return (a);
}
