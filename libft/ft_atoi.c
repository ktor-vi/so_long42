/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:49:00 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 16:30:02 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_c_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

static int	handle_overflow(int sign)
{
	if (sign == 1)
		return (-1);
	else 
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long int	result;
	int						i;
	int						sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_c_is_numeric(str[i]))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result > 9223372036854775807)
			return (handle_overflow(sign));
	}
	return (result * sign);
}
