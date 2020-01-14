/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:40:28 by glopez-a          #+#    #+#             */
/*   Updated: 2019/11/12 13:18:12 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libcub.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*aux1;
	const unsigned char	*aux2;

	aux1 = (unsigned char *)dst;
	aux2 = (unsigned char *)src;
	if (dst || src)
	{
		while (n > 0)
		{
			*aux1 = *aux2;
			n--;
			aux1++;
			aux2++;
		}
		return (dst);
	}
	return (0);
}
