/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:22:20 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/07 19:20:10 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack	*ft_get_head(t_stack *elem)
{
	while (elem -> prev)
		elem = elem -> prev;
	return (elem);
}

static t_stack	*ft_new_stack(int number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> num = number;
	new ->prev = NULL;
	new -> next = NULL;
	return (new);
}

static t_stack	*ft_add_to_stack(t_stack *last, int num)
{
	t_stack	*new;

	new = ft_new_stack(num);
	if (!new)
		return (NULL);
	new ->num = num;
	if (last)
	{
		new -> prev = last;
		last -> next = new;
	}
	return (new);
}

t_stack	*ft_char_to_stack(int len, char **numbers)
{
	int		i;
	t_stack	*elem;

	elem = ft_new_stack(ft_atoi_err(numbers[1]));
	if (!elem)
		return (NULL);
	i = 1;
	while (++i < len)
	{
		elem = ft_add_to_stack(elem, ft_atoi_err(numbers[i]));
		if (!elem)
		{
			ft_free_stack(elem);
			ft_exit(1);
		}
	}
	return (ft_get_head(elem));
}
