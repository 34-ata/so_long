/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:51:11 by faata             #+#    #+#             */
/*   Updated: 2023/12/04 17:53:31 by faata            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill2(char **map, int x, int y, t_mlx *st_mlx)
{
	if (x >= st_mlx->map_x || y >= st_mlx->map_y || y < 0 || x < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill2(map, x + 1, y, st_mlx);
	flood_fill2(map, x - 1, y, st_mlx);
	flood_fill2(map, x, y + 1, st_mlx);
	flood_fill2(map, x, y - 1, st_mlx);
}

void	flood_fill3(char **map, int x, int y, t_mlx *st_mlx)
{
	if (x >= st_mlx->map_x || y >= st_mlx->map_y || y < 0 || x < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'E')
		return ;
	map[y][x] = 'X';
	flood_fill3(map, x + 1, y, st_mlx);
	flood_fill3(map, x - 1, y, st_mlx);
	flood_fill3(map, x, y + 1, st_mlx);
	flood_fill3(map, x, y - 1, st_mlx);
}

int	flood_fill(t_mlx *st_mlx)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = ft_getmap(st_mlx->map_path);
	flood_fill2(temp, st_mlx->monster_x, st_mlx->monster_y, st_mlx);
	while (i < ft_maplen(st_mlx->map_path))
	{
		j = 0;
		while (j < ft_strlen(temp[0]) - 1)
		{
			if (temp[i][j] == 'P' || temp[i][j] == 'C' || temp[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(temp);
	return (1);
}

int	flood_fill0(t_mlx *st_mlx)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = ft_getmap(st_mlx->map_path);
	flood_fill3(temp, st_mlx->monster_x, st_mlx->monster_y, st_mlx);
	while (i < ft_maplen(st_mlx->map_path))
	{
		j = 0;
		while (j < ft_strlen(temp[0]) - 1)
		{
			if (temp[i][j] == 'P' || temp[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(temp);
	return (1);
}

void	ft_putnbr(unsigned int a)
{
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
	else
		write(1, &"0123456789"[a], 1);
}
