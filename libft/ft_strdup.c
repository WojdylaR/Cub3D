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

char	*ft_strdup(const char *s1)
{
	int		j;
	int		i;
	char	*str;

	i = 0;
	j = 0;
	if (!(s1))
		return (0);
	while (s1[i])
		i++;
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (0);
	while (i > j)
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
