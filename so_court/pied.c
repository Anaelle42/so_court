/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pied.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:44:57 by ahenault          #+#    #+#             */
/*   Updated: 2024/10/10 13:46:27 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;

	void *wall;
	void *floor;
	void *player;
	void *coin;
	void *exit;

	int playerx;
	int playery;
	char **map;
	int nb_coins;
	int p_coins;
}				t_vars;

int end(t_vars *var)
{
	int i = 0;
	while(var->map[i])
	{
		free(var->map[i]);
		i++;
	}
	free(var->map);
	mlx_destroy_image(var->mlx,var->floor);
	mlx_destroy_image(var->mlx,var->wall);
	mlx_destroy_image(var->mlx,var->player);
	mlx_destroy_image(var->mlx,var->coin);
	mlx_destroy_image(var->mlx,var->exit);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	exit(0);
}

int move(t_vars *var, int x, int y)
{
	if (var->map[(var->playery + y) / 48 ][(var->playerx + x) / 48] == 'E' && var->p_coins == var->nb_coins)
		end(var);
	if (var->map[(var->playery + y) / 48 ][(var->playerx + x) / 48] == '1' 
	|| var->map[(var->playery + y) / 48 ][(var->playerx + x) / 48] == 'E')
		return (0);
	mlx_put_image_to_window(var->mlx, var->win, var->floor, var->playerx, var->playery);
	var->playerx += x;
	var->playery += y;
	if (var->map[(var->playery) / 48 ][(var->playerx) / 48] == 'C')
	{
		var->p_coins++;
		var->map[(var->playery) / 48 ][(var->playerx) / 48] = '0';
	}
	mlx_put_image_to_window(var->mlx, var->win, var->player, var->playerx, var->playery);
	return (0);
}

int game(int key, t_vars *var)
{
	if (key == 65307)
	{
		end(var);
	}
	if (key == 65361)
		move(var, -48 , 0);
	if (key == 65362)
		move(var, 0 , -48);
	if (key == 65363)
		move(var, 48 , 0);
	if (key == 65364)
		move(var, 0 , 48);
	return (0);
}

int main()
{
	int nb_map = 16;
	
	t_vars var;
	int size_win_x;	int size_win_y;
	int w = 0;	int h = 0;
	int x = 0; int y = 0;
	var.mlx = mlx_init();
	if(!var.mlx)
		return (1);
	mlx_get_screen_size(var.mlx, &size_win_x, &size_win_y);
	var.win = mlx_new_window(var.mlx, 300, 300, "le jeu so_court kawaiii");
	if(!var.win)
		return (1);
	var.nb_coins = 0;
	var.p_coins = 0;
	int fd = open("maps/caverne.ber", O_RDONLY);
	if (fd == - 1)
		return (1);
	int i = 0;
	int a = 0;
	var.wall = mlx_xpm_file_to_image(var.mlx, "xpm/mur.xpm", &w, &h);;
	var.floor = mlx_xpm_file_to_image(var.mlx, "xpm/sol.xpm", &w, &h);;
	var.player = mlx_xpm_file_to_image(var.mlx, "xpm/kitty.xpm", &w, &h);
	var.coin = mlx_xpm_file_to_image(var.mlx, "xpm/rosse.xpm", &w, &h);;
	var.exit = mlx_xpm_file_to_image(var.mlx, "xpm/porte.xpm", &w, &h);;

	var.map = calloc(nb_map + 1, sizeof(char *));
	if(!var.map)
		return (1);
	while(i < nb_map + 1)
	{
		var.map[i] = get_next_line(fd);
		i++;
	}
	i = 0;
	while(var.map[i])
	{
		while(var.map[i][a])
		{
			if(var.map[i][a] == '1')
				mlx_put_image_to_window(var.mlx, var.win, var.wall, x, y);
			if(var.map[i][a] == '0')
				mlx_put_image_to_window(var.mlx, var.win, var.floor, x, y);
			if(var.map[i][a] == 'P')
			{
				var.playerx = i * 48; var.playery = a * 48;
				mlx_put_image_to_window(var.mlx, var.win, var.player, x, y);
			}
			if(var.map[i][a] == 'C')
			{
				mlx_put_image_to_window(var.mlx, var.win, var.coin, x, y);
				var.nb_coins++;
			}
			if(var.map[i][a] == 'E')
				mlx_put_image_to_window(var.mlx, var.win, var.exit, x, y);
			x += 48;
			a++;
		}
		y +=48;
		a = 0;
		x = 0;
		i++;
	}
	close(fd);
	mlx_hook(var.win, 2, (1L<<0), game, &var);
	mlx_loop(var.mlx);
	return (0);
}
