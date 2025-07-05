/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:27:02 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/05 17:13:36 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_top(t_stack **stack)
{
	int	max;
	int	len;
	int	index;
	int	rev;

	max = get_max(*stack);
	index = get_index(*stack, max);
	len = len_stack(*stack);
	rev = len - index;
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	if (index <= len / 2)
		while (index-- > 0)
			rb(stack);
	else
		while(rev-- > 0)
			rrb(stack);
}

int	get_index(t_stack *stack, int value)
{
	int		i;
	t_stack	*current;

	if (!stack)
		return (-1);
	i = 0;
	current = stack;
	while (1)
	{
		if (current->valeur == value)
			return (i);
		current = current->next;
		i++;
		if (current == stack)
			break ;
	}
	return (-1);
}

int	is_sorted(t_stack *stack)
{
	int	i;
	int	len;

	len = len_stack(stack);
	if (len > 0)
	{
		i = 1;
		while (i < len)
		{
			if (stack->valeur > stack->next->valeur)
				return (0);
			stack = stack->next;
			i++;
		}
		return (1);
	}
	return (0);
}

int	get_max(t_stack *stack)
{
	t_stack	*current;
	int		max;

	if (!stack)
		return (0);
	max = stack->valeur;
	current = stack->next;
	while (current != stack)
	{
		if (current->valeur > max)
			max = current->valeur;
		current = current->next;
	}
	return (max);
}

int	get_min(t_stack	*stack)
{
	int		min;
	t_stack	*current;

	min = stack->valeur;
	current = stack->next;
	while (current != stack)
	{
		if (current->valeur < min)
			min = current->valeur;
		current = current->next;
	}
	return (min);
}

int	is_empty(t_stack **stack)
{
	if ((*stack) == NULL)
		return (1);
	else
		return (0);
}

void	rotate_to_min(t_stack **stack_a)
{
	int		min;
	int		index;
	t_stack	*current;

	if (!stack_a || !(*stack_a))
		return ;
	min = get_min(*stack_a);
	index = 0;
	current = *stack_a;
	while (current->valeur != min)
	{
		current = current->next;
		index++;
	}
	if (index <= len_stack(*stack_a) / 2)
	{
		while ((*stack_a)->valeur != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->valeur != min)
			rra(stack_a);
	}
}


void	rotate_to_max(t_stack **stack_b)
{
	int		max;
	int		index;
	t_stack	*current;

	if (!stack_b || !(*stack_b))
		return ;
	max = get_max(*stack_b);
	index = 0;
	current = *stack_b;
	while (current->valeur != max)
	{
		current = current->next;
		index++;
	}
	if (index <= len_stack(*stack_b) / 2)
	{
		while ((*stack_b)->valeur != max)
			rb(stack_b);
	}
	else
	{
		while ((*stack_b)->valeur != max)
			rrb(stack_b);
	}
}


int	cost_to_rotate(t_stack *stack, int index)
{
	int	len = len_stack(stack);
	if  (index < 0 || index >= len)
		return (0);
	if (index <= len / 2)
		return index;
	else
		return len - index;
}
