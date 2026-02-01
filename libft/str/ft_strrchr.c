/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:15:33 by kraoui            #+#    #+#             */
/*   Updated: 2025/01/31 16:18:46 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	a;

	str = (char *)s;
	a = (char)c;
	i = ft_strlen(str);
	while (i > 0 && str[i] != a)
	{
		i--;
	}
	if (str[i] == a)
		return (&str[i]);
	return (NULL);
}
