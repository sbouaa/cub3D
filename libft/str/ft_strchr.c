/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:48:01 by kraoui            #+#    #+#             */
/*   Updated: 2025/01/31 16:17:57 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	a;

	i = 0;
	str = (char *)s;
	a = (char)c;
	while (str[i] != a && str[i])
		i++;
	if (str[i] == a)
		return (&str[i]);
	return (NULL);
}
