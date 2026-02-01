/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:11:30 by kraoui            #+#    #+#             */
/*   Updated: 2025/12/05 12:30:10 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!s1 || !s2)
		return (1);
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (ptr1[i] == ptr2[i] && ptr1[i] && ptr2[i])
		i++;
	return (ptr1[i] - ptr2[i]);
}
