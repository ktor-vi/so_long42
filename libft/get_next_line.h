/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:44:52 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/30 16:25:39 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 41
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *str);
char	*strjoin(char *s1, char *s2);
int		ft_memchr_gnl(char *s, int c);
char	*ft_overwrite(char *str);
char	*ft_free(char *str);

#endif
