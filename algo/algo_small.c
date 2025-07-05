/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:29:12 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/03 20:42:37 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_algo(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->valeur;
	second = (*stack)->next->valeur;
	third = (*stack)->next->next->valeur;
	if ((first > second) && (second > third))
	{
		sa(stack);
		rra(stack);
	}
	else if ((first < second && first < third) && (second > third))
	{
		sa(stack);
		ra(stack);
	}
	else if ((first < second && first < third) && (second > third))
		rra(stack);
	else if ((first > second && first > third) && (second < third))
		ra(stack);
	else if (first > second && second < third)
		sa(stack);
}
