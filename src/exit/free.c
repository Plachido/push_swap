/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:06:42 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/15 12:08:39 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_free_stack(t_stack *elem)
{
	t_stack	*next;

	if (!elem)
		return ;
	next = NULL;
	elem = ft_top(elem);
	while (elem -> next)
	{
		next = elem -> next;
		free(elem);
		elem = next;
	}
	if (next)
		free(next);
}

void	ft_malloc_error(int numbers[], t_stack *stack)
{
	if (stack)
		ft_free_stack(stack);
	free(numbers);
	ft_exit(1);
}

void	ft_free(t_stack *a, t_stack *b)
{
	if (a)
		ft_free_stack(a);
	if (b)
		ft_free_stack(b);
}
