/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:58:22 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 17:27:44 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_walls(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < game->lines)
	{
		while (i < game->rows)
		{
			if (game->matrix[j][i++] == '.' && (j == 0 || i == 0
					|| i == game->rows - 1 || j == game->lines - 1))
				return (0);
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_shape(t_game *game)
{
	int		k;
	size_t	base_len;

	k = 0;
	base_len = ft_strlen(game->matrix[k]);
	while (k < game->lines)
	{
		if (ft_strlen(game->matrix[k]) != base_len)
			return (0);
		k++;
	}
	return (1);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game->matrix[y][x] == '.')
		return ;
	if (check_bounds(y, x, game))
	{
		if (game->matrix[y][x] == 'C')
			game->collectables++;
		game->matrix[y][x] = '.';
		flood_fill(game, x - 1, y);
		flood_fill(game, x + 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
	return ;
}

int	check_collectables(t_game *game)
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
				if (game->matrix[j][i] != '.')
					return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (game->collectables < 1)
		return (1);
	else
		return (0);
}

int	check_exit(t_game *game)
{
	int	i;
	int	j;
	int	only;

	j = 0;
	i = 0;
	only = 0;
	while (j < game->lines)
	{
		while (i < game->rows)
		{
			if (game->ref_matrix[j][i] == 'E')
			{
				only++;
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (game->matrix[game->end_y][game->end_x] == '.' || only != 1)
		return (1);
	else
		return (0);
}
