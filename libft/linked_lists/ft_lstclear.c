/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 05:06:13 by kraoui            #+#    #+#             */
/*   Updated: 2025/07/23 03:49:11 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next;

	if (!lst || !del || !*lst)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		next = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = next;
	}
	*lst = NULL;
}
