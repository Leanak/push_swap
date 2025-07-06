/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opes_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:36:36 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/06 15:03:42 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra_bonus(t_stack **stack_a)
{
	if ((*stack_a) != NULL && (*stack_a)->next != (*stack_a))
		(*stack_a) = (*stack_a)->next;
}

void	rb_bonus(t_stack **stack_b)
{
	if ((*stack_b) != NULL && (*stack_b)->next != (*stack_b))
		(*stack_b) = (*stack_b)->next;
}

void	rr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	ra_bonus(stack_a);
	rb_bonus(stack_b);
}
