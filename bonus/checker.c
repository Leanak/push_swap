/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:49:26 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/06 17:57:48 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_instruction(t_stack **s_a, t_stack **s_b, char **line)
{
	if (ft_strcmp(*line, "pa") == 0)
		pa_bonus(s_a, s_b);
	else if (ft_strcmp(*line, "pb") == 0)
		pb_bonus(s_b, s_a);
	else if (ft_strcmp(*line, "sa") == 0)
		sa_bonus(s_a);
	else if (ft_strcmp(*line, "sb") == 0)
		sb_bonus(s_b);
	else if (ft_strcmp(*line, "ss") == 0)
		ss_bonus(s_a, s_b);
	else if (ft_strcmp(*line, "rra") == 0)
		rra_bonus(s_a);
	else if (ft_strcmp(*line, "rrb") == 0)
		rrb_bonus(s_b);
	else if (ft_strcmp(*line, "rrr") == 0)
		rrr_bonus(s_a, s_b);
	else if (ft_strcmp(*line, "ra") == 0)
		ra_bonus(s_a);
	else if (ft_strcmp(*line, "rb") == 0)
		rb_bonus(s_b);
	else if (ft_strcmp(*line, "rr") == 0)
		rr_bonus(s_a, s_b);
	else
	{
		if (*line)
			free(*line);
		free_stack(s_a);
		free_stack(s_b);
		write(2, "Error\n", 6);
		exit (1);
	}
}

void	read_instructions(t_stack **s_a, t_stack **s_b)
{
	int	res;
	char	*line;
	char	buffer[2];

	res = 1;
	line = NULL;
	while (res > 0)
	{
		res = read(0, buffer, 1);
		buffer[res] = '\0';
		if (res == 0)
			return ;
		else if (buffer[0] != '\n')
			line = ft_strjoin(line, buffer);
		else
		{
			do_instruction(s_a, s_b, &line);
			free(line);
			line = NULL;
		}
	}
}

void	start_checker(t_stack *s_a, t_stack *s_b)
{
	read_instructions(&s_a, &s_b);
	if (is_sorted(s_a) == 1)
	{
		write(1, "OK\n", 3);
		free_stack(&s_a);
		exit (1);
	}
	else
	{
		write(1, "KO\n", 3);
		free_stack(&s_a);
		free_stack(&s_b);
		exit (1) ;
	}
	
}

int	main(int ac, char **av)
{
	int		error;
	char	**split;
	int		init;
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	error = 1;
	init = 0;
	stack_a = NULL;
	stack_b = NULL;
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
		start_checker(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}