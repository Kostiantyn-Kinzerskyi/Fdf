/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:45:32 by kkinzers          #+#    #+#             */
/*   Updated: 2019/03/13 15:45:35 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isom(int i, int j, t_mlx *a)
{
	double	previous_x;
	double	previous_y;

	while (i < a->count_y)
	{
		while (j < a->count_x)
		{
			previous_x = a->p[i][j].x;
			previous_y = a->p[i][j].y;
			a->p[i][j].x = (previous_x - previous_y) * cos(0.523599);
			a->p[i][j].y = -a->p[i][j].z + (previous_x + previous_y)
			* sin(0.523599);
			j++;
		}
		j = 0;
		i++;
	}
}

void		sup_text_put(t_mlx *a)
{
	char *g;

	mlx_string_put(a->mlx_ptr, a->win_ptr, SCREEN_W - 150, 20, 0x4EF684,
		"Move");
	mlx_string_put(a->mlx_ptr, a->win_ptr, SCREEN_W - 150, 37, 0x4EF684, "X:");
	g = ft_itoa(a->step_x);
	mlx_string_put(a->mlx_ptr, a->win_ptr, SCREEN_W - 120, 37, 0x4EF684, g);
	free(g);
	mlx_string_put(a->mlx_ptr, a->win_ptr, SCREEN_W - 150, 54, 0x4EF684, "Y:");
	g = ft_itoa(a->step_y);
	mlx_string_put(a->mlx_ptr, a->win_ptr, SCREEN_W - 120, 54, 0x4EF684, g);
	free(g);
	mlx_string_put(a->mlx_ptr, a->win_ptr, SCREEN_W - 150, 71, 0x4EF684,
		"Zoom:");
	g = ft_itoa(a->zoom_scr);
	mlx_string_put(a->mlx_ptr, a->win_ptr, SCREEN_W - 95, 71, 0x4EF684, g);
	free(g);
}

void		text_put(t_mlx *a)
{
	mlx_string_put(a->mlx_ptr, a->win_ptr, 65, 20, 0x4EF684, "How to Use");
	mlx_string_put(a->mlx_ptr, a->win_ptr, 65, 37, 0x4EF684, "Zoom: + / -");
	mlx_string_put(a->mlx_ptr, a->win_ptr, 65, 54, 0x4EF684, "Move: Arrows");
	mlx_string_put(a->mlx_ptr, a->win_ptr, 65, 71, 0x4EF684, "Rotate:");
	mlx_string_put(a->mlx_ptr, a->win_ptr, 85, 88, 0x4EF684, "X-Axis - 1 / 2");
	mlx_string_put(a->mlx_ptr, a->win_ptr, 85, 105, 0x4EF684, "Y-Axis - 3 / 4");
	mlx_string_put(a->mlx_ptr, a->win_ptr, 85, 122, 0x4EF684, "Z-Axis - 5 / 6");
	mlx_string_put(a->mlx_ptr, a->win_ptr, 65, 139, 0x4EF684,
		"Projection: I / P");
	mlx_string_put(a->mlx_ptr, a->win_ptr, 65, 156, 0x4EF684, "Exit: Esc");
	sup_text_put(a);
}

void		second_read(char *filename, t_mlx *a, int j, int i)
{
	int		fd;
	char	*line;
	char	**mas;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		mas = ft_strsplit(line, ' ');
		free(line);
		i = 0;
		while (mas[i])
		{
			sup_read_dots(i, j, ft_atoi(mas[i]), a);
			i++;
		}
		i = 0;
		while (mas[i])
			free(mas[i++]);
		free(mas);
		j++;
	}
	free(line);
}

void		start_iso(t_mlx *a, int i)
{
	a->static_col = 0xFFFFFF;
	a->max_z = 0;
	a->step_x = 0;
	a->step_y = 0;
	a->check_valid = 0;
	a->zoom_scr = 0;
	second_read(a->file, a, 0, 0);
	if (i == 0)
		ft_zoom(a, 0);
	else
		ft_zoom(a, 1);
}
