/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:48:04 by kraoui            #+#    #+#             */
/*   Updated: 2025/01/31 16:17:10 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	g;
	unsigned char	*ptr;

	i = 0;
	g = (unsigned char)c;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = g;
		i++;
	}
	return (ptr);
}
