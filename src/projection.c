/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:03:50 by malluin           #+#    #+#             */
/*   Updated: 2018/12/05 15:48:15 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	iso(t_win *mlx)
{
	int		i;
	int		j;
	int		prevx;
	t_coord	*coord;

	i = 0;
	while (i < mlx->map->size_y)
	{
		j = 0;
		while (j < mlx->map->size_x)
		{
			coord = &(mlx->proj[i][j]);
			prevx = coord->x;
			coord->x = (coord->x - coord->y) * cos(0.523599);
			coord->y = -coord->z + (prevx + coord->y) * sin(0.523599);
			j++;
		}
		i++;
	}
}
