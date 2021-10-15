/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:22:20 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/15 12:17:57 by plpelleg         ###   ########.fr       */
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

static t_stack	*ft_simplify(t_stack *stack, int values[])
{
	int	i;

	while (stack->next)
	{
		i = -1;
		while (values[++i] != stack -> num)
			;
		stack -> num = i;
		stack = stack -> next;
	}
	i = -1;
	while (values[++i] != stack -> num)
		;
	stack -> num = i;
	return (ft_top(stack));
}

t_stack	*ft_char_to_stack(int len, char **numbers)
{
	t_stack	*elem;
	int		i;
	int		*values;

	elem = NULL;
	values = malloc((len - 1) * sizeof(int));
	if (!values)
		ft_exit(0);
	ft_atoi_ps(elem, values, 0, numbers[1]);
	elem = ft_new_stack(values[0]);
	if (!elem)
		ft_malloc_error(values, elem);
	i = 1;
	while (++i < len)
	{
		ft_atoi_ps(elem, values, i - 1, numbers[i]);
		elem = ft_add_to_stack(elem, values[i - 1]);
		if (!elem)
			ft_malloc_error(values, elem);
	}
	ft_quicksort(values, 0, len - 2);
	elem = ft_simplify(ft_top(elem), values);
	free(values);
	return (elem);
}
