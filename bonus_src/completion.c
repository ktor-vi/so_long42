/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:28:11 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 17:28:13 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_collectable(t_game *game)
{
	size_t	i;

	i = 0;
	if (game->ref_matrix[game->current_y][game->current_x] == 'C')
	{
		game->collectables++;
		game->ref_matrix[game->current_y][game->current_x] = '0';
		while (i < game->sprites[3]->count)
		{
			if (game->sprites[3]->instances[i].x == game->current_x * 64
				&& game->sprites[3]->instances[i].y == game->current_y * 64)
				game->sprites[3]->instances[i].enabled = false;
			i++;
		}
	}
	if (game->collectables == game->total_collectables
		&& game->collectables > 0)
		game->sprites[2]->enabled = true;

	if (game->collectables == game->total_collectables
		&& game->current_y == game->end_y && game->current_x == game->end_x)
	{
		terminate_all(game);
		exit(0);
	}
}

static void	free_sprites(t_game *game, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		mlx_delete_image(game->mlx, game->sprites[i]);
		i++;
	}
}

void	terminate_all(t_game *game)
{
	if (game->ref_matrix)
		clear_tab(game->ref_matrix);
	if (game->matrix)
		clear_tab(game->matrix);
	free_sprites(game, 8);
	mlx_terminate(game->mlx);
}

void	verify(t_game *game)
{
	flood_fill(game, game->current_x, game->current_y);
	if (check_exit(game))
	{
		ft_putendl_fd("Map : exit invalid", 2);
		terminate_all(game);
		exit(1);
	}
	if (check_shape(game))
	{
		ft_putendl_fd("Map : shape invalid", 2);
		terminate_all(game);
		exit(1);
	}
	else if (check_walls(game))
	{
		ft_putendl_fd("Map : border invalid", 2);
		terminate_all(game);
		exit(1);
	}
	else if (check_collectables(game))
	{
		ft_putendl_fd("Map : collectables invalid", 2);
		terminate_all(game);
		exit(1);
	}
}
