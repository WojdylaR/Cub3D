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

static	int		malf(char const *s1, char const *set)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (set[n])
	{
		if (set[n] == s1[i])
		{
			i++;
			n = -1;
		}
		n++;
	}
	return (i);
}

static	int		mall(char const *s1, char const *set)
{
	int i;
	int n;
	int k;

	k = 0;
	i = 0;
	n = 0;
	while (s1[i])
		i++;
	i--;
	while (set[n])
	{
		if (set[n] == s1[i])
		{
			k++;
			i--;
			n = -1;
		}
		n++;
	}
	return (k);
}

static	int		len(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (s1[i])
		i++;
	i = i - mall(s1, set) - malf(s1, set);
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	char	*dst;
	int		n;

	i = 0;
	if (!(s1))
		return (NULL);
	k = len(s1, set);
	if (k <= 0)
		k = 0;
	n = malf(s1, set);
	if (!(dst = malloc(sizeof(char) * k + 1)))
		return (0);
	while (k > i)
	{
		dst[i] = s1[n];
		i++;
		n++;
	}
	dst[i] = 0;
	return (dst);
}
