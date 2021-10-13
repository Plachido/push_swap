/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:32:29 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/12 22:36:52 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

static int ft_min(t_stack *a)
{
	int min;
	
	a = ft_top(a);
	min = a->num;
	while (a)
	{
		if (a->num < min)
			min = a->num;
		a = a->next;
	}
	return(min);
}

static void	ft_fix_rotation(t_stack *a, int ra, int rra)
{
	a = ft_top(a);
	if (ra <= rra)
		while (ra--)
		{
			ft_putendl("ra");
			ft_r(a);
		}
	else
		while (rra--)
		{
			ft_putendl("rra");
			ft_rr(a);
		}
}

static int	ft_stack_ordered(t_stack *a, int len)
{
	int i;
	int index;
	int min;
	int sum;
	
	i = 0;
	index = 1;
	a = ft_top(a);
	min = ft_min(a);
	while (a -> num != min)
	{
		a = a->next;
		index++;
	}
	while(++i < len)
	{
		if (a->next)
		{
			if (a->next->num < a->num)
				return(0);
			a = a->next;
		}
		else
		{
			if (ft_top(a)->num < a->num)
				return(0);
			a = ft_top(a);
		}
	}
	sum = 0;
	if (len%2 != 0)
		sum = 1;
	while(ft_top(a) -> num != min)
	{
		if (index > ((len + sum)/2))
		{
			ft_putendl("rra");
			ft_rr(a);
		}
		else
		{
			ft_putendl("ra");
			ft_r(a);
		}
	}
	return(1);
}

t_stack	*ft_sort(t_stack *a, t_stack *b, int len)
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
			if (ft_stack_size(a) == size && ft_stack_ordered(a, len))
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
