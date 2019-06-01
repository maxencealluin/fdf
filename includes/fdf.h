/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:22:25 by malluin           #+#    #+#             */
/*   Updated: 2018/12/06 17:01:19 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080
# define XOFF (WIDTH / 2)
# define YOFF (HEIGHT / 10)

# include "mlx.h"
# include "libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_coord
{
	int			x;
	int			y;
	int			z;
	t_point		*ptr;
}				t_coord;

typedef struct	s_pix {
	int			u;
	int			v;
	int			w;
	t_point		*ptr;
}				t_pix;

typedef	struct	s_map {
	int			size_x;
	int			size_y;
	t_point		**map;
	t_point		*high;
	t_point		*low;
}				t_map;

typedef struct	s_der {
	int			dx;
	int			dy;
	int			e;
	int			signe;
	int			or;
	int			swap;
}				t_der;

typedef	struct	s_win {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image_ptr;
	char		*image_str;
	t_map		*map;
	int			*palette;
	t_coord		**proj;
	t_pix		**screen;
	float		scale;
	int			iso;
	float		offset_z;
}				t_win;

void			usage(char *av);
void			errortoomany(char *av);
void			error();

t_map			*input_to_tab(char *av);
int				map_to_proj(t_win *mlx);
int				proj_to_screen(t_win *mlx);

int				rgb(unsigned char red, unsigned char green, unsigned char blue);

void			xline(t_win *mlx, t_pix px1, t_pix px2);
void			yline(t_win *mlx, t_pix px1, t_pix px2);
int				mouse_line(int button, int x, int y, void *param);
void			place_line(t_win *param, t_pix px1, t_pix px2);
void			place_pixel(t_win *mlx, int x, int y, int color);

int				refresh_legend(void *param);
void			legend_text(t_win *mlx);
void			legend_box(t_win *mlx);
void			boxes(t_win *mlx);
void			draw_grid(t_win	*mlx);
void			offset_z(t_win *mlx, float offset);

int				image_init(t_win *mlx);
int				refresh_init(t_win *mlx);
int				refresh_show(t_win *mlx);

void			rotate(t_win *mlx, float ax, float ay, float az);

void			translate_to_org(t_win *mlx);
void			translate_to_center (t_win *mlx);
void			scale(t_win *mlx, float coef);

void			iso(t_win *mlx);

int				deal_key(int key, void *param);

int				lin_interx(t_pix px1, t_pix px2, int x, int signe);
int				lin_intery(t_pix px1, t_pix px2, int y, int signe);
void			color_init(t_win *mlx);
int				*palette_init(char *av);

#endif
