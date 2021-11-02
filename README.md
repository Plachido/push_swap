# push_swap
The goal of this project is to sort data on a stack using two stacks, with a limited set of instructions, using the lowest possible number of actions. All of the code is written in accordance to the Norm v3.

## THE ACTIONS
The operations allowed on the the two stacks (named respectively A and B) are the folowing:
* **sa** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* **sb** : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* **ss** : sa and sb at the same time.
* **pa** : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* **pb** : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* **ra** : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* **rb** : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* **rr** : ra and rb at the same time.
* **rra** : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* **rrb** : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* **rrr** : rra and rrb at the same time.

## THE ALGORITHM
The main algorithm, inspired by [@LeoFu9487's Push_Swap Tutorial](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e) is an implementation of radix sort. Basically, the numbers are seen as binary digits in order to use the algorithm with only two bins (the two stacks). This solution, although not the moste efficient, is quite efficient expetially when used for sorting many numbers.
In fact, it is extremely inefficient when few numbers have to get ordered. Because of this, the approach is different when the numbers to sort are less than 25 (after some tests, this seemed a reasonable number): a smart rotation is made in order to push to stack B the highest number until only two numbers are left in stack A. These get sorted and everything gets pushed back to A. 

## KNOWN ISSUES
* Under some circumstances, numbers above max int might not return error.
* Shell variables do not work because the program recognizes strings as one single number and therefor does nothing.
