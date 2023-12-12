/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:13:40 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/12 17:31:35 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	struct s_list	*last;

	if (new_node == NULL)
		return ;
	last = ft_lstlast(*lst);
	if (last != NULL)
	{
		last->next = new_node;
	}
	else
	{
		*lst = new_node;
	}
}
