/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:24:17 by malluin           #+#    #+#             */
/*   Updated: 2018/12/06 17:50:27 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		image_init(t_win *mlx)
{
	int bpp;
	int s_l;
	int end;

	if (!(mlx->image_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT)))
		return (0);
	if (!(mlx->image_str = mlx_get_data_addr(mlx->image_ptr, &bpp, &s_l, &end)))
		return (0);
	return (1);
}

int		refresh_init(t_win *mlx)
{
	if (mlx->mlx_ptr && mlx->image_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->image_ptr);
	if (!(image_init(mlx)))
		return (0);
	if (!(map_to_proj(mlx)))
		return (0);
	if (mlx->offset_z != 1.0)
		offset_z(mlx, mlx->offset_z);
	translate_to_org(mlx);
	scale(mlx, mlx->scale);
	if (mlx->iso == 1)
		iso(mlx);
	return (1);
}

int		refresh_show(t_win *mlx)
{
	if (!(proj_to_screen(mlx)))
		return (0);
	translate_to_center(mlx);
	draw_grid(mlx);
	boxes(mlx);
	legend_box(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image_ptr, 0, 0);
	legend_text(mlx);
	return (1);
}

void	place_pixel(t_win *mlx, int u, int v, int color)
{
	int	coord;
	int	red;
	int	blue;
	int	green;

	if (color == 0)
		color = rgb(255, 255, 255);
	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = (color) & 0xFF;
	u = ft_imax(u, 0);
	coord = u * 4 + v * WIDTH * 4;
	if (coord < WIDTH * 4 * HEIGHT && coord >= 0 && u < WIDTH)
	{
		(mlx->image_str)[coord] = blue;
		(mlx->image_str)[coord + 1] = green;
		(mlx->image_str)[coord + 2] = red;
	}
}

int		refresh_legend(void *param)
{
	t_win *mlx;

	mlx = (t_win *)param;
	legend_text(mlx);
	return (1);
}
