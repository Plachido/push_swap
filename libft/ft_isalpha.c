/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:08:23 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/05 16:52:01 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (!((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')))
		return (0);
	return (1);
}
