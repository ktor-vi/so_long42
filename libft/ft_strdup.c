/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:35:08 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 16:31:47 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup( char *s1)
{
	char	*dest;
	int		len;

	len = ft_strlen(s1);
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (len >= 0)
	{
		dest[len] = s1[len];
		len--;
	}
	return (dest);
}
