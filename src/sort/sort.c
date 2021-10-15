/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:32:29 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/15 12:10:20 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_choose_rotation(t_stack **a, int num, int len, int index)
{
	int	sum;

	if (len % 2 != 0)
		sum = 1;
	while (ft_top(*a)-> num != (num))
	{
		if (index > ((len + sum) / 2))
		{
			ft_putendl("rra");
			ft_rr(*a);
		}
		else
		{
			ft_putendl("ra");
			ft_r(*a);
		}
	}
}

static void	ft_choose_r_p(int i, int num, t_stack **a, t_stack **b)
{
	if (((num >> i) & 1) == 1)
	{
		ft_putendl("ra");
		*a = ft_r(*a);
	}
	else
	{
		ft_putendl("pb");
		*b = ft_p(a, *b);
		*a = ft_top(*a);
	}
}

void	ft_push_back(t_stack **a, t_stack **b, int size)
{
	while (ft_stack_size(*a) < size)
	{
		ft_putendl("pa");
		*a = ft_p(b, *a);
	}
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
			ft_choose_r_p(i, num, &a, &b);
		}
		ft_push_back(&a, &b, size);
		a = ft_top(a);
	}
	return (a);
}
