/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:29:59 by kraoui            #+#    #+#             */
/*   Updated: 2025/01/31 16:17:06 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	i = len - 1;
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (dst <= src && len > 0)
	{
		ptr1 = ft_memcpy(dst, src, len);
	}
	else if (dst > src && len > 0)
	{
		while (i + 1 > 0)
		{
			ptr1[i] = ptr2[i];
			i--;
		}
	}
	return (dst);
}
