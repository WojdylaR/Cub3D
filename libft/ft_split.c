/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sp.c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_word(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != 0)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static	int		word_size(int index, char const *s, char c)
{
	int i;

	i = 0;
	while (s[index + i] != c && s[index + i])
		i++;
	return (i);
}

static	int		fill_word(char *str, int index, char const *s, char c)
{
	int	i;

	i = 0;
	while (s[index] != c && s[index])
	{
		str[i] = s[index];
		index++;
		i++;
	}
	str[i] = 0;
	return (index);
}

static	char	**free_tab(char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		index;
	int		wrd_nbr;

	i = 0;
	index = 0;
	if ((!s))
		return (0);
	wrd_nbr = count_word(s, c);
	if (!(strs = malloc(sizeof(char *) * (wrd_nbr + 1))))
		return (0);
	while (i < wrd_nbr)
	{
		while (s[index] == c && s[index])
			index++;
		if (!(strs[i] = malloc(sizeof(char) * (word_size(index, s, c) + 1))))
			return (free_tab(strs, i));
		index = fill_word(strs[i], index, s, c);
		if (index == 0)
			return (0);
		i++;
	}
	strs[i] = 0;
	return (strs);
}
