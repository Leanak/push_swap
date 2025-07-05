/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opes_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:25:03 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/03 20:24:06 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_push(t_stack **stack_a, t_stack *tmp)
{
	if (!(*stack_a))
	{
		tmp ->next = tmp;
		tmp->prev = tmp;
		(*stack_a) = tmp;
	}
	else
	{
		tmp->prev = (*stack_a)->prev;
		tmp->next = (*stack_a);
		(*stack_a)->prev->next = tmp;
		(*stack_a)->prev = tmp;
		(*stack_a) = tmp;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = (*stack_b);
	if ((*stack_b)->next == (*stack_b))
		(*stack_b) = NULL;
	else
	{
		(*stack_b)->prev->next = (*stack_b)->next;
		(*stack_b)->next->prev = (*stack_b)->prev;
		(*stack_b) = (*stack_b)->next;
	}
	add_push(stack_a, tmp);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a || !(*stack_a))
		return ;
	tmp = (*stack_a);
	if ((*stack_a)->next == (*stack_a))
		(*stack_a) = NULL;
	else
	{
		(*stack_a)->prev->next = (*stack_a)->next;
		(*stack_a)->next->prev = (*stack_a)->prev;
		(*stack_a) = (*stack_a)->next;
	}
	add_push(stack_b, tmp);
	write(1, "pb\n", 3);
}
