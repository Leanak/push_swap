/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:51:50 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/07 15:11:07 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack **stack_a, char **split)
{
	int	i;
	int	j;
	int	len;
	int	error;

	i = 0;
	len = 0;
	if (!split)
		return (-1);
	while (split[len])
		len++;
	i = len;
	while (--i >= 0)
	{
		j = ft_atoi(split[i]);
		error = add_to_list(stack_a, j);
		if (error == -2)
			return (free_split2(split), 0);
	}
	free_split2(split);
	return (1);
}
