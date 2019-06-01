/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:21:47 by malluin           #+#    #+#             */
/*   Updated: 2018/12/06 16:58:19 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	initialize(t_win *mlx, int ac, char **av)
{
	if (!(mlx->map = input_to_tab(av[1])))
		error();
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "FDF")))
		return (0);
	mlx->image_ptr = NULL;
	if (ac >= 3)
		mlx->palette = palette_init(av[2]);
	else
		mlx->palette = palette_init(NULL);
	if (!(mlx->palette))
		return (0);
	color_init(mlx);
	mlx->scale = 1.0;
	mlx->offset_z = 1.0;
	mlx->iso = 1.0;
	return (1);
}

int	main(int ac, char **av)
{
	t_win	*mlx;

	if (ac == 1)
		usage(av[0]);
	else if (ac > 3)
		errortoomany(av[0]);
	if (!(mlx = (t_win *)malloc(sizeof(t_win))))
		return (0);
	if (!(initialize(mlx, ac, av)))
		return (0);
	if (!(refresh_init(mlx)))
		return (0);
	if (!(refresh_show(mlx)))
		return (0);
	mlx_key_hook(mlx->win_ptr, deal_key, (void *)mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_line, (void *)(mlx));
	mlx_expose_hook(mlx->win_ptr, refresh_legend, (void *)(mlx));
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
