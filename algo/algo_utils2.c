/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:00:38 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/05 18:03:56 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
