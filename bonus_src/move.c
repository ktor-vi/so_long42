/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:55:16 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 13:55:17 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_up(t_game *game)
{
	if (game == NULL)
		return (-1);
	if (game->sprites[4] == NULL)
		return (-1);
	clear_player(game);
	game->sprites[4]->instances[0].y -= 64;
	game->sprites[5]->instances[0].y -= 64;
	game->sprites[6]->instances[0].y -= 64;
	game->sprites[7]->instances[0].y -= 64;
	game->sprites[6]->enabled = true;
	return (0);
}

int	move_down(t_game *game)
{
	if (game == NULL)
		return (-1);
	if (game->sprites[4] == NULL)
		return (-1);
	clear_player(game);
	game->sprites[4]->instances[0].y += 64;
	game->sprites[5]->instances[0].y += 64;
	game->sprites[6]->instances[0].y += 64;
	game->sprites[7]->instances[0].y += 64;
	game->sprites[7]->enabled = true;
	return (0);
}

int	move_left(t_game *game)
{
	if (game == NULL)
		return (-1);
	if (game->sprites[4] == NULL)
		return (-1);
	clear_player(game);
	game->sprites[4]->instances[0].x -= 64;
	game->sprites[5]->instances[0].x -= 64;
	game->sprites[6]->instances[0].x -= 64;
	game->sprites[7]->instances[0].x -= 64;
	game->sprites[5]->enabled = true;
	return (0);
}

int	move_right(t_game *game)
{
	if (game == NULL)
		return (-1);
	if (game->sprites[4] == NULL)
		return (-1);
	clear_player(game);
	game->sprites[4]->instances[0].x += 64;
	game->sprites[5]->instances[0].x += 64;
	game->sprites[6]->instances[0].x += 64;
	game->sprites[7]->instances[0].x += 64;
	game->sprites[4]->enabled = true;
	return (0);
}

void	clear_player(t_game *game)
{
	int	i;

	i = 4;
	while (i < 8)
	{
		game->sprites[i]->enabled = false;
		i++;
	}
}
