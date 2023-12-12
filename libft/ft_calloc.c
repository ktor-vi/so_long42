/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:36:06 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 16:30:01 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*res;
	char	*tmp;
	size_t	i;

	i = -1;
	total_size = count * size;
	res = NULL;
	if (count != 0 && size != 0)
	{
		if (total_size / count != size)
			return (NULL);
	}
	if (count == 0 || size == 0)
		total_size = 0;
	res = malloc(total_size);
	if (res == NULL)
		return (NULL);
	tmp = (char *)res;
	while (++i < total_size)
		tmp[i] = 0;
	return (res);
}
