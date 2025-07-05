/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cost_to_B.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:01:32 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/05 14:34:48 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_best_move_b(t_stack *stack_a, t_stack *stack_b, t_detail **detail)
{
	int			i;
	int			len;
	int			min_cost;
	t_stack		*current;
	t_detail	*tmp;

	i = 0;
	len = len_stack(stack_a);
	current = stack_a;
	min_cost = -1;

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
		{
			min_cost = tmp->total_cost;
			(*detail)->val = tmp->val;
			(*detail)->index_a = tmp->index_a;
			(*detail)->index_b = tmp->index_b;
			(*detail)->total_cost = tmp->total_cost;
			(*detail)->num = tmp->num;
		}
		current = current->next;
		i++;
	}
	free(tmp);
}

void	find_insert_b(t_stack *stack, t_detail **detail)
{
	int		i;
	int		len;
	int		min;
	int		max;
	int		curr;
	int		next;
	t_stack	*current;

	if (!stack || stack->next == stack)
		return ;
	current = stack;
	i = 0;
	len = len_stack(stack);
	min = get_min(stack);
	max = get_max(stack);
	(*detail)->index_b = 0;
	
	while (i < len)
	{
		curr = current->valeur;
		next = current->next->valeur;
		if (((*detail)->val < min || (*detail)->val > max) && (curr == max))
		{
			(*detail)->index_b = i;
			break;
		}
		if ((*detail)->val <= curr && (*detail)->val >= next)
		{	
			(*detail)->index_b = (i + 1);
			break;
		}
		current = current->next;
		i++;
	}
}

