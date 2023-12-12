/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:44:40 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/30 16:25:28 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

char	*ft_cut(char *stash, int k)
{
	int		bp;
	char	*line;
	int		i;

	i = 0;
	if (k <= 0 || ft_memchr_gnl(stash, '\n') < 0)
		bp = ft_strlen_gnl(stash);
	else
		bp = ft_memchr_gnl(stash, '\n') + 1;
	line = malloc(bp + 1);
	if (line == NULL || bp == 0)
		return (ft_free(line));
	while (i < bp)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_error(char *line, char **stash)
{
	free(line);
	free(*stash);
	*stash = 0;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			i;
	char		*line;
	static char	*stash = NULL;

	buf[0] = '\0';
	i = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_memchr_gnl(stash, '\n') < 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= -1)
			return (ft_read_error(line, &stash));
		if (i == 0)
			break ;
		buf[i] = '\0';
		stash = strjoin(stash, buf);
		free(line);
	}
	line = ft_cut(stash, i);
	stash = ft_overwrite(stash);
	return (line);
}
