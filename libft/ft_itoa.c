/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:14:59 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 16:30:24 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

static int	calculate(int n)
{
	int	count;
	int	sign;

	count = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count + sign);
}

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

char	*edge(int n)
{
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	else
		return (ft_strdup("0"));
}

char	*ft_itoa(int n)
{
	char	*itoaed;
	int		i;
	int		sign;

	if (n == 0 || n == INT_MIN)
		return (edge(n));
	i = calculate(n) - 1;
	sign = 0;
	itoaed = malloc(calculate(n) + 1);
	if (itoaed == NULL)
		return (NULL);
	itoaed[calculate(n)] = '\0';
	if (n < 0)
	{
		itoaed[0] = '-';
		sign = 1;
		n *= -1;
	}
	while (i >= sign)
	{
		itoaed[i] = (char)((n % 10) + 48);
		n /= 10;
		i--;
	}
	return (itoaed);
}

// #include <stdio.h>
// int main(void)
// {
//     printf("%s\n", ft_itoa(INT_MIN));
// }
