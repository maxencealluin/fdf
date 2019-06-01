/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:49:16 by malluin           #+#    #+#             */
/*   Updated: 2018/12/05 18:08:10 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	int	r;
	int	g;
	int	b;

	r = (red << 16) & 0xFF0000;
	g = (green << 8) & 0x00FF00;
	b = blue & 0x000FF;
	return (0x000000 | r | g | b);
}

int		*palette_init(char *av)
{
	int *palette;

	if (!(palette = malloc(sizeof(int) * 5)))
		return (0);
	if (av && ft_strcmp(av, "GEO") == 0)
	{
		palette[0] = rgb(27, 38, 79);
		palette[1] = rgb(41, 76, 155);
		palette[2] = rgb(234, 212, 161);
		palette[3] = rgb(93, 178, 85);
		palette[4] = rgb(229, 229, 229);
	}
	else
	{
		palette[0] = rgb(242, 215, 238);
		palette[1] = rgb(211, 188, 192);
		palette[2] = rgb(165, 102, 139);
		palette[3] = rgb(105, 48, 109);
		palette[4] = rgb(14, 16, 61);
	}
	return (palette);
}

void	color_init(t_win *mlx)
{
	int		i;
	int		j;
	float	ratio;
	int		range;

	range = 1;
	if (mlx->map->high && mlx->map->low)
		range = mlx->map->high->z - mlx->map->low->z;
	range = range <= 0 ? 1 : range;
	i = 0;
	j = 0;
	while (i < mlx->map->size_y)
	{
		j = 0;
		while (j < mlx->map->size_x)
		{
			ratio = ((float)mlx->map->map[i][j].z +
					ft_fabs((float)mlx->map->low->z)) / (float)range;
			mlx->map->map[i][j++].color =
				mlx->palette[(int)(ratio * 4.)];
		}
		i++;
	}
}
