/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cost_B.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:14:58 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/05 14:15:12 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calcul_cost_both_up(int index_a, int index_b)
{
	int	res;

	res = 0;
	if (index_a > index_b)
		res = index_a;
	else
		res = index_b;
	return (res);
}

static int	calcul_cost_both_down(int index_a, int index_b, int len_a, int len_b)
{
	int	res;

	res = 0;
	if ((len_a - index_a) > (len_b - index_b))
		res = len_a - index_a;
	else
		res = len_b - index_b;
	return (res); 
}

static int	calcul_cost_diff(int cost_a, int cost_b)
{
	int res;

	res = 0;
	res = cost_a + cost_b;
	return (res);
}

void	calcul_total_cost_b(int index_a, t_stack *stack_a, t_stack *stack_b, t_detail **detail)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;
	int	cost_1;
	int cost_2;
	int	cost_3;
	int	index_b;
	
	index_b = (*detail)->index_b;
	len_a = len_stack(stack_a);
	len_b = len_stack(stack_b);
	cost_a = cost_to_rotate(stack_a, index_a);
	cost_b = cost_to_rotate(stack_b, index_b);
	cost_1 = calcul_cost_both_up(index_a, index_b);
	cost_2 = calcul_cost_both_down(index_a, index_b, len_a, len_b);
	cost_3 = calcul_cost_diff(cost_a, cost_b);
	
	if (cost_1 <= cost_2 && cost_1 <= cost_3)
	{
		(*detail)->num = 1;
		(*detail)->total_cost = cost_1;
	}
	else if (cost_2 <= cost_1 && cost_2 <= cost_3)
	{	
		(*detail)->num = 2;
		(*detail)->total_cost = cost_2;
	}
	else	
	{
		(*detail)->num = 3;
		(*detail)->total_cost = cost_3;
	}
}