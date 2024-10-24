/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jambe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:07:33 by ahenault          #+#    #+#             */
/*   Updated: 2024/10/24 16:12:50 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_list	*witch;
	void	*player[4];

	void	*wall;
	void	*wall2;

	void	*floor;
	void	*floor2;

	// void	*coin;
	// void	*exit;

	int		playerx;
	int		playery;
	char	**map;
	// int		nb_coins;
	// int		p_coins;
}			t_vars;

// int	end(t_vars *var)
// {
// 	int	i;

// 	i = 0;
// 	while (var->map[i])
// 	{
// 		free(var->map[i]);
// 		i++;
// 	}
// 	free(var->map);
// 	mlx_destroy_image(var->mlx, var->floor);
// 	mlx_destroy_image(var->mlx, var->wall);
// 	mlx_destroy_image(var->mlx, var->player);
// 	mlx_destroy_image(var->mlx, var->coin);
// 	mlx_destroy_image(var->mlx, var->exit);
// 	mlx_destroy_window(var->mlx, var->win);
// 	mlx_destroy_display(var->mlx);
// 	free(var->mlx);
// 	exit(0);
// }

int	move(t_vars *var, int x, int y)
{
	// if (var->map[(var->playery + y) / 48][(var->playerx + x) / 48] == 'E'
	// 	&& var->p_coins == var->nb_coins)
	// 	end(var);
	//	|| var->map[(var->playery + y) / 48][(var->playerx + x) / 32] == 'E')
	if ((var->map[(var->playery + y) / 48][(var->playerx + x) / 32] == '1')
		|| (var->map[(var->playery + y) / 48][(var->playerx + x) / 32] == '2'))
		return (0);
	if (var->map[(var->playery + y) / 48][(var->playerx + x) / 32] == '3')
		return (0);
	var->map[var->playery / 48][var->playerx / 32] = '3';
	mlx_put_image_to_window(var->mlx, var->win, var->floor2, var->playerx,
		var->playery);
	var->playerx += x;
	var->playery += y;
	// if (var->map[(var->playery) / 48][(var->playerx) / 48] == 'C')
	// {
	// 	var->p_coins++;
	// 	var->map[(var->playery) / 48][(var->playerx) / 48] = '0';
	// }
	// mlx_put_image_to_window(var->mlx, var->win, var->player, var->playerx,
	// 	var->playery);
	return (0);
}

int	game(int key, t_vars *var)
{
	(void)var;
	if (key == 65307)
	{
		// end(var);
		exit(0);
	}
	if (key == 65361 && (var->playerx - 1) >= 0)
	{
		printf("gauche\n");
		move(var, -32, 0);
	}
	if (key == 65362 && (var->playery - 1) >= 0)
	{
		printf("haut %i\n", var->playery / 48);
		printf("haut %i\n", var->playery / 48 - 1);
		printf("haut\n");
		move(var, 0, -48);
	}
	if (key == 65363)
	{
		printf("droite\n");
		move(var, 32, 0);
	}
	if (key == 65364)
	{
		printf("bas\n");
		move(var, 0, 48);
	}
	return (0);
}

int	image(t_vars *var)
{
	static int	frame;

	frame++;
	if (frame == 10000) // 100000
	{
		frame = 0;
		mlx_put_image_to_window(var->mlx, var->win, var->witch->content,
			var->playerx, var->playery);
		var->witch = var->witch->next;
	}
	return (0);
}

t_list	*create_list(t_vars var)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	list = NULL;
	tmp = NULL;
	i = 0;
	ft_lstadd_back(&list, ft_lstnew((void *)var.player[i]));
	i++;
	tmp = list;
	while (42)
	{
		ft_lstadd_back(&list, ft_lstnew((void *)var.player[i]));
		i++;
		if (var.player[i])
			list = list->next;
		else
			break ;
	}
	list->next = tmp;
	return (tmp);
}

int	main(void)
{
	t_vars	var;
	int		w;
	int		h;
	int		fd;
	int		size_win_x;
	int		size_win_y;
	int		nb_map;
	int		i;
	int		a;

	// int		x;
	// int		y;
	nb_map = 9;
	w = 0;
	h = 0;
	// x = 0;
	// y = 0;
	// var.nb_coins = 0;
	// var.p_coins = 0;
	i = 0;
	// a = 0;
	var.mlx = mlx_init();
	if (!var.mlx)
		return (1);
	mlx_get_screen_size(var.mlx, &size_win_x, &size_win_y);
	var.win = mlx_new_window(var.mlx, size_win_x, size_win_y,
			"la nouvelle version qui dechire tout");
	if (!var.win)
		return (1);
	fd = open("maps/map.ber", O_RDONLY);
	if (fd == -1)
		return (1);
	//
	var.player[0] = mlx_xpm_file_to_image(var.mlx, "xpm/a.xpm", &w, &h);
	var.player[1] = mlx_xpm_file_to_image(var.mlx, "xpm/b.xpm", &w, &h);
	var.player[2] = mlx_xpm_file_to_image(var.mlx, "xpm/a.xpm", &w, &h);
	var.player[3] = NULL;
	var.floor = mlx_xpm_file_to_image(var.mlx, "xpm/sol.xpm", &w, &h);
	var.floor2 = mlx_xpm_file_to_image(var.mlx, "xpm/sol2.xpm", &w, &h);
	var.wall = mlx_xpm_file_to_image(var.mlx, "xpm/wall.xpm", &w, &h);
	var.wall2 = mlx_xpm_file_to_image(var.mlx, "xpm/wall2.xpm", &w, &h);
	var.witch = create_list(var);
	//
	var.map = calloc(nb_map + 1, sizeof(char *));
	if (!var.map)
		return (1);
	while (i < nb_map + 1)
	{
		var.map[i] = get_next_line(fd);
		i++;
	}
	i = 0;
	while (var.map[i])
	{
		a = 0;
		while (var.map[i][a] && (var.map[i][a] != '\n'))
		{
			// if (var.map[i][a] == '0')
			// 	mlx_put_image_to_window(var.mlx, var.win, var.floor, i * w, a
			// 		* h);
			if (var.map[i][a] == '1')
				mlx_put_image_to_window(var.mlx, var.win, var.wall, a * w, i
					* h);
			else if (var.map[i][a] == '2')
				mlx_put_image_to_window(var.mlx, var.win, var.wall2, a * w, i
					* h);
			else if (var.map[i][a] == 'P')
			{
				var.playerx = a * w;
				var.playery = i * h;
				// mlx_put_image_to_window(var.mlx, var.win, var.player, x, y);
			}
			else
				mlx_put_image_to_window(var.mlx, var.win, var.floor, a * w, i
					* h);
			// if (var.map[i][a] == 'C')
			// {
			// 	mlx_put_image_to_window(var.mlx, var.win, var.coin, x, y);
			// 	var.nb_coins++;
			// }
			// if (var.map[i][a] == 'E')
			// 	mlx_put_image_to_window(var.mlx, var.win, var.exit, x, y);
			// x += 48;
			a++;
		}
		// y += 48;
		// x = 0;
		i++;
	}
	close(fd);
	mlx_hook(var.win, 2, (1L << 0), game, &var);
	mlx_loop_hook(var.mlx, image, &var);
	mlx_loop(var.mlx);
	return (0);
}
