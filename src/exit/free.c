#include "../header/push_swap.h"

void	ft_free_stack(t_stack *elem)
{
	t_stack	*next;

	next = NULL;
	elem = ft_get_head(elem);
	while (elem -> next)
	{
		next = elem -> next;
		free(elem);
		elem = next;
	}
	if (next)
		free(next);
}

void	ft_free(t_stack *a, t_stack *b)
{
	if (a)
		ft_free_stack(a);
	if (b)
		ft_free_stack(b);
}
