/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_ordered.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:25:41 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/15 12:09:39 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	ft_get_index(t_stack **a, int num)
{
	int	index;

	index = 1;
	while ((*a)-> num != num)
	{
		*a = (*a)->next;
		index++;
	}
	return (index);
}

int	ft_stack_ordered(t_stack *a, int len)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	a = ft_top(a);
	min = ft_min(a);
	index = ft_get_index(&a, min);
	while (++i < len)
	{
		if (a->next)
		{
			if (a->next->num < a->num)
				return (0);
			a = a->next;
		}
		else
		{
			if (ft_top(a)->num < a->num)
				return (0);
			a = ft_top(a);
		}
	}
	ft_choose_rotation(&a, min, len, index);
	return (1);
}
