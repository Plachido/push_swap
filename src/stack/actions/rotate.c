/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:10:10 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/15 10:10:48 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

t_stack	*ft_r(t_stack *a)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_stack_size(a) == 1)
		return (a);
	first = ft_top(a);
	last = ft_bottom(a);
	first -> next -> prev = NULL;
	first -> next = NULL;
	first -> prev = last;
	last -> next = first;
	return (ft_top(a));
}

t_stack	*ft_rr(t_stack *a)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_stack_size(a) == 1)
		return (a);
	first = ft_top(a);
	last = ft_bottom(a);
	last -> prev ->next = NULL;
	first -> prev = last;
	last -> next = first;
	last -> prev = NULL;
	return (ft_top(a));
}
