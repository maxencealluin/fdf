/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:38:31 by malluin           #+#    #+#             */
/*   Updated: 2018/12/06 18:30:32 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fdf.h"

t_point	*char_to_int(char *str, t_map *tmap, int y, int i)
{
	t_point		*ptab;
	char		**ctab;

	ctab = ft_strsplit(str, ' ');
	while (ctab[i])
		i++;
	if (tmap->size_x == 0)
		tmap->size_x = i;
	if (tmap->size_x != i || i == 0)
		error();
	if (!(ptab = (t_point *)malloc(sizeof(t_point) * i)))
		return (0);
	i = -1;
	while (ctab[++i])
	{
		ptab[i].z = ft_atoi(ctab[i]);
		if (!(tmap->high) || tmap->high->z < ptab[i].z)
			tmap->high = &ptab[i];
		if (!(tmap->low) || tmap->low->z > ptab[i].z)
			tmap->low = &ptab[i];
		ptab[i].x = i;
		ptab[i].y = y;
	}
	ft_deltab(&ctab);
	return (ptab);
}

t_map	*read_to_tab(int fd, t_map *tmap, int i, int c)
{
	char	**ctab;

	if (!(ctab = (char **)malloc(sizeof(char *) * (c + 1))))
		return (0);
	while (get_next_line(fd, &(ctab[i++])) > 0)
		;
	ctab[i] = 0;
	if (i == 1)
		error();
	if (!(tmap->map = (t_point **)malloc(sizeof(t_point *) * (i + 1))))
		return (0);
	i = -1;
	tmap->size_x = 0;
	while (ctab[++i][0])
		tmap->map[i] = char_to_int(ctab[i], tmap, i, 0);
	if (i == 0)
		error();
	tmap->size_y = i - 1 < 0 ? 1 : i;
	ft_deltab(&ctab);
	return (tmap);
}

t_map	*input_to_tab(char *av)
{
	int		fd;
	t_map	*tmap;
	char	buff[512];
	int		c;
	int		i;

	fd = open(av, O_RDONLY);
	c = 1;
	while (read(fd, buff, 512) > 0)
	{
		i = 0;
		while (i < 512)
			if (buff[i++] == '\n')
				c++;
	}
	close(fd);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!(tmap = (t_map *)malloc(sizeof(t_map))))
		return (0);
	tmap->high = NULL;
	tmap->low = NULL;
	tmap = read_to_tab(fd, tmap, 0, c);
	return (tmap);
}

int		map_to_proj(t_win *mlx)
{
	static int		first = 0;
	int				i;
	int				j;

	if (first == 0)
		if (!(mlx->proj = malloc(sizeof(t_coord *) * mlx->map->size_y)))
			return (0);
	i = 0;
	while (i < mlx->map->size_y)
	{
		if (first == 0)
			if (!(mlx->proj[i] = (t_coord *)malloc(sizeof(t_coord)
			* mlx->map->size_x)))
				return (0);
		j = -1;
		while (++j < mlx->map->size_x)
		{
			mlx->proj[i][j].x = mlx->map->map[i][j].x;
			mlx->proj[i][j].y = mlx->map->map[i][j].y;
			mlx->proj[i][j].z = mlx->map->map[i][j].z;
			mlx->proj[i][j].ptr = &mlx->map->map[i][j];
		}
		i++;
	}
	return (first = 1);
}

int		proj_to_screen(t_win *mlx)
{
	static int	first = 0;
	int			i;
	int			j;

	if (first == 0)
		if (!(mlx->screen = malloc(sizeof(t_pix *) * mlx->map->size_y)))
			return (0);
	i = 0;
	while (i < mlx->map->size_y)
	{
		if (first == 0)
			if (!(mlx->screen[i] = (t_pix *)malloc(sizeof(t_pix) *
				mlx->map->size_x)))
				return (0);
		j = -1;
		while (++j < mlx->map->size_x)
		{
			mlx->screen[i][j].u = mlx->proj[i][j].x;
			mlx->screen[i][j].v = mlx->proj[i][j].y;
			mlx->screen[i][j].w = mlx->proj[i][j].z;
			mlx->screen[i][j].ptr = mlx->proj[i][j].ptr;
		}
		i++;
	}
	return (first = 1);
}
