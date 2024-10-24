/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:35:55 by ahenault          #+#    #+#             */
/*   Updated: 2023/11/22 18:43:20 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
}
