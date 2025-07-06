/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:27:02 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/05 18:02:31 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	cost_to_rotate(t_stack *stack, int index)
{
	int	len;

	len = len_stack(stack);
	if (index < 0 || index >= len)
		return (0);
	if (index <= len / 2)
		return (index);
	else
		return (len - index);
}
