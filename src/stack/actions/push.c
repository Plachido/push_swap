/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:14:19 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/15 10:17:27 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	ft_move(t_stack *from, t_stack *des)
{
	des = ft_top(des);
	des -> prev = from;
	from -> prev = NULL;
	from -> next = des;
	des = des -> prev;
}

t_stack	*ft_p(t_stack **src, t_stack *des)
{
	t_stack	*from;
	t_stack	*new_top;

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
		ft_move(from, des);
	else
	{
		des = from;
		des -> next = NULL;
		des->prev = NULL;
	}
	*src = new_top;
	return (des);
}
