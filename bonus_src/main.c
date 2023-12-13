/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:54:00 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 17:27:59 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17 // exit key code

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_putendl_fd("so_long accepts one argument only", 2), 1);
	game = (t_game){0};
	init_game(&game, argv);
	verify(&game);
	init_display(&game);
	mlx_key_hook(game.mlx, &key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
