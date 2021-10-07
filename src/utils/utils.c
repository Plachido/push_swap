/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:29:48 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/07 19:15:20 by plpelleg         ###   ########.fr       */
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
			ft_exit(2);
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * neg);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	ft_putendl(char *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}
