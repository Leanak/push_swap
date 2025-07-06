/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:49:58 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/06 15:32:07 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "push_swap.h"

void	do_instruction(t_stack **s_a, t_stack **s_b, char **line);
void	read_instructions(t_stack **s_a, t_stack **s_b);
void	start_checker(t_stack *s_a, t_stack *s_b);

char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);

void	pa_bonus(t_stack **stack_a, t_stack **stack_b);
void	pb_bonus(t_stack **stack_b, t_stack **stack_a);
void	rra_bonus(t_stack **stack_a);
void	rrb_bonus(t_stack **stack_b);
void	rrr_bonus(t_stack **stack_a, t_stack **stack_b);
void	ra_bonus(t_stack **stack_a);
void	rb_bonus(t_stack **stack_b);
void	rr_bonus(t_stack **stack_a, t_stack **stack_b);
void	sa_bonus(t_stack **stack_a);
void	sb_bonus(t_stack **stack_b);
void	ss_bonus(t_stack **stack_a, t_stack **stack_b);


#endif