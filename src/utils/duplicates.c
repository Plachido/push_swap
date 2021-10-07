/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:38:37 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/07 19:43:54 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_duplicates(t_stack *stack)
{
	int		num;
	t_stack	*loop;

	while (stack -> next)
	{
		loop = stack -> next;
		while (loop -> next)
		{
			if (loop -> num == stack -> num)
			{
				ft_free_stack(stack);
				ft_exit(3);
			}
			loop = loop -> next;
		}
		if (loop -> num == stack -> num)
		{
			ft_free_stack(stack);
			ft_exit(3);
		}
		stack = stack -> next;
	}
}
