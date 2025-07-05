/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:29:38 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/03 20:26:22 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_free(char **res, int j)
{
	while (j >= 0)
	{
		free(res[j]);
		j--;
	}
	free(res);
	return (NULL);
}

static char	*fill_word(char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc ((end - start + 1) * sizeof(char));
	if (!word || !str)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static void	int_init(int *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

char	**ft_split(char *str, char c)
{
	char	**res;
	int		i;
	int		j;
	int		s_word;

	int_init(&i, &j, &s_word);
	res = malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!res || !str)
		return (NULL);
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && s_word < 0)
			s_word = i;
		else if ((str[i] == c || i == ft_strlen(str)) && s_word >= 0)
		{
			res[j] = fill_word(str, s_word, i);
			if (!res[j])
				return (ft_free(res, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
