/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:27:05 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/08 12:33:19 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_r(t_stack *a)
{
	t_stack	*first;
	t_stack	*last;

	first = ft_top(a);
	last = ft_bottom(a);
	first -> next -> prev = NULL;
	first -> next = NULL;
	first -> prev = last;
	last -> next = first;
}

t_stack	*ft_p(t_stack *from, t_stack *to)
{
	from = ft_top(from);
	if (ft_stack_size(from) > 1)
		from -> next -> prev = NULL;
	if (to)
	{
		to = ft_top(to);
		to -> prev = from;
		from -> prev = NULL;
		from -> next = to;
	}
	else
	{
		to = from;
		to -> next = NULL;
	}
	return (to);
}
