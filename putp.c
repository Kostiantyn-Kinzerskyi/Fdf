/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:40:48 by kkinzers          #+#    #+#             */
/*   Updated: 2019/02/25 16:40:50 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		line_p(t_line *b, t_mlx *a)
{
	a->deltax = fabs(round(b->x2) - round(b->x1));
	a->deltay = fabs(round(b->y2) - round(b->y1));
	a->signx = round(b->x1) < round(b->x2) ? 1 : -1;
	a->signy = round(b->y1) < round(b->y2) ? 1 : -1;
	a->error = a->deltax - a->deltay;
	mlx_pixel_put(a->mlx_ptr, a->win_ptr, round(b->x2), round(b->y2), b->col);
	while (round(b->x1) != round(b->x2) || round(b->y1) != round(b->y2))
	{
		mlx_pixel_put(a->mlx_ptr, a->win_ptr,
			round(b->x1), round(b->y1), b->col);
		a->error2 = a->error * 2;
		if (a->error2 > -a->deltay)
		{
			a->error -= a->deltay;
			b->x1 += a->signx;
		}
		if (a->error2 < a->deltax)
		{
			a->error += a->deltax;
			b->y1 += a->signy;
		}
	}
}

void		sup_pixel_p(int i, int j, t_mlx *a, t_line *b)
{
	j = 0;
	while (j < a->count_x)
	{
		i = 0;
		while ((i + 1) < a->count_y)
		{
			b->x1 = a->p[i][j].x * a->x + a->x1;
			b->y1 = a->p[i][j].y * a->x + a->y;
			b->x2 = a->p[i + 1][j].x * a->x + a->x1;
			b->y2 = a->p[i + 1][j].y * a->x + a->y;
			b->col = a->p[i][j].color;
			if (a->p[i][j].color == 0x99ff9E ||
				a->p[i + 1][j].color == 0x99ff9E)
				b->col = 0x99ff9E;
			line_p(b, a);
			i++;
		}
		j++;
	}
}

void		pixel_p(int i, int j, t_mlx *a)
{
	t_line b;

	text_put(a);
	if (a->count_x == 1 && a->count_y == 1)
		mlx_pixel_put(a->mlx_ptr, a->win_ptr, a->p[i][j].x * a->x + a->x1,
			a->p[i][j].y * a->x + a->y, a->p[i][j].color);
	while (i < a->count_y)
	{
		j = 0;
		while ((j + 1) < a->count_x)
		{
			b.x1 = a->p[i][j].x * a->x + a->x1;
			b.y1 = a->p[i][j].y * a->x + a->y;
			b.x2 = a->p[i][j + 1].x * a->x + a->x1;
			b.y2 = a->p[i][j + 1].y * a->x + a->y;
			b.col = a->p[i][j].color;
			if (a->p[i][j].color == 0x99ff9E ||
				a->p[i][j + 1].color == 0x99ff9E)
				b.col = 0x99ff9E;
			line_p(&b, a);
			j++;
		}
		i++;
	}
	sup_pixel_p(i, j, a, &b);
}
