/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:50:45 by faata             #+#    #+#             */
/*   Updated: 2024/01/18 17:31:03 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_maplen(char *path)
{
	char	*temp;
	int		len;
	int		fd;

	len = 0;
	fd = open(path, O_RDWR);
	if (fd == -1)
		ft_close("Cannot open map.\n");
	temp = get_next_line(fd);
	while (temp)
	{
		len++;
		free (temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (len);
}

char	**ft_getmap(char *path)
{
	char	**res;
	int		len;
	int		fd;
	int		i;

	len = ft_maplen(path);
	i = 0;
	res = (char **)malloc((len + 1) * sizeof(char *));
	if (!res)
		return (0);
	fd = open(path, O_RDWR);
	if (fd == -1)
		ft_close("Cannot open map.\n");
	while (i < len)
		res[i++] = get_next_line(fd);
	res[i] = 0;
	close(fd);
	return (res);
}

void	xpm_init(t_mlx *st_mlx)
{
	int	a;
	int	b;

	st_mlx->wall = mlx_xpm_file_to_image(st_mlx->mlx,
			"textures/wall", &a, &b);
	st_mlx->monster = mlx_xpm_file_to_image(st_mlx->mlx,
			"textures/monster", &a, &b);
	st_mlx->cookie = mlx_xpm_file_to_image(st_mlx->mlx,
			"textures/cookie", &a, &b);
	st_mlx->parquet = mlx_xpm_file_to_image(st_mlx->mlx,
			"textures/parquet", &a, &b);
	st_mlx->exit = mlx_xpm_file_to_image(st_mlx->mlx,
			"textures/exit", &a, &b);
	if (!st_mlx->wall || !st_mlx->monster || !st_mlx->cookie
		|| !st_mlx->parquet || !st_mlx->exit)
		ft_close("Cannot find xpms.\n");
	st_mlx->mlx_win = mlx_new_window(st_mlx->mlx,
			(st_mlx->map_x * 64), (st_mlx->map_y * 64), "So_long");
}

int	ft_close(char *x)
{
	write(1, x, ft_strlen(x));
	exit(1);
}

int	main(int ac, char **av)
{
	t_mlx	st_mlx;

	if (ac != 2)
		ft_close("Invalid argument count.\n");
	st_mlx.map_path = av[1];
	if (!ft_extension(st_mlx.map_path))
		ft_close("Map extension does not correct.\n");
	st_mlx.mlx = mlx_init();
	st_mlx.map = ft_getmap(av[1]);
	st_mlx.map_x = ft_strlen(st_mlx.map[0]) - 1;
	st_mlx.map_y = ft_maplen(st_mlx.map_path);
	map_check(&st_mlx);
	xpm_init(&st_mlx);
	ft_printmap(&st_mlx, -1, 0, 0);
	mlx_hook(st_mlx.mlx_win, 02, 0L, key_hook, &st_mlx);
	mlx_hook(st_mlx.mlx_win, 17, 0L, ft_close, "Successfully closed.\n");
	mlx_loop(st_mlx.mlx);
}
