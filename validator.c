/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:16:57 by kkinzers          #+#    #+#             */
/*   Updated: 2019/03/12 12:16:58 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_file(char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		s;

	s = 0;
	fd = open(filename, O_RDONLY);
	read(fd, "", 0);
	i = get_next_line(fd, &line);
	free(line);
	if (i == 0 || i == -1)
		return (0);
	return (1);
}

int			valid_string(t_mlx *a, char **mas)
{
	int		i;
	int		j;

	i = 0;
	while (mas[i])
	{
		while (mas[i][j])
		{
			if (mas[i][j] >= 33 && mas[i][j] <= 126)
				j++;
			else
				return (0);
		}
		j = 0;
		i++;
	}
	if (a->count_x == 0)
	{
		a->count_x = i;
	}
	if (i != a->count_x || (a->count_y > 0 && i == 0))
		return (0);
	return (1);
}
