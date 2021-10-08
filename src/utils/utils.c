/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:29:48 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/08 11:49:32 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_atoi_err(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 57 || str[i] < 48)
			ft_exit(1);
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * neg);
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

	size = 0;
	stack = ft_top(stack);
	while (stack -> next)
	{
		stack = stack -> next;
		++size;
	}
	return (++size);
}
