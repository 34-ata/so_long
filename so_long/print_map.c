/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:50:37 by faata             #+#    #+#             */
/*   Updated: 2023/12/04 17:54:04 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printmap_p(t_mlx *st_mlx, int x, int y)
{
	mlx_put_image_to_window(st_mlx->mlx, st_mlx->mlx_win,
		st_mlx->parquet, x, y);
	mlx_put_image_to_window(st_mlx->mlx, st_mlx->mlx_win,
		st_mlx->monster, x, y);
	st_mlx->monster_x = x;
	st_mlx->monster_y = y;
}

void	ft_printmap_c(t_mlx *st_mlx, int x, int y)
{
	mlx_put_image_to_window(st_mlx->mlx, st_mlx->mlx_win,
		st_mlx->parquet, x, y);
	mlx_put_image_to_window(st_mlx->mlx, st_mlx->mlx_win, st_mlx->cookie, x, y);
	st_mlx->count_cookie += 1;
}

void	ft_printmap_e(t_mlx *st_mlx, int x, int y)
{
	mlx_put_image_to_window(st_mlx->mlx, st_mlx->mlx_win,
		st_mlx->parquet, x, y);
	mlx_put_image_to_window(st_mlx->mlx, st_mlx->mlx_win,
		st_mlx->exit, x, y);
}

void	ft_check_this_out(char c, t_mlx *st_mlx, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(st_mlx->mlx, st_mlx->mlx_win,
			st_mlx->wall, x, y);
	else if (c == 'P')
		ft_printmap_p(st_mlx, x, y);
	else if (c == 'C')
		ft_printmap_c(st_mlx, x, y);
	else if (c == '0')
		mlx_put_image_to_window(st_mlx->mlx, st_mlx->mlx_win,
			st_mlx->parquet, x, y);
	else if (c == 'E')
		ft_printmap_e(st_mlx, x, y);
	else if (c != '\n')
		exit (1);
}

void	ft_printmap(t_mlx *st_mlx, int i, int x, int y)
{
	int	j;

	st_mlx->count_cookie = 0;
	while (st_mlx->map[++i])
	{
		j = -1;
		x = 0;
		while (st_mlx->map[i][++j])
		{
			ft_check_this_out(st_mlx->map[i][j], st_mlx, x, y);
			x += 64;
			st_mlx->map_x += 64;
		}
		y += 64;
		st_mlx->map_y += 64;
	}
}
