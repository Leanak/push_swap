/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opes_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:36:36 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/03 20:25:05 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	if ((*stack_a) != NULL && (*stack_a)->next != (*stack_a))
		(*stack_a) = (*stack_a)->next;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	if ((*stack_b) != NULL && (*stack_b)->next != (*stack_b))
		(*stack_b) = (*stack_b)->next;
	write(1, "rb\n", 3);
}

void	ra_silent(t_stack **stack_a)
{
	if ((*stack_a) != NULL && (*stack_a)->next != (*stack_a))
		(*stack_a) = (*stack_a)->next;
}

void	rb_silent(t_stack **stack_b)
{
	if ((*stack_b) != NULL && (*stack_b)->next != (*stack_b))
		(*stack_b) = (*stack_b)->next;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra_silent(stack_a);
	rb_silent(stack_b);
	write(1, "rr\n", 3);
}
