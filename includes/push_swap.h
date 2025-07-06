/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:19:07 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/05 17:09:04 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Librairies
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

//Structures
typedef struct s_stack
{
	int				valeur;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_detail
{
	int	index_a;
	int	index_b;
	int	val;
	int	total_cost;
	int	num;
}		t_detail;

//Fonctions libft
char	**ft_split(char *str, char c);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_swap(int *a, int *b);

//Fonctions algo
void	start_algo(t_stack **stack_a, t_stack **stack_b);
void	set_zero(t_detail **finale);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	push_2_b(t_stack **stack_a, t_stack **stack_b);
void	quick_sort_algo(t_stack **stack);
int		is_sorted(t_stack *stack);
int		get_max(t_stack *stack);
int		get_min(t_stack	*stack);
int		is_empty(t_stack **stack);
void	do_opes(t_detail **finale, t_stack **stack_a, t_stack **stack_b);
void	find_best_move_a(t_stack *stack_a, t_stack *stack_b, t_detail **detail);
void	find_best_move_b(t_stack *stack_a, t_stack *stack_b, t_detail **detail);
void	find_insert_b(t_stack *stack, t_detail **detail);
void	find_insert_a(t_stack *stack, t_detail **detail);
void	calcul_total_cost_b(int index_a, t_stack *stack_a, t_stack *stack_b, \
		t_detail **detail);
void	calcul_total_cost_a(int index_b, t_stack *stack_b, t_stack *stack_a, \
		t_detail **detail);
int		cost_to_rotate(t_stack *stack, int index);
void	rotate_to_min(t_stack **stack_a);
void	rotate_to_max(t_stack **stack_b);
int		get_index(t_stack *stack, int value);
void	check_top(t_stack **stack);

//Fonctions listes
int		lst_newelem(int valeur, t_stack *element);
int		add_to_list(t_stack **stack, int valeur);
int		len_stack(t_stack *stack);

//Fonctions opes
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ra_silent(t_stack **stack_a);
void	rra_silent(t_stack **stack_a);
void	rb_silent(t_stack **stack_b);
void	rrb_silent(t_stack **stack_b);

//Fonctions pushSwap
char	**arguments(int argc, char **argv, int *error);
int		is_args_empty(int ac, char **av);
void	get_tab(char **split, int *error);
void	quick_sort(int *tab, int min, int max);
int		init_stack(t_stack **stack_a, char **split);
char	**free_split(char **split, int i);
void	free_stack(t_stack	**stack);
char	**free_split(char **split, int i);
char	**free_all(char **split, int i, char **tmp, int j);

//Fonction tmp
void	print_split(char **split);
void	print_tab(int *tab, int len);
void	print_stack(t_stack *stack_a);

#endif