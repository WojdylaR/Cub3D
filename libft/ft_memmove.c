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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*sorc;
	char	*dest;

	i = 0;
	dest = dst;
	sorc = (char *)src;
	if (dest < sorc)
	{
		while (i < len)
		{
			dest[i] = sorc[i];
			i++;
		}
	}
	if (dest > sorc)
	{
		while (len > 0)
		{
			dest[len - 1] = sorc[len - 1];
			len--;
		}
	}
	return (dest);
}
