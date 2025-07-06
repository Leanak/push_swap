/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opes_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:19:20 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/06 17:59:11 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_bonus(t_stack **stack_a)
{
	int	tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = (*stack_a)->valeur;
	(*stack_a)->valeur = (*stack_a)->next->valeur;
	(*stack_a)->next->valeur = tmp;
}

void	sb_bonus(t_stack **stack_b)
{
	int	tmp;
	
	if (!stack_b || !*stack_b)
		return ;
	tmp = (*stack_b)->valeur;
	(*stack_b)->valeur = (*stack_b)->next->valeur;
	(*stack_b)->next->valeur = tmp;
}

void	ss_bonus(t_stack **stack_a, t_stack **stack_b)
{
	sa_bonus(stack_a);
	sb_bonus(stack_b);
}
