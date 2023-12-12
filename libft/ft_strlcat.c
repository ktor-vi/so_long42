/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 08:38:54 by ktorvi            #+#    #+#             */
/*   Updated: 2023/10/25 16:31:56 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static size_t	ft_cstrlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	i_dstlen;

	len = ft_cstrlen(src);
	if (!dst && dstsize == 0 && src)
		return (len);
	j = 0;
	i = ft_strlen(dst);
	i_dstlen = ft_strlen(dst);
	if (dstsize <= i_dstlen)
		return (len + dstsize);
	while (src[j] != '\0' && j < dstsize - i_dstlen - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (i_dstlen + len);
}
