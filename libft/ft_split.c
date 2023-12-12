/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 07:27:20 by ktorvi            #+#    #+#             */
/*   Updated: 2023/10/25 16:31:41 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	sep_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*ft_s_assign(char *src, char c)
{
	int		m_size;
	char	*s;
	int		i;

	m_size = sep_len(src, c);
	s = malloc(m_size + 1);
	if (!s)
	{
		return (NULL);
	}
	i = 0;
	while (i < m_size)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	**clear_splitted(char **splitted, int k)
{
	while (k >= 0)
	{
		free(splitted[k]);
		k--;
	}
	free(splitted);
	return (NULL);
}

static int	count_words(char *s, char c)
{
	int	word_count;
	int	j;

	word_count = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c && s[j])
			j++;
		if (s[j])
		{
			word_count++;
			while (s[j] != c && s[j])
				j++;
		}
	}
	return (word_count);
}

char	**ft_split(char *s, char c)
{
	char	**splitted;
	int		k;

	if (s == NULL)
		return (NULL);
	splitted = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	k = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			splitted[k] = ft_s_assign(s, c);
			if (splitted[k] == NULL)
				return (clear_splitted(splitted, k));
			k++;
			while (*s && *s != c)
				s++;
		}
	}
	splitted[k] = NULL;
	return (splitted);
}
// #include <stdio.h>
//
// int	main(int ac, char **av)
// {
// 	char	**table;
// 	int		i;
//
// 	(void)ac;
// 	i = 0;
// 	table = ft_split(av[1], av[2][0]);
// 	while (table[i])
// 	{
// 		printf("%s\n", table[i]);
// 		i++;
// 	}
// }
