/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:31:42 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/06 15:25:51 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**free_all(char **split, int i, char **tmp, int j)
{
	free_split(split, i);
	free_split(tmp, j);
	return (NULL);
}

void	free_stack(t_stack	**stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!(*stack) || !stack)
		return ;
	current = (*stack);
	(*stack)->prev->next = NULL;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	(*stack) = NULL;
}

char	**free_split(char **split, int i)
{
	if (!split)
		return (NULL);
	while (i >= 0)
	{
		if (split[i])
			free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

int	is_sorted(t_stack *stack)
{
	int	i;
	int	len;

	len = len_stack(stack);
	if (len > 0)
	{
		i = 1;
		while (i < len)
		{
			if (stack->valeur > stack->next->valeur)
				return (0);
			stack = stack->next;
			i++;
		}
		return (1);
	}
	return (0);
}
