/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:26:06 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/15 12:17:44 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_three(t_stack **a, int len)
{
	ft_putendl("sa");
	*a = ft_s(*a);
	ft_stack_ordered(*a, len);
}

static void	ft_five(t_stack **a, t_stack **b, int len)
{
	int	sum;
	int	i;
	int	index;

	i = 0;
	sum = 0;
	if (len % 2 != 0)
		sum = 1;
	*a = ft_top(*a);
	while (i++ < len - 2)
	{
		index = 0;
		while ((*a)->num != i - 1)
		{
			*a = (*a)->next;
			index++;
		}
		ft_choose_rotation(a, i - 1, len, index);
		ft_putendl("pb");
		*b = ft_p(a, *b);
	}
	ft_stack_ordered(*a, 2);
	ft_push_back(a, b, len);
}

t_stack	*ft_sort_small(t_stack *a, t_stack *b, int len)
{
	if (ft_stack_ordered(a, len))
		return (a);
	if (len == 3)
		ft_three(&a, len);
	else
	{
		ft_five(&a, &b, len);
	}
	return (ft_top(a));
}
