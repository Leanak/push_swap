/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:18:49 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/09 15:36:57 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			init;
	int			error;
	char		**split;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	error = 1;
	if (ac == 1 || av[1][0] == '\0')
		return (1);
	split = arguments(ac, av, &error);
	get_tab(split, &error);
	if (error == -1 || is_args_empty(ac, av) == 1 || !split)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init = init_stack(&stack_a, arguments(ac, av, &error));
	if (init == 1)
		start_algo(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
