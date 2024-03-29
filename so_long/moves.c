/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:50:10 by faata             #+#    #+#             */
/*   Updated: 2023/12/27 13:16:54 by faata            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_right(t_mlx *vars)
{
	if (vars->map[vars->monster_y / 64][(vars->monster_x / 64) + 1] == 'E'
			&& vars->count_cookie == 0)
		exit (1);
	if (vars->map[vars->monster_y / 64][(vars->monster_x / 64) + 1] != '1'
		&& vars->map[vars->monster_y / 64][(vars->monster_x / 64) + 1] != 'E')
	{
		if (vars->map[vars->monster_y / 64][(vars->monster_x / 64) + 1] == 'C')
			vars->count_cookie -= 1;
		vars->map[vars->monster_y / 64][vars->monster_x / 64] = '0';
		vars->map[vars->monster_y / 64][(vars->monster_x / 64) + 1] = 'P';
		ft_printmap(vars, -1, 0, 0);
		vars->num_of_mov += 1;
		write(1, "Number of movements : ", 22);
		ft_putnbr(vars->num_of_mov);
		write(1, "\n", 1);
	}
}

void	go_left(t_mlx *vars)
{
	if (vars->map[vars->monster_y / 64][(vars->monster_x / 64) - 1] == 'E'
			&& vars->count_cookie == 0)
		exit (1);
	if (vars->map[vars->monster_y / 64][(vars->monster_x / 64) - 1] != '1'
		&& vars->map[vars->monster_y / 64][(vars->monster_x / 64) - 1] != 'E')
	{
		if (vars->map[vars->monster_y / 64][(vars->monster_x / 64) - 1] == 'C')
			vars->count_cookie -= 1;
		vars->map[vars->monster_y / 64][vars->monster_x / 64] = '0';
		vars->map[vars->monster_y / 64][(vars->monster_x / 64) - 1] = 'P';
		ft_printmap(vars, -1, 0, 0);
		vars->num_of_mov += 1;
		write(1, "Number of movements : ", 22);
		ft_putnbr(vars->num_of_mov);
		write(1, "\n", 1);
	}
}

void	go_up(t_mlx *vars)
{
	if (vars->map[(vars->monster_y / 64) - 1][vars->monster_x / 64] == 'E'
			&& vars->count_cookie == 0)
		exit (1);
	if (vars->map[(vars->monster_y / 64) - 1][vars->monster_x / 64] != '1'
		&& vars->map[(vars->monster_y / 64) - 1][vars->monster_x / 64] != 'E')
	{
		if (vars->map[(vars->monster_y / 64) - 1][vars->monster_x / 64] == 'C')
			vars->count_cookie -= 1;
		vars->map[vars->monster_y / 64][vars->monster_x / 64] = '0';
		vars->map[(vars->monster_y / 64) - 1][vars->monster_x / 64] = 'P';
		ft_printmap(vars, -1, 0, 0);
		vars->num_of_mov += 1;
		write(1, "Number of movements : ", 22);
		ft_putnbr(vars->num_of_mov);
		write(1, "\n", 1);
	}
}

void	go_down(t_mlx *vars)
{
	if (vars->map[(vars->monster_y / 64) + 1][vars->monster_x / 64] == 'E'
			&& vars->count_cookie == 0)
		exit (1);
	if (vars->map[(vars->monster_y / 64) + 1][vars->monster_x / 64] != '1'
		&& vars->map[(vars->monster_y / 64) + 1][vars->monster_x / 64] != 'E')
	{
		if (vars->map[(vars->monster_y / 64) + 1][vars->monster_x / 64] == 'C')
			vars->count_cookie -= 1;
		vars->map[vars->monster_y / 64][vars->monster_x / 64] = '0';
		vars->map[(vars->monster_y / 64) + 1][vars->monster_x / 64] = 'P';
		ft_printmap(vars, -1, 0, 0);
		vars->num_of_mov += 1;
		write(1, "Number of movements : ", 22);
		ft_putnbr(vars->num_of_mov);
		write(1, "\n", 1);
	}
}

int	key_hook(int keycode, t_mlx *vars)
{
	(void)vars;
	if (keycode == 53)
		exit(1);
	if (keycode == 2 || keycode == 124)
		go_right(vars);
	if (keycode == 0 || keycode == 123)
		go_left(vars);
	if (keycode == 1 || keycode == 125)
		go_down(vars);
	if (keycode == 13 || keycode == 126)
		go_up(vars);
	return (0);
}
