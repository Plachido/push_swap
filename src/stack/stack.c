/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:22:20 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/08 11:30:43 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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

static	t_stack *ft_simplify(t_stack *stack, int values[])
{
	int i;

	while(stack->next)
	{
		i = -1;
		while (values[++i] != stack -> num)
			;
		stack -> num = i + 1;
		stack = stack -> next;
	}
	i = -1;
	while (values[++i] != stack -> num)
		;
	stack -> num = i + 1;
	return (ft_top(stack));

}

t_stack	*ft_char_to_stack(int len, char **numbers)
{
	int		i;
	t_stack	*elem;
	int *values;
	int num;
	
	values = malloc((len - 2) * sizeof(int));
	num = ft_atoi_err(numbers[1]);
	values[0] = num;
	elem = ft_new_stack(num);
	if (!elem)
		return (NULL);
	i = 1;
	while (++i < len)
	{
		num = ft_atoi_err(numbers[i]);
		values[i - 1] = num;
		elem = ft_add_to_stack(elem, num);
		if (!elem)
		{
			ft_free_stack(elem);
			ft_exit(1);
		}
	}
	ft_quicksort(values, 0, len - 2);
	elem = ft_simplify(ft_top(elem), values);
	free(values);
	return (elem);
}
