/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:50:53 by malluin           #+#    #+#             */
/*   Updated: 2018/12/04 11:58:46 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_to_org(t_win *mlx)
{
	int		i;
	int		c;
	t_map	*tmap;

	tmap = mlx->map;
	i = 0;
	while (i < tmap->size_y)
	{
		c = 0;
		while (c < tmap->size_x)
		{
			mlx->proj[i][c].x -= tmap->size_x / 2;
			mlx->proj[i][c].y -= tmap->size_y / 2;
			c++;
		}
		i++;
	}
}

void	translate_to_center(t_win *mlx)
{
	int i;
	int c;

	i = 0;
	while (i < mlx->map->size_y)
	{
		c = 0;
		while (c < mlx->map->size_x)
		{
			mlx->screen[i][c].u += WIDTH / 2;
			mlx->screen[i][c].v += HEIGHT / 2;
			c++;
		}
		i++;
	}
}
