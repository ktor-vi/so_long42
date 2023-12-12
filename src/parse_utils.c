/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:55:23 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 13:55:26 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clear_tab(char **splitted)
{
	int	k;

	k = 0;
	while (splitted[k])
	{
		free(splitted[k]);
		k++;
	}
	free(splitted);
}

int	calc_lines(char *path)
{
	int		i;
	char	buf[1];
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(1);
	i = 0;
	while (read(fd, buf, 1) > 0)
	{
		if (buf[0] == '\n')
			i++;
	}
	close(fd);
	return (i);
}

int	size_splitted(char *path)
{
	char	*line;
	int		i;
	int		fd;
	char	**splitted;

	fd = open(path, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	splitted = ft_split(line, ' ');
	while (splitted[i])
		i++;
	free(line);
	close(fd);
	return (i);
}

void	print_map(t_game game)
{
	int	j;

	j = 0;
	while (j < game.lines)
	{
		printf("%s\n", game.matrix[j]);
		j++;
	}
}
