/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:27:05 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/13 20:57:47 by ubuntu           ###   ########.fr       */
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

t_stack *ft_rr(t_stack *a)
{
	t_stack	*first;
	t_stack	*last;
	
	if (ft_stack_size(a) == 1)
		return(a);
	first = ft_top(a);
	last = ft_bottom(a);
	last -> prev ->next = NULL;
	first -> prev = last;
	last -> next = first;
	last -> prev = NULL;
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

t_stack *ft_s(t_stack *stack)
{
	t_stack *second;
	stack = ft_top(stack);
	if (ft_stack_size(stack) == 1)
		return (NULL);
	second = stack -> next;
	if (stack -> next -> next)
		stack -> next -> next -> prev = stack;
	stack -> next -> prev = NULL;
	stack -> prev = stack -> next;
	stack -> next = stack -> next-> next;
	second->next = stack;
	return(ft_top(stack));
}