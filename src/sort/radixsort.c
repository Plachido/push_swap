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

static int	ft_stack_ordered(t_stack *a)
{
	a = ft_top(a);
	while (a)
	{
		if ((a -> prev) && (a -> num <  a -> prev -> num))
			return(0);
		a = a -> next;
	}
	return (1);
}
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
			if (ft_stack_size(a) == size && ft_stack_ordered(a))
				return (a);
			num = a-> num;
			if (((num >> i) & 1) == 1)
			{
				ft_putendl("ra");
				a = ft_r(a);
			}
			else
			{
				ft_putendl("pb");
				b = ft_p(&a, b);
				a = ft_top(a);
			}
		}
		while (ft_stack_size(a) < size)
		{
			ft_putendl("pa");
			a = ft_p(&b, a);
		}
		a = ft_top(a);
	}
	return (a);
}
