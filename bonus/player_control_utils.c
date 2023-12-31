/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:14:58 by fkalaman          #+#    #+#             */
/*   Updated: 2023/05/11 12:28:44 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->map[vars->i - 1][vars->j] != '1')
	{
		if (vars->map[vars->i][vars->j] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b,
				vars->x, vars->y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.e,
				vars->x, vars->y);
		if (vars->map[vars->i][vars->j] != 'E')
			vars->map[vars->i][vars->j] = '0';
		vars->y -= IMG_SIZE;
		vars->i -= 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->m.player_back_img, vars->x, vars->y);
		if (vars->map[vars->i][vars->j] == '0')
			vars->map[vars->i][vars->j] = 'P';
		if (vars->map[vars->i][vars->j] == 'C')
		{
			vars->map[vars->i][vars->j] = '0';
			vars->collected_coin++;
		}
		move_counter(vars);
	}
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->i + 1][vars->j] != '1')
	{
		if (vars->map[vars->i][vars->j] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b,
				vars->x, vars->y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.e,
				vars->x, vars->y);
		if (vars->map[vars->i][vars->j] != 'E')
			vars->map[vars->i][vars->j] = '0';
		vars->y += IMG_SIZE;
		vars->i += 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.player_img,
			vars->x, vars->y);
		if (vars->map[vars->i][vars->j] == '0')
			vars->map[vars->i][vars->j] = 'P';
		if (vars->map[vars->i][vars->j] == 'C')
		{
			vars->map[vars->i][vars->j] = '0';
			vars->collected_coin++;
		}
		move_counter(vars);
	}
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->i][vars->j + 1] != '1')
	{
		if (vars->map[vars->i][vars->j] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b,
				vars->x, vars->y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.e,
				vars->x, vars->y);
		if (vars->map[vars->i][vars->j] != 'E')
			vars->map[vars->i][vars->j] = '0';
		vars->x += IMG_SIZE;
		vars->j += 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->m.player_right_img, vars->x, vars->y);
		if (vars->map[vars->i][vars->j] == '0')
			vars->map[vars->i][vars->j] = 'P';
		if (vars->map[vars->i][vars->j] == 'C')
		{
			vars->map[vars->i][vars->j] = '0';
			vars->collected_coin++;
		}
		move_counter(vars);
	}
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->i][vars->j - 1] != '1')
	{
		if (vars->map[vars->i][vars->j] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b,
				vars->x, vars->y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->m.e,
				vars->x, vars->y);
		if (vars->map[vars->i][vars->j] != 'E')
			vars->map[vars->i][vars->j] = '0';
		vars->x -= IMG_SIZE;
		vars->j -= 1;
		++vars->move_count;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->m.player_left_img, vars->x, vars->y);
		if (vars->map[vars->i][vars->j] == '0')
			vars->map[vars->i][vars->j] = 'P';
		if (vars->map[vars->i][vars->j] == 'C')
		{
			vars->map[vars->i][vars->j] = '0';
			vars->collected_coin++;
		}
		move_counter(vars);
	}
}

void	exit_door(t_vars *vars)
{
	if (vars->map[vars->i][vars->j] == 'V')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.enemy_img,
			vars->x, vars->y);
		ft_printf("\nYou DEAD!\n");
		exit(0);
	}
	if (vars->map[vars->i][vars->j] == 'E'
		&& vars->collected_coin + 1 == vars->cants.coin_count)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.exiter_img,
			vars->x, vars->y);
		ft_printf("\nYou Rock!\n");
		exit(0);
	}
	else if (vars->map[vars->i][vars->j] == 'E'
			&& vars->collected_coin != vars->cants.coin_count)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.exiter_img,
			vars->x, vars->y);
		ft_printf("\nYou have to collect all coins before you go");
	}
}
