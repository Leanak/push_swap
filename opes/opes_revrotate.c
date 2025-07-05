/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opes_revrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:39:46 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/03 20:24:49 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	if ((*stack_a) != NULL && (*stack_a)->prev != (*stack_a))
		(*stack_a) = (*stack_a)->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	if ((*stack_b) != NULL && (*stack_b)->prev != (*stack_b))
		(*stack_b) = (*stack_b)->prev;
	write(1, "rrb\n", 4);
}

void	rra_silent(t_stack **stack_a)
{
	if ((*stack_a) != NULL && (*stack_a)->prev != (*stack_a))
		(*stack_a) = (*stack_a)->prev;
}

void	rrb_silent(t_stack **stack_b)
{
	if ((*stack_b) != NULL && (*stack_b)->prev != (*stack_b))
		(*stack_b) = (*stack_b)->prev;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_silent(stack_a);
	rrb_silent(stack_b);
	write(1, "rrr\n", 4);
}
