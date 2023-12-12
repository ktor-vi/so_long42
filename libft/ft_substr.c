/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:35:54 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 16:32:27 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static size_t	calculate(char const *s, unsigned int start, size_t len)
{
	size_t	remaining_length;
	size_t	actual_len;

	remaining_length = ft_strlen(s) - start;
	if (len > remaining_length)
		actual_len = remaining_length;
	else
		actual_len = len;
	return (actual_len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s) || s[0] == '\0' || s == NULL)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	sub = malloc(calculate(s, start, len));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
