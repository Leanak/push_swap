/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:22:05 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/06 17:26:21 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = len_stack((*stack_a));
	if (is_sorted(*stack_a))
		return ;
	if (len_a == 2)
	{
		sa(stack_a);
		return ;
	}
	if (len_a == 3)
	{
		quick_sort_algo(stack_a);
		return ;
	}
	push_b(stack_a, stack_b);
}

void	set_zero(t_detail **finale)
{
	(*finale)->index_a = 0;
	(*finale)->index_b = 0;
	(*finale)->val = 0;
	(*finale)->total_cost = 0;
	(*finale)->num = 0;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_detail	*finale;

	finale = malloc (sizeof(t_detail));
	if (!finale)
		return ;
	push_2_b(stack_b, stack_a);
	while (len_stack(*stack_a) > 3)
	{
		set_zero(&finale);
		find_best_move_b(*stack_a, *stack_b, &finale);
		do_opes(&finale, stack_a, stack_b);
		pb(stack_b, stack_a);
	}
	quick_sort_algo(stack_a);
	rotate_to_max(stack_b);
	while (!is_empty(stack_b))
	{
		set_zero(&finale);
		find_best_move_a(*stack_a, *stack_b, &finale);
		do_opes(&finale, stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	rotate_to_min(stack_a);
	free(finale);
}

void	push_2_b(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
}
