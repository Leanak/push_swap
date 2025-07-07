/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:03:09 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/07 15:10:23 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_args_empty(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	count_split(char **tmp)
{
	int	i;

	i = 0;
	if (!tmp)
		return (-1);
	while (tmp[i])
		i++;
	return (i);
}

static char	**sortie(char **tmp, char **split)
{
	if (*tmp)
		free_split2(tmp);
	free_split2(split);
	return (NULL);
}

char	**arguments(int ac, char **av, int *error)
{
	char	**split;
	char	**tmp;
	int		i;

	if (ac == 2)
		return (ft_split(av[1], ' '));
	split = malloc(ac * sizeof(char *));
	if (!split)
		return (NULL);
	i = -1;
	while (++i < ac - 1)
	{
		tmp = ft_split(av[i + 1], ' ');
		if (!tmp || count_split(tmp) != 1)
		{
			*error = -1;
			return (sortie(tmp, split));
		}
		split[i] = ft_strdup(av[i + 1]);
		if (!split[i])
			return (free_all(split, tmp));
		free_split2(tmp);
	}
	split[ac - 1] = NULL;
	return (split);
}
