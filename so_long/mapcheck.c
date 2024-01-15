/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:50:55 by faata             #+#    #+#             */
/*   Updated: 2023/12/04 17:53:52 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_extension(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	if (path[i] == 'r' && path[i - 1] == 'e' && path[i - 2] == 'b'
		&& path[i - 3] == '.')
		return (1);
	return (0);
}

int	overload(t_mlx *st_mlx)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(st_mlx->map[i]) - 1;
	while (st_mlx->map[++i])
	{
		if (len != ft_strlen(st_mlx->map[i]) - 1
			&& i != ft_maplen(st_mlx->map_path) - 1)
			return (0);
	}
	return (1);
}

int	boundary(t_mlx *st_mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (st_mlx->map[0][j] && st_mlx->map[0][j] != '\n')
		if (st_mlx->map[0][j++] != '1')
			return (0);
	j = 0;
	i = ft_maplen(st_mlx->map_path) - 1;
	while (st_mlx->map[i][j])
		if (st_mlx->map[i][j++] != '1')
			return (0);
	i = 0;
	j = 0;
	while (st_mlx->map[i])
		if (st_mlx->map[i++][0] != '1')
			return (0);
	j = ft_strlen(st_mlx->map[0]) - 1;
	while (st_mlx->map[i])
		if (st_mlx->map[i++][j] != '1')
			return (0);
	return (1);
}

int	ft_count(t_mlx *st_mlx, int exit_count, int cookie_count, int monster_count)
{
	int	i;
	int	j;

	i = -1;
	while (st_mlx->map[++i])
	{
		j = -1;
		while (st_mlx->map[i][++j])
		{
			if (st_mlx->map[i][j] == 'C')
				cookie_count += 1;
			else if (st_mlx->map[i][j] == 'E')
				exit_count += 1;
			else if (st_mlx->map[i][j] == 'P' && (monster_count++, 1))
			{
				st_mlx->monster_x = j;
				st_mlx->monster_y = i;
			}
			else if (st_mlx->map[i][j] != '\n' && st_mlx->map[i][j] != '1' && st_mlx->map[i][j] != '0')
				ft_close("Invalid map element(s).\n");
		}
	}
	if (exit_count != 1 || cookie_count == 0 || monster_count != 1)
		return (0);
	return (1);
}

void	map_check(t_mlx *st_mlx)
{
	if (!ft_count(st_mlx, 0, 0, 0))
		ft_close("Incorrect cookie, player or exit count.\n");
	if (!boundary(st_mlx))
		ft_close("Map does not surround by walls.\n");
	if (!overload(st_mlx))
		ft_close("Map lines are not equal.\n");
	if (!(flood_fill(st_mlx) && flood_fill0(st_mlx)))
		ft_close("Map has unreachable element(s).\n");
	if (!ft_extension(st_mlx->map_path))
		ft_close("Map extension does not correct.\n");
}
