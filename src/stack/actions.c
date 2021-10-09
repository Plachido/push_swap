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

t_stack	*ft_r(t_stack *a)
{
	t_stack	*first;
	t_stack	*last;
	
	if (ft_stack_size(a) == 1)
		return(a);
	first = ft_top(a);
	last = ft_bottom(a);
	first -> next -> prev = NULL;
	first -> next = NULL;
	first -> prev = last;
	last -> next = first;
	return (ft_top(a));
}

t_stack	*ft_p(t_stack **src, t_stack *des)
{
	t_stack *from;
	t_stack *new_top;

	from = *src;
	from = ft_top(from);
	if (ft_stack_size(from) > 1)
	{
		from -> next -> prev = NULL;
		new_top = from ->next;
	}
	else
		new_top = NULL;
	if (des)
	{
		des = ft_top(des);
		des -> prev = from;
		from -> prev = NULL;
		from -> next = des;
		des = des -> prev;
	}
	else
	{
		des = from;
		des -> next = NULL;
	}
	*src = new_top;
	return (des);
}
