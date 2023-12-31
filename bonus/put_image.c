/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:14:51 by fkalaman          #+#    #+#             */
/*   Updated: 2023/03/18 15:16:52 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars *vars, int i, int j)
{
	int	x;
	int	y;

	while (vars->map[i])
	{
		y = i * IMG_SIZE;
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			x = j * IMG_SIZE;
			if (vars->map[i][j] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.w, x, y);
			}
			else if (vars->map[i][j] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b, x, y);
			}
			j++;
		}
		i++;
	}
	put_pl(vars, 0, 0);
}

void	put_pl(t_vars *vars, int i, int j)
{
	int	x;
	int	y;

	while (vars->map[i])
	{
		y = i * IMG_SIZE;
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			x = j * IMG_SIZE;
			if (vars->map[i][j] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->m.player_img, x, y);
				vars->x = x;
				vars->y = y;
			}
			j++;
		}
		i++;
	}
	put_en(vars, 0, 0);
}

void	put_en(t_vars *vars, int i, int j)
{
	int	x;
	int	y;

	while (vars->map[i])
	{
		y = i * IMG_SIZE;
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			x = j * IMG_SIZE;
			if (vars->map[i][j] == 'V')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.enemy_img,
					x, y);
				vars->enemy_x = x;
				vars->enemy_y = y;
				vars->enemy_i = i;
				vars->enemy_j = j;
			}
			j++;
		}
		i++;
	}
	put_ce(vars, 0, 0);
}

void	put_ce(t_vars *vars, int i, int j)
{
	int	x;
	int	y;

	while (vars->map[i])
	{
		y = i * IMG_SIZE;
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			x = j * IMG_SIZE;
			if (vars->map[i][j] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.c, x, y);
			}
			else if (vars->map[i][j] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.e, x, y);
			}
			j++;
		}
		i++;
	}
}

void	put_coin(t_vars *vars, int i, int j, int k)
{
	int	x;
	int	y;

	while (vars->map[i])
	{
		y = i * IMG_SIZE;
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			x = j * IMG_SIZE;
			if (vars->map[i][j] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->m.c, x, y);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->s.cs[k], x,
					y);
			}
			j++;
		}
		i++;
	}
}
