/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:28:26 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 17:28:43 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game, char **argv)
{
	*game = build_matrix(argv[1], *game);
	set_start(game);
	set_end(game);
	game->img_pxl = 64;
	init_textures(game);
	init_player(game);
	set_collectables(game);
}

void	init_display(t_game *game)
{
	display_wall(game, game->mlx);
	display_ground(game, game->mlx);
	display_collectible(game, game->mlx);
	display_exit(game, game->mlx);
	display_player(game, game->mlx);
}
