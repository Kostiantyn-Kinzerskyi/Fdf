/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 17:30:44 by kkinzers          #+#    #+#             */
/*   Updated: 2019/03/09 17:30:54 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_z(int i, int j, t_mlx *a, double k)
{
	while (i < a->count_y)
	{
		j = 0;
		while (j < a->count_x)
		{
			a->x0 = a->p[i][j].x;
			a->y0 = a->p[i][j].y;
			a->p[i][j].x = a->x0 * cos(k) - a->y0 * sin(k);
			a->p[i][j].y = a->x0 * sin(k) + a->y0 * cos(k);
			j++;
		}
		i++;
	}
	max_y_x(0, 0, a);
}

void		rotate_y(int i, int j, t_mlx *a, double k)
{
	while (i < a->count_y)
	{
		j = 0;
		while (j < a->count_x)
		{
			a->x0 = a->p[i][j].x;
			a->z0 = a->p[i][j].z;
			a->p[i][j].x = a->x0 * cos(k) + a->z0 * sin(k);
			a->p[i][j].z = -a->x0 * sin(k) + a->z0 * cos(k);
			j++;
		}
		i++;
	}
	max_y_x(0, 0, a);
}

void		rotate_x(int i, int j, t_mlx *a, double k)
{
	while (i < a->count_y)
	{
		j = 0;
		while (j < a->count_x)
		{
			a->y0 = a->p[i][j].y;
			a->z0 = a->p[i][j].z;
			a->p[i][j].y = a->y0 * cos(k) + a->z0 * sin(k);
			a->p[i][j].z = -a->y0 * sin(k) + a->z0 * cos(k);
			j++;
		}
		i++;
	}
	max_y_x(0, 0, a);
}

void		rotate(int key, t_mlx *a)
{
	if (key == 18)
		rotate_x(0, 0, a, 0.03);
	if (key == 19)
		rotate_x(0, 0, a, -0.03);
	if (key == 20)
		rotate_y(0, 0, a, 0.03);
	if (key == 21)
		rotate_y(0, 0, a, -0.03);
	if (key == 23)
		rotate_z(0, 0, a, 0.03);
	if (key == 22)
		rotate_z(0, 0, a, -0.03);
}
