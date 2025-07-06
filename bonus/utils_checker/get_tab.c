/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:00:18 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/06 15:22:57 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	init_var(int *i, int *sign, long long *res)
{
	*i = 0;
	*res = 0;
	*sign = 1;
}

static int	ft_atoi_pars(char *str, int *error)
{
	int			i;
	int			sign;
	long long	res;

	init_var(&i, &sign, &res);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if ((res * sign) < INT_MIN || (res * sign) > INT_MAX)
			return (*error = -1, 0);
		i++;
	}
	if (str[i] != '\0')
		return (*error = -1, 0);
	return (res * sign);
}

static int	check_doublon(int *tab, int len)
{
	int	i;
	int	tmp;
	int	check;

	i = 0;
	tmp = tab[0];
	check = 0;
	while (++i < len)
	{
		if (tab[i] == tmp)
			return (1);
		tmp = tab[i];
	}
	return (0);
}

void	get_tab(char **split, int *error)
{
	int	len;
	int	*tab;
	int	i;

	len = 0;
	i = -1;
	if (!split)
		return ;
	while (split[len])
		len++;
	tab = malloc(len * sizeof(int));
	if (!tab || len == 0)
		return (free(tab), *error = -1, (void)0);
	while (++i < len)
	{
		tab[i] = ft_atoi_pars(split[i], error);
		if (*error == -1)
			return (free(split));
		free(split[i]);
	}
	quick_sort(tab, 0, len - 1);
	if (check_doublon(tab, len) == 1)
		return (free(tab), free(split), *error = -1, (void)0);
	return (free(tab), free(split));
}
