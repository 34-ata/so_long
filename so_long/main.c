/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:50:45 by faata             #+#    #+#             */
/*   Updated: 2023/12/04 17:53:46 by faata            ###   ########.fr       */
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
			"/Users/faata/Desktop/so_long/xpms/wall", &a, &b);
	st_mlx->monster = mlx_xpm_file_to_image(st_mlx->mlx,
			"/Users/faata/Desktop/so_long/xpms/monster", &a, &b);
	st_mlx->cookie = mlx_xpm_file_to_image(st_mlx->mlx,
			"/Users/faata/Desktop/so_long/xpms/cookie", &a, &b);
	st_mlx->parquet = mlx_xpm_file_to_image(st_mlx->mlx,
			"/Users/faata/Desktop/so_long/xpms/parquet", &a, &b);
	st_mlx->exit = mlx_xpm_file_to_image(st_mlx->mlx,
			"/Users/faata/Desktop/so_long/xpms/exit", &a, &b);
	st_mlx->mlx_win = mlx_new_window(st_mlx->mlx,
			(st_mlx->map_x * 64), (st_mlx->map_y * 64), "So_long");
}

int	ft_close(void *x)
{
	(void)x;
	exit(1);
}

int	main(int ac, char **av)
{
	t_mlx	st_mlx;

	if (ac != 2)
		return (write(1, "Error\n", 6), 1);
	st_mlx.map_path = av[1];
	st_mlx.mlx = mlx_init();
	st_mlx.map = ft_getmap(av[1]);
	st_mlx.map_x = ft_strlen(st_mlx.map[0]) - 1;
	st_mlx.map_y = ft_maplen(st_mlx.map_path);
	if (map_check(&st_mlx) == 0)
		exit (write(1, "Error!\n", 7));
	xpm_init(&st_mlx);
	ft_printmap(&st_mlx, -1, 0, 0);
	mlx_hook(st_mlx.mlx_win, 02, 0L, key_hook, &st_mlx);
	mlx_hook(st_mlx.mlx_win, 17, 0L, ft_close, &st_mlx);
	mlx_loop(st_mlx.mlx);
}
