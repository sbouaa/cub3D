/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:49:18 by kraoui            #+#    #+#             */
/*   Updated: 2025/07/23 03:49:22 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	ptr = NULL;
	while (lst)
	{
		new = ft_lstnew(lst->content);
		if (!new)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		new->content = f(lst->content);
		ft_lstadd_back(&ptr, new);
		lst = lst->next;
	}
	return (ptr);
}
