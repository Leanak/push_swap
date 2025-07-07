/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opes_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:19:20 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/06 18:15:47 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	int	tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = (*stack_a)->valeur;
	(*stack_a)->valeur = (*stack_a)->next->valeur;
	(*stack_a)->next->valeur = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	int	tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = (*stack_b)->valeur;
	(*stack_b)->valeur = (*stack_b)->next->valeur;
	(*stack_b)->next->valeur = tmp;
	write(1, "sb\n", 3);
}

static void	sa_silent(t_stack **stack_a)
{
	int	tmp;

	tmp = (*stack_a)->valeur;
	(*stack_a)->valeur = (*stack_a)->next->valeur;
	(*stack_a)->next->valeur = tmp;
}

static void	sb_silent(t_stack **stack_b)
{
	int	tmp;

	tmp = (*stack_b)->valeur;
	(*stack_b)->valeur = (*stack_b)->next->valeur;
	(*stack_b)->next->valeur = tmp;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa_silent(stack_a);
	sb_silent(stack_b);
	write(1, "ss\n", 3);
}
