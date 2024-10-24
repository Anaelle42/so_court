/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:46:30 by ahenault          #+#    #+#             */
/*   Updated: 2023/11/22 19:15:47 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_ele;

	new_list = NULL;
	while (lst)
	{
		new_ele = ft_lstnew(f(lst->content));
		if (new_ele == 0)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, new_ele);
		if (new_list == 0)
			return (0);
		lst = lst->next;
	}
	return (new_list);
}
