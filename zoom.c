/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:32:53 by kkinzers          #+#    #+#             */
/*   Updated: 2019/03/07 20:32:55 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		sup_zoom(int i, int j, t_mlx *a)
{
	while (i < a->count_y)
	{
		while (j < a->count_x)
		{
			a->p[i][j].x *= a->x;
			a->p[i][j].y *= a->x;
			a->p[i][j].z *= a->x;
			j++;
		}
		j = 0;
		i++;
	}
}

void		max_y_x(int i, int j, t_mlx *a)
{
	a->max_x = 0;
	a->max_y = 0;
	a->min_x = 0;
	a->min_y = 0;
	while (a->count_y > i)
	{
		j = 0;
		while (a->count_x > j)
		{
			if (a->p[i][j].x < a->min_x)
				a->min_x = a->p[i][j].x;
			if (a->p[i][j].x > a->max_x)
				a->max_x = a->p[i][j].x;
			if (a->p[i][j].y < a->min_y)
				a->min_y = a->p[i][j].y;
			if (a->p[i][j].y > a->max_y)
				a->max_y = a->p[i][j].y;
			j++;
		}
		i++;
	}
	a->y = (SCREEN_H - a->max_y - a->min_y) / 2 + a->step_y;
	a->x1 = (SCREEN_W - a->max_x - a->min_x) / 2 + a->step_x;
}

void		ft_zoom(t_mlx *a, int i)
{
	if (SCREEN_H <= SCREEN_W)
	{
		if (a->count_x >= a->count_y)
			a->x = (SCREEN_H / 2) / a->count_x;
		if (a->count_y > a->count_x)
			a->x = (SCREEN_H / 2) / a->count_y;
		if (a->max_z > a->count_x && a->max_z > a->count_y && i == 0)
			a->x = (SCREEN_H / 2) / a->max_z;
	}
	if (SCREEN_W < SCREEN_H)
	{
		if (a->count_x >= a->count_y)
			a->x = (SCREEN_W / 2) / a->count_x;
		if (a->count_y > a->count_x)
			a->x = (SCREEN_W / 2) / a->count_y;
		if (a->max_z > a->count_x && a->max_z > a->count_y && i == 0)
			a->x = (SCREEN_W / 2) / a->max_z;
	}
	sup_zoom(0, 0, a);
	if (i == 0)
		isom(0, 0, a);
	max_y_x(0, 0, a);
	a->x = 1;
}
