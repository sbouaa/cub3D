/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:51:30 by kraoui            #+#    #+#             */
/*   Updated: 2025/01/31 16:16:52 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	a;

	i = 0;
	ptr = (unsigned char *)s;
	a = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (i + 1 < n && ptr[i] != a)
	{
		i++;
	}
	if (ptr[i] == a)
		return (&ptr[i]);
	else
		return (NULL);
}
