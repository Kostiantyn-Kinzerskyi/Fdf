/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:05:58 by kkinzers          #+#    #+#             */
/*   Updated: 2019/02/06 17:19:07 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			close_x(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void		sup_key(int key, t_mlx *a)
{
	if (key == 34)
		start_iso(a, 0);
	if (key == 35)
		start_iso(a, 1);
	if (key == 124)
	{
		a->step_x += 8;
		a->x1 += 8;
	}
	if (key == 123)
	{
		a->step_x -= 8;
		a->x1 -= 8;
	}
	if (key == 126)
	{
		a->step_y -= 8;
		a->y -= 8;
	}
	if (key == 125)
	{
		a->step_y += 8;
		a->y += 8;
	}
}

int			deal_key(int key, t_mlx *a)
{
	if (key == 53)
		exit(0);
	if (key == 78)
	{
		a->zoom_scr--;
		a->x /= 1.05;
	}
	if (key == 69)
	{
		a->zoom_scr++;
		a->x *= 1.05;
	}
	rotate(key, a);
	sup_key(key, a);
	mlx_clear_window(a->mlx_ptr, a->win_ptr);
	pixel_p(0, 0, a);
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx	a;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf map_file");
		return (0);
	}
	a.file = argv[1];
	if (!ft_read(argv[1], &a))
	{
		ft_putendl("Invalid file");
		return (0);
	}
	a.mlx_ptr = mlx_init();
	a.win_ptr = mlx_new_window(a.mlx_ptr, SCREEN_W, SCREEN_H, "42");
	pixel_p(0, 0, &a);
	mlx_hook(a.win_ptr, 2, 2, deal_key, &a);
	mlx_hook(a.win_ptr, 17, 1L << 17, close_x, &a);
	mlx_loop(a.mlx_ptr);
	return (0);
}
