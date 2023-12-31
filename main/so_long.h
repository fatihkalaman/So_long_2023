/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:14:38 by fkalaman          #+#    #+#             */
/*   Updated: 2023/05/04 13:32:43 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/ft_printf/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define IMG_SIZE 126

typedef struct s_cants
{
	int			coin_count;
	int			player_count;
	int			exit_count;
	int			enemy_count;
}				t_cants;

typedef struct s_path
{
	int			collectible_coin;
	int			spaces;
	int			**imap;
}				t_path;

typedef struct s_images
{
	char		*b;
	char		*w;
	char		*e;
	char		*exiter_img;
	char		*player_img;
	char		*player_back_img;
	char		*player_left_img;
	char		*player_right_img;
	char		*c;
	char		*enemy_img;
}				t_images;

typedef struct s_sprite
{
	char		*cs[8];
	int			aspeed;
}				t_sprite;

typedef struct s_vars
{
	t_cants		cants;
	t_path		path;
	t_images	m;
	t_sprite	s;
	char		**map;
	char		*map_name;
	char		sprites[6];
	void		*mlx;
	void		*win;
	int			width;
	int			len_height;
	int			map_height;
	int			map_width;
	int			move_count;
	int			collected_coin;
	int			enemy_x;
	int			enemy_y;
	int			enemy_i;
	int			enemy_j;
	int			enemyspeed;
	int			coinspeed;
	char		*mover;
	int			y;
	int			x;
	int			i;
	int			j;
}				t_vars;

void			exit_door(t_vars *vars);
void			map_read(t_vars *vars);
void			image_create(t_vars *vars);
void			map_put(t_vars *vars);
void			put_image(t_vars *vars, int i, int j);
void			upload(t_vars *vars);
void			img_load(t_vars *vars);
void			move_up(t_vars *vars);
void			move_down(t_vars *vars);
void			move_right(t_vars *vars);
void			move_left(t_vars *vars);
void			put_image(t_vars *vars, int i, int j);
void			put_pl(t_vars *vars, int i, int j);
void			put_en(t_vars *vars, int i, int j);
void			put_ce(t_vars *vars, int i, int j);
void			map_control_dsl(t_vars *vars);
void			mapfree_control(t_vars *vars);
void			rectangular(t_vars *vars, int i, int j);
void			control_components(char **map, t_vars *vars);
void			map_name_control(char *map_name, t_vars *vars);
void			error_messages(int i, t_vars *vars);
void			map_read_bonus(t_vars *vars);
void			player_locate(t_vars *vars);
void			c_coin(t_vars *vars, int i, int j);
void			c_player(t_vars *vars, int i, int j);
void			c_exit(t_vars *vars, int i, int j);
void			free_imap(t_vars *vars);
void			free_map(t_vars *vars);
void			free_exit(t_vars *vars);
void			free_wrong(t_vars *vars);
void			free_mapfree(t_vars *vars);
void			error_center_top_down(t_vars *vars);
void			error_center_left_right(t_vars *vars);
void			control(t_vars *vars);

void			put_coin(t_vars *vars, int i, int j, int k);
void			sprite_a(t_vars *vars);

int				path_up(int y, int x, t_vars *vars);
int				path_right(int y, int x, t_vars *vars);
int				path_left(int y, int x, t_vars *vars);

int				vertical_len(char *map_name);
int				horizontal_len(t_vars *vars);
int				map_control(t_vars *vars);
int				player_move(int keycode, t_vars *vars);
int				player_control(t_vars *vars);
int				counts(t_vars *vars);
int				path_finder(int y, int x, t_vars *vars);
int				press_close_key(t_vars *vars);

#endif