/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:53:37 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:38 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	calc_x(t_game *game)
{
	int	size_x;

	size_x = game->img_pxl * game->lines;
	return (size_x);
}

int	calc_y(t_game *game)
{
	int	size_y;

	size_y = game->img_pxl * game->rows;
	return (size_y);
}

int	check_bounds(int y, int x, t_game *game)
{
	if (x < 0 || x > game->rows - 1)
		return (0);
	else if (y < 0 || y > game->lines - 1)
		return (0);
	else if (game->matrix[y][x] != '1')
		return (1);
	return (0);
}
