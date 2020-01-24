/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:04:21 by marandre          #+#    #+#             */
/*   Updated: 2020/01/24 20:16:39 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

static	int		sized(int n)
{
	int	result;

	if (n == -2147483648)
		return (11);
	result = 1;
	if (n < 0)
	{
		result++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char			*ft_itoa(int n)
{
	char			*result;
	int				i;
	unsigned int	nbr;

	i = sized(n);
	if (!(result = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		nbr = -1 * n;
		result[0] = '-';
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		result[i--] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (result);
}
