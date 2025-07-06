/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:29:12 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/03 20:20:43 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_a)
{
	t_stack	*current;

	if (!stack_a)
	{
		printf("empty stack\n");
		return ;
	}
	current = stack_a;
	while (current->next != stack_a)
	{
		printf("%d\n", current->valeur);
		current = current->next;
	}
	printf("%d\n", current->valeur);
}

void	print_tab(int *tab, int len)
{
	int	i;

	i = 0;
	printf("MON TAB\n");
	while (i < len)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

void	print_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
	{
		printf("PROB AVEC SPLIT\n");
		return ;
	}
	printf("MON SPLIT\n");
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}
