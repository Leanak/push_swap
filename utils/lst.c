/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:18:33 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/04 13:23:01 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_newelem(int valeur, t_stack *element)
{
	if (!element)
		return (-2);
	element->next = NULL;
	element->prev = NULL;
	element->valeur = valeur;
	return (1);
}

int	add_to_list(t_stack **stack, int valeur)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (-2);
	if (lst_newelem(valeur, element) == -1)
	{
		free(element);
		return (-2);
	}
	if ((*stack) == NULL)
	{
		(*stack) = element;
		(*stack)->next = (*stack);
		(*stack)->prev = (*stack);
	}
	else
	{
		element->prev = (*stack)->prev;
		element->next = (*stack);
		(*stack)->prev->next = element;
		(*stack)->prev = element;
		(*stack) = element;
	}
	return (1);
}

int	len_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	if (!stack)
		return (0);
	i = 1;
	tmp = stack->next;
	while (tmp != stack)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
