/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:41:02 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 16:32:07 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapid;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	mapid = malloc(ft_strlen(s) + 1);
	if (mapid == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		mapid[i] = f(i, s[i]);
		i++;
	}
	mapid[i] = '\0';
	return (mapid);
}
