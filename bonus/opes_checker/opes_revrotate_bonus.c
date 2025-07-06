/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opes_revrotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:39:46 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/06 15:03:38 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra_bonus(t_stack **stack_a)
{
	if ((*stack_a) != NULL && (*stack_a)->prev != (*stack_a))
		(*stack_a) = (*stack_a)->prev;
}

void	rrb_bonus(t_stack **stack_b)
{
	if ((*stack_b) != NULL && (*stack_b)->prev != (*stack_b))
		(*stack_b) = (*stack_b)->prev;
}

void	rrr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	rra_bonus(stack_a);
	rrb_bonus(stack_b);
}
