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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	str = (char *)haystack;
	i = 0;
	if (needle[0] == 0)
		return (str);
	while (haystack[i] && len > 0)
	{
		j = 0;
		k = i;
		while ((haystack[k] == needle[j] && len > 0) || needle[0] == '\0')
		{
			k++;
			j++;
			len--;
			if (needle[j] == '\0')
				return (str + i);
		}
		len = len + j - 1;
		i++;
	}
	return (NULL);
}
