/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:38:37 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/13 18:43:59 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_duplicates(t_stack *stack)
{
	t_stack	*loop;

	while (stack -> next)
	{
		loop = stack -> next;
		while (loop -> next)
		{
			if (loop -> num == stack -> num)
			{
				ft_free_stack(stack);
				ft_exit(1);
			}
			loop = loop -> next;
		}
		if (loop -> num == stack -> num)
		{
			ft_free_stack(stack);
			ft_exit(1);
		}
		stack = stack -> next;
	}
}
