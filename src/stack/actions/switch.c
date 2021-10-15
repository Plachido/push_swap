/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:27:05 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/15 10:14:48 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

t_stack	*ft_s(t_stack *stack)
{
	t_stack	*second;

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
	return (ft_top(stack));
}
