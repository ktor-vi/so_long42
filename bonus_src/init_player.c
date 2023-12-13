/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:18:23 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 15:18:25 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_player_u(t_game *game)
{
	xpm_t		*player_u;
	mlx_image_t	*player_ui;

	player_u = mlx_load_xpm42("./img/up1.xpm42");
	player_ui = mlx_texture_to_image(game->mlx, &player_u->texture);
	game->sprites[6] = player_ui;
	mlx_delete_xpm42(player_u);
}

static void	init_player_r(t_game *game)
{
	xpm_t		*player_r;
	mlx_image_t	*player_ri;

	player_r = mlx_load_xpm42("./img/right1.xpm42");
	player_ri = mlx_texture_to_image(game->mlx, &player_r->texture);
	game->sprites[4] = player_ri;
	mlx_delete_xpm42(player_r);
}

static void	init_player_l(t_game *game)
{
	xpm_t		*player_l;
	mlx_image_t	*player_li;

	player_l = mlx_load_xpm42("./img/left1.xpm42");
	player_li = mlx_texture_to_image(game->mlx, &player_l->texture);
	game->sprites[5] = player_li;
	mlx_delete_xpm42(player_l);
}

static void	init_player_d(t_game *game)
{
	xpm_t		*player_d;
	mlx_image_t	*player_di;

	player_d = mlx_load_xpm42("./img/down1.xpm42");
	player_di = mlx_texture_to_image(game->mlx, &player_d->texture);
	game->sprites[7] = player_di;
	mlx_delete_xpm42(player_d);
}

void	init_player(t_game *game)
{
	init_player_r(game);
	init_player_l(game);
	init_player_u(game);
	init_player_d(game);
}
