/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cost_to_B.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:01:32 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/05 18:33:29 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_details(t_detail **finale, t_detail **tmp, int *min_cost)
{
	(*finale)->val = (*tmp)->val;
	(*finale)->index_a = (*tmp)->index_a;
	(*finale)->index_b = (*tmp)->index_b;
	(*finale)->total_cost = (*tmp)->total_cost;
	(*finale)->num = (*tmp)->num;
	*min_cost = (*tmp)->total_cost;
}

static void	init_var(int *i, int *len, int *min_cost, t_stack *stack)
{
	*i = 0;
	*len = len_stack(stack);
	*min_cost = -1;
}

void	find_best_move_b(t_stack *stack_a, t_stack *stack_b, t_detail **finale)
{
	int			i;
	int			len;
	int			min_cost;
	t_stack		*current;
	t_detail	*tmp;

	init_var(&i, &len, &min_cost, stack_a);
	current = stack_a;
	tmp = malloc(sizeof(t_detail));
	if (!tmp)
		return ;
	while (i < len)
	{
		set_zero(&tmp);
		tmp->val = current->valeur;
		tmp->index_a = i;
		find_insert_b(stack_b, &tmp);
		calcul_total_cost_b(i, stack_a, stack_b, &tmp);
		if (min_cost == -1 || tmp->total_cost < min_cost)
			set_details(finale, &tmp, &min_cost);
		current = current->next;
		i++;
	}
	free(tmp);
}

static void	init_var2(int *len, int *min, int *max, t_stack *stack)
{
	*len = len_stack(stack);
	*min = get_min(stack);
	*max = get_max(stack);
}

void	find_insert_b(t_stack *stack, t_detail **detail)
{
	int		i;
	int		len;
	int		min;
	int		max;
	t_stack	*current;

	if (!stack || stack->next == stack)
		return ;
	i = 0;
	current = stack;
	init_var2(&len, &min, &max, stack);
	(*detail)->index_b = 0;
	while (i < len)
	{
		if (((*detail)->val < min || (*detail)->val > max)
			&& (current->valeur == max))
			return ((*detail)->index_b = i, (void)0);
		if (((*detail)->val <= current->valeur)
			&& ((*detail)->val >= current->next->valeur))
			return ((*detail)->index_b = i + 1, (void)0);
		current = current->next;
		i++;
	}
}
