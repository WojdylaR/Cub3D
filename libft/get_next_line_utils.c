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

#include "get_next_line.h"

static int		ft_strlen_gnl(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_substr_gnl(char *s, int start, int len)
{
	int		i;
	char	*dst;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(dst = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (start > ft_strlen_gnl(s) || s[0] == 0)
	{
		dst[0] = 0;
		return (dst);
	}
	while (len-- > 0 && s[start])
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}

char			*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dst;

	j = 0;
	i = 0;
	if (!(s1 && s2))
		return (NULL);
	if (!(dst = malloc(sizeof(char) * (ft_strlen_gnl(s1)
		+ ft_strlen_gnl(s2)) + 1)))
		return (0);
	while (s1[i])
		dst[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dst[j++] = s2[i++];
	dst[j] = '\0';
	free(s1);
	return (dst);
}

char			*ft_strdup_gnl(char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + 1))))
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int				ft_strlcpy_gnl(char *dest, char *src)
{
	int		i;

	i = 0;
	if (!(dest && src))
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (i);
}
