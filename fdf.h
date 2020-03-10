/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:46:04 by kkinzers          #+#    #+#             */
/*   Updated: 2019/03/18 16:22:37 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H
# define SCREEN_W 1600
# define SCREEN_H 800
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line.h"
# include <mlx.h>

typedef struct	s_line
{
	double		x;
	double		y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			col;
}				t_line;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_mlx
{
	int			zoom_scr;
	char		*file;
	int			step_x;
	int			step_y;
	int			max_x;
	int			max_y;
	int			min_x;
	int			min_y;
	int			static_col;
	int			check_valid;
	double		k;
	double		x0;
	double		y0;
	double		z0;
	double		x;
	double		y;
	double		x1;
	void		*mlx_ptr;
	void		*win_ptr;
	double		error;
	int			dots;
	int			count_x;
	int			count_y;
	int			max_z;
	double		deltax;
	double		deltay;
	double		signx;
	double		signy;
	double		error2;
	t_point		**p;
}				t_mlx;

int				ft_read(char *filename, t_mlx *a);
void			rotate(int key, t_mlx *a);
int				deal_key(int key, t_mlx *a);
void			pixel_p(int i, int j, t_mlx *a);
void			ft_zoom(t_mlx *a, int i);
void			max_y_x(int i, int j, t_mlx *a);
void			isom(int i, int j, t_mlx *a);
void			text_put(t_mlx *a);
int				valid_string(t_mlx *a, char **mas);
void			sup_read_dots(int i, int j, int g, t_mlx *a);
void			second_read(char *filename, t_mlx *a, int j, int i);
void			start_iso(t_mlx *a, int i);
void			paral(t_mlx *a);
void			text_put(t_mlx *a);
int				check_file(char *filename);

#endif
