/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:50:37 by faata             #+#    #+#             */
/*   Updated: 2024/01/15 13:21:36 by faata            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include <fcntl.h>
# include "mlx/mlx.h"

typedef struct t_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*monster;
	void	*cookie;
	void	*wall;
	void	*parquet;
	void	*exit;
	char	**map;
	char	*map_path;
	int		count_cookie;
	int		monster_x;
	int		monster_y;
	int		map_x;
	int		map_y;
	int		num_of_mov;
	int		i;
	int		j;
}	t_mlx;

void	map_check(t_mlx *st_mlx);
void	flood_fill3(char **map, int x, int y, t_mlx *st_mlx);
void	flood_fill2(char **map, int x, int y, t_mlx *st_mlx);
int		flood_fill(t_mlx *st_mlx);
int		flood_fill0(t_mlx *st_mlx);
int		key_hook(int keycode, t_mlx *vars);
void	ft_printmap(t_mlx *st_mlx, int i, int x, int y);
int		ft_maplen(char *path);
char	**ft_getmap(char *path);
void	ft_putnbr(unsigned int a);
int		ft_close(char *x);

#endif
