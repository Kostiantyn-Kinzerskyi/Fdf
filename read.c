/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:57:28 by kkinzers          #+#    #+#             */
/*   Updated: 2019/02/07 18:57:29 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		sup_read_dots(int i, int j, int g, t_mlx *a)
{
	a->p[j][i].x = i;
	a->p[j][i].y = j;
	a->p[j][i].z = g;
	if (abs(g) > a->max_z)
		a->max_z = abs(g);
	if (g > 0)
		a->p[j][i].color = 0x99ff9E;
	else
		a->p[j][i].color = 0xFFFFFF;
}

void		free_mas(char **mas)
{
	int		i;

	i = 0;
	while (mas[i])
		free(mas[i++]);
	free(mas);
}

void		read_dots(char *filename, t_mlx *a, int j, int i)
{
	int		fd;
	char	*line;
	char	**mas;

	a->p = (t_point **)malloc(sizeof(t_point *) * a->count_y);
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		mas = ft_strsplit(line, ' ');
		free(line);
		i = 0;
		a->p[j] = (t_point *)malloc(sizeof(t_point) * a->count_x);
		while (mas[i])
		{
			sup_read_dots(i, j, ft_atoi(mas[i]), a);
			i++;
		}
		free_mas(mas);
		j++;
	}
	free(line);
}

int			count_dots(char *filename, t_mlx *a)
{
	int		fd;
	char	*line;
	char	**mas;
	int		i;

	a->dots = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i = 0;
		a->count_y++;
		mas = ft_strsplit(line, ' ');
		free(line);
		while (mas[i])
			i++;
		a->dots += i;
		if (!valid_string(a, mas))
			return (0);
		free_mas(mas);
	}
	free(line);
	return (1);
}

int			ft_read(char *filename, t_mlx *a)
{
	if (!check_file(filename))
		return (0);
	a->static_col = 0xFFFFFF;
	a->max_z = 0;
	a->step_x = 0;
	a->step_y = 0;
	a->check_valid = 0;
	a->count_x = 0;
	a->count_y = 0;
	a->zoom_scr = 0;
	if (!count_dots(filename, a))
		return (0);
	read_dots(filename, a, 0, 0);
	ft_zoom(a, 0);
	return (1);
}
