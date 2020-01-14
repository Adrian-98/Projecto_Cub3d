/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:32:57 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/01/14 17:17:42 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void			ft_crouch_jump(t_cub *cub)
{

	if (cub->crouch == 1)
	{
		cub->drawEnd -= 20;
		cub->drawStart -= 20;
	}
	else if (cub->jump == 1)
	{
		cub->drawEnd += 20;
		cub->drawStart += 20;
	}
}
