/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:53:50 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 15:19:47 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_press(struct mlx_key_data keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode.key == MLX_KEY_ESCAPE && keycode.action == MLX_RELEASE)
	{
		terminate_all(game);
		exit(1);
	}
	else if (keycode.key == MLX_KEY_W && (keycode.action == MLX_REPEAT
			|| keycode.action == MLX_RELEASE))
		w_press(game);
	else if (keycode.key == MLX_KEY_A && (keycode.action == MLX_REPEAT
			|| keycode.action == MLX_RELEASE))
		a_press(game);
	else if (keycode.key == MLX_KEY_S && (keycode.action == MLX_REPEAT
			|| keycode.action == MLX_RELEASE))
		s_press(game);
	else if (keycode.key == MLX_KEY_D && (keycode.action == MLX_REPEAT
			|| keycode.action == MLX_RELEASE))
		d_press(game);
}

void	w_press(t_game *game)
{
	if (check_bounds(game->current_y - 1, game->current_x, game))
	{
		move_up(game);
		game->moves++;
		game->current_y--;
		check_collectable(game);
		ft_printf("Moves : %d\n", game->moves);
	}
}

void	a_press(t_game *game)
{
	if (check_bounds(game->current_y, game->current_x - 1, game))
	{
		move_left(game);
		game->moves++;
		game->current_x--;
		check_collectable(game);
		ft_printf("Moves : %d\n", game->moves);
	}
}

void	s_press(t_game *game)
{
	if (check_bounds(game->current_y + 1, game->current_x, game))
	{
		move_down(game);
		game->moves++;
		game->current_y++;
		check_collectable(game);
		ft_printf("Moves : %d\n", game->moves);
	}
}

void	d_press(t_game *game)
{
	if (check_bounds(game->current_y, game->current_x + 1, game))
	{
		move_right(game);
		game->moves++;
		game->current_x++;
		check_collectable(game);
		ft_printf("Moves : %d\n", game->moves);
	}
}
