/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:29:48 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/14 16:03:22 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_atoi_err(t_stack *stack, int *values, const char *str)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' ||
			str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if ((str[i] != '\0') || (num > 2147483647 && np == 1) || (num > 2147483648 && np == -1))
	{
		ft_free_stack(stack);
		free(values);
		ft_exit(1);
	}
	return ((int)(np * num));
}

static int	ft_max(t_stack *stack)
{
	int	max;

	stack = ft_top(stack);
	max = stack -> num;
	while (stack -> next)
	{
		stack = stack -> next;
		if (stack -> num > max)
			max = stack -> num;
	}
	return (max);
}

int	ft_max_bits(t_stack *stack)
{
	int	max;
	int	max_bits;

	max_bits = 0;
	max = ft_max(stack);
	while ((max >> max_bits) != 0)
		++max_bits;
	return (max_bits);
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	stack = ft_top(stack);
	while (stack -> next)
	{
		stack = stack -> next;
		++size;
	}
	return (++size);
}
