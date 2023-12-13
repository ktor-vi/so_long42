/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:53:19 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:22 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	display_wall(t_game *game, void *mlx)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < game->lines)
	{
		while (i < game->rows)
		{
			if (game->matrix[j][i] == '1')
			{
				mlx_image_to_window(mlx, game->sprites[0], i * game->img_pxl, j
					* game->img_pxl);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	display_ground(t_game *game, void *mlx)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < game->lines)
	{
		while (i < game->rows)
		{
			if (game->matrix[j][i] != '1')
			{
				mlx_image_to_window(mlx, game->sprites[1], i * game->img_pxl, j
					* game->img_pxl);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	display_collectible(t_game *game, void *mlx)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < game->lines)
	{
		while (i < game->rows)
		{
			if (game->ref_matrix[j][i] == 'C')
			{
				mlx_image_to_window(mlx, game->sprites[3], i * game->img_pxl, j
					* game->img_pxl);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	display_player(t_game *game, void *mlx)
{
	mlx_image_to_window(mlx, game->sprites[4], game->current_x * 64,
		(game->current_y - 1) * 64);
	mlx_image_to_window(mlx, game->sprites[5], game->current_x * 64,
		(game->current_y - 1) * 64);
	mlx_image_to_window(mlx, game->sprites[6], game->current_x * 64,
		(game->current_y - 1) * 64);
	mlx_image_to_window(mlx, game->sprites[7], game->current_x * 64,
		(game->current_y - 1) * 64);
	clear_player(game);
	game->sprites[4]->enabled = true;
	return (0);
}

int	display_exit(t_game *game, void *mlx)
{
	mlx_image_to_window(mlx, game->sprites[2], game->end_x * 64, (game->end_y)
		* 64);
	game->sprites[2]->enabled = false;
	return (0);
}
