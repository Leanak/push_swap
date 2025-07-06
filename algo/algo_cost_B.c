/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cost_B.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:14:58 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/06 12:38:24 by lenakach         ###   ########.fr       */
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

static int	calcul_cost_both_down(int i_a, int i_b, t_stack *s_a, t_stack *s_b)
{
	int	res;
	int	len_a;
	int	len_b;

	len_a = len_stack(s_a);
	len_b = len_stack(s_b);
	res = 0;
	if ((len_a - i_a) > (len_b - i_b))
		res = len_a - i_a;
	else
		res = len_b - i_b;
	return (res);
}

static int	calcul_cost_diff(t_stack *s_a, t_stack *s_b, int i_a, int i_b)
{
	int	res;
	int	cost_a;
	int	cost_b;

	cost_a = cost_to_rotate(s_a, i_a);
	cost_b = cost_to_rotate(s_b, i_b);
	res = 0;
	res = cost_a + cost_b;
	return (res);
}

void	calcul_total_cost_b(int i_a, t_stack *s_a, t_stack *s_b, t_detail **det)
{
	int	cost_1;
	int	cost_2;
	int	cost_3;
	int	index_b;

	index_b = (*det)->index_b;
	cost_1 = calcul_cost_both_up(i_a, index_b);
	cost_2 = calcul_cost_both_down(i_a, index_b, s_a, s_b);
	cost_3 = calcul_cost_diff(s_a, s_b, i_a, index_b);
	if (cost_1 <= cost_2 && cost_1 <= cost_3)
	{
		(*det)->num = 1;
		(*det)->total_cost = cost_1;
	}
	else if (cost_2 <= cost_1 && cost_2 <= cost_3)
	{	
		(*det)->num = 2;
		(*det)->total_cost = cost_2;
	}
	else
	{
		(*det)->num = 3;
		(*det)->total_cost = cost_3;
	}
}
