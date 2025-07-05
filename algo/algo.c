/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 22:57:44 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/04 18:01:35 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	both_up(int i, int j, t_stack **sa, t_stack **sb)
{
	while (i > 0 && j > 0)
	{
		rr(sa, sb);
		i--;
		j--;
	}
	while (i-- > 0)
		ra(sa);
	while (j-- > 0)
		rb(sb);
}

static void	both_down(int i, int j, t_stack **sa, t_stack **sb)
{
	int	len_a;
	int	len_b;
	int	new_a;
	int	new_b;
	
	len_a = len_stack(*sa);
	len_b = len_stack(*sb);
	new_a = len_a - i;
	new_b = len_b - j;
	
	while (new_a > 0 && new_b > 0)
	{
		rrr(sa, sb);
		new_a--;
		new_b--;
	}
	while (new_a-- > 0)
		rra(sa);
	while (new_b-- > 0)
		rrb(sb);
}

static void	both_diff_a(int index, t_stack **stack)
{
	int	len;
	int	rev;

	len = len_stack(*stack);
	rev = len - index;
	if (index <= len / 2)
		while (index-- > 0)
			ra(stack);
	else
		while (rev-- > 0)
			rra(stack);
}

static void	both_diff_b(int index, t_stack **stack)
{
	int	len;
	int	rev;

	len = len_stack(*stack);
	rev = len - index;
	if (index <= len / 2)
		while (index-- > 0)
			rb(stack);
	else
		while (rev-- > 0)
			rrb(stack);
}

void	do_opes(t_detail **finale, t_stack **stack_a, t_stack **stack_b)
{
	int	index_a;
	int	index_b;
	
	index_a = (*finale)->index_a;
	index_b = (*finale)->index_b;

	if ((*finale)->num == 1)
		both_up(index_a, index_b, stack_a, stack_b);
	else if ((*finale)->num == 2)
		both_down(index_a, index_b, stack_a, stack_b);
	else if ((*finale)->num == 3)
	{
		both_diff_a(index_a, stack_a);
		both_diff_b(index_b, stack_b);
	}
}

/* void	do_opes(t_detail **finale, t_stack **stack_a, t_stack **stack_b)
{
	int	len_b;
	int	rot_a;
	int	rot_b;
	int	rev_a;
	int	rev_b;

	len_b = len_stack((*stack_b));
	rot_a = (*finale)->index_a;
	rot_b = (*finale)->index_b;
	rev_a = len_stack(*stack_a) - rot_a;
	rev_b = len_b - rot_b;
	if ((rot_a <= len_stack(*stack_a) / 2) && (rot_b <= len_b / 2))
		cas_inferieur(rot_a, rot_b, stack_a, stack_b);
	else if ((rot_a > len_stack(*stack_a) / 2) && (rot_b > len_b / 2))
		cas_superieur(rev_a, rev_b, stack_a, stack_b);
	else
	{
		cas_hybride(rot_a, rev_a, stack_a);
		cas_hybride(rot_b, rev_b, stack_b);
	}
} */

/* void	do_opes(t_detail **finale, t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	int	len_b;
	int	rot_a;
	int	rot_b;
	int	rev_a;
	int	rev_b;
	
	len_a = len_stack((*stack_a));
	len_b = len_stack((*stack_b));
	rot_a = (*finale)->index_a;
	rot_b = (*finale)->index_b;
	rev_a = len_a - rot_a;
	rev_b = len_b - rot_b;

	if ((rot_a <= len_a / 2) && (rot_b <= len_b / 2))
	{
		while (rot_a > 0 && rot_b > 0)
		{
			rr(stack_a, stack_b);
			rot_a--;
			rot_b--;
		}
		while (rot_a-- > 0)
			ra(stack_a);
		while (rot_b-- > 0)
			rb(stack_b);
	}
	else if((rot_a > len_a / 2) && (rot_b > len_b / 2))
	{
		while (rev_a > 0 && rev_b > 0)
		{
			rrr(stack_a, stack_b);
			rev_a--;
			rev_b--;
		}
		while (rev_a-- > 0)
			rra(stack_a);
		while(rev_b--> 0)
			rrb(stack_b);
	}
	else
	{
		if (rot_a <= len_a / 2)
			while (rot_a-- > 0)
				ra(stack_a);
		else
			while(rev_a--> 0)
				rra(stack_a);
		if (rot_b <= len_b / 2)
			while(rot_b-- > 0)
				rb(stack_b);
		else
			while(rev_b-- > 0)
				rrb(stack_b);
	}
}
 */