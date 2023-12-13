/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fool_proof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:16:46 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/13 12:17:04 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	xpm_sprite_fail(void)
{
	int	fd;

	fd = open("./img/collectible.xpm42", O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("XPM load failed*", 2), 1);
	close(fd);
	fd = open("./img/ground.xpm42", O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("XPM load failed@", 2), 1);
	close(fd);
	fd = open("./img/wall.xpm42", O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("XPM load failed!", 2), 1);
	close(fd);
	fd = open("./img/exit.xpm42", O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("XPM load failed^", 2), 1);
	close(fd);
	return (0);
}

static int	xpm_player_fail(void)
{
	int	fd;

	fd = 0;
	fd = open("./img/right1.xpm42", O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("XPM load failed", 2), 1);
	close(fd);
	fd = open("./img/up1.xpm42", O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("XPM load failed", 2), 1);
	close(fd);
	fd = open("./img/left1.xpm42", O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("XPM load failed", 2), 1);
	close(fd);
	fd = open("./img/down1.xpm42", O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("XPM load failed", 2), 1);
	close(fd);
	return (0);
}

static int	name_check(char *name)
{
	int	l;

	l = ft_strlen(name);
	if (name[l - 4] == '.' && name[l - 3] == 'b' && name[l - 2] == 'e' && name[l
			- 1] == 'r')
		return (0);
	else
		return (ft_putendl_fd("Map : name invalid", 2), 1);
}

void	file_check(char *name)
{
	if (name_check(name) || xpm_sprite_fail() || xpm_player_fail())
		exit(1);
}

void	empty_file(t_game game)
{
	ft_putendl_fd("Map : file is empty", 2);
	exit(1);
}
