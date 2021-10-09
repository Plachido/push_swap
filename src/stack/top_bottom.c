/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_bottom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:31:12 by plpelleg          #+#    #+#             */
/*   Updated: 2021/10/08 11:45:19 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack	*ft_top(t_stack *elem)
{
	if (!elem)
		return (NULL);
	while (elem -> prev)
		elem = elem -> prev;
	return (elem);
}

t_stack	*ft_bottom(t_stack *elem)
{
	if (!elem)
		return (NULL);
	while (elem -> next)
		elem = elem -> next;
	return (elem);
}
