/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:35:42 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 16:32:23 by vphilipp         ###   ########.fr       */
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

static char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;

	len = ft_strlen(s1);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (len >= 0)
	{
		dest[len] = s1[len];
		len--;
	}
	return (dest);
}

static int	ft_cc(char c, char const *charset)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(charset);
	i = 0;
	while (i < len)
	{
		if (c == charset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	calculate(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	j = ft_strlen(s1) - 1;
	count = 0;
	while (i <= j && ft_cc(s1[i], set) == 1)
	{
		count++;
		i++;
	}
	while (i <= j && ft_cc(s1[j], set) == 1)
	{
		j--;
		count++;
	}
	return (ft_strlen(s1) - count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		k;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	k = 0;
	if (s1[0] == '\0')
		return (ft_strdup(""));
	trimmed = malloc(calculate(s1, set) + 1);
	if (trimmed == NULL)
		return (NULL);
	while (ft_cc(s1[i], set))
		i++;
	while (k < calculate(s1, set) && s1[i] != '\0')
		trimmed[k++] = s1[i++];
	trimmed[k] = '\0';
	return (trimmed);
}
