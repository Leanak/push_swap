/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:56:55 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/03 20:13:57 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(int *tab, int min, int max)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[max];
	j = min;
	i = min - 1;
	while (j < max)
	{
		if (tab[j] <= pivot)
		{
			i++;
			ft_swap(&tab[i], &tab[j]);
		}
		j++;
	}
	ft_swap(&tab[i + 1], &tab[max]);
	return (i + 1);
}

void	quick_sort(int *tab, int min, int max)
{
	int	pivot;

	if (min < max)
	{
		pivot = partition(tab, min, max);
		quick_sort(tab, min, pivot - 1);
		quick_sort(tab, pivot + 1, max);
	}
}
