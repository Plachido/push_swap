#include "../src/header/push_swap.h"
#include "stdio.h"

void	ft_print(t_stack *stack)
{
	while (stack -> next)
	{
		printf("%d\n", stack -> num);
		stack = stack ->next;
	}
	printf("%d\n", stack -> num);
}
