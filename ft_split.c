/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:53:19 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/02/26 12:53:22 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	words_count(char const *s, char sep)
{
	int	i;
	int	count_words;

	i = 1;
	count_words = 0;
	if (s == NULL)
		return (count_words);
	if (s[0] != sep)
		count_words++;
	while (s[i])
	{
		if ((s[i] != sep) && (s[i - 1] == sep))
			count_words++;
		i++;
	}
	return (count_words);
}

static char	*ft_strndup(const char *str, int n)
{
	int		i;
	char	*copy;

	copy = (char *)malloc(sizeof(char) * (n + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	fill(char **res, char const *s, char c, int nb_words)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[k] && i < nb_words)
	{
		j = 0;
		while (s[k] && (s[k] == c))
			k++;
		while (s[k + j] && (s[k + j] != c))
			j++;
		res[i] = ft_strndup(&s[k], j);
		i++;
		k += j;
	}
	res[nb_words] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nb_words;

	if (!s)
		return (NULL);
	if (*s == '\0')
	{
		res = (char **)malloc(sizeof(char *));
		*res = NULL;
		return (res);
	}
	nb_words = words_count(s, c);
	res = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (res == NULL)
		return (NULL);
	fill(res, s, c, nb_words);
	return (res);
}
