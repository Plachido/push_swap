/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:29:48 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/15 10:24:14 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	ft_max(t_stack *stack)
{
	int	max;

	stack = ft_top(stack);
	max = stack -> num;
	while (stack -> next)
	{
		stack = stack -> next;
		if (stack -> num > max)
			max = stack -> num;
	}
	return (max);
}

int	ft_max_bits(t_stack *stack)
{
	int	max;
	int	max_bits;

	max_bits = 0;
	max = ft_max(stack);
	while ((max >> max_bits) != 0)
		++max_bits;
	return (max_bits);
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	stack = ft_top(stack);
	while (stack -> next)
	{
		stack = stack -> next;
		++size;
	}
	return (++size);
}

int	ft_min(t_stack *a)
{
	int	min;

	a = ft_top(a);
	min = a->num;
	while (a)
	{
		if (a->num < min)
			min = a->num;
		a = a->next;
	}
	return (min);
}
