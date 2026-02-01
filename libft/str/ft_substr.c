/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:09:13 by kraoui            #+#    #+#             */
/*   Updated: 2025/12/02 13:11:14 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	size_t			j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	if (j < start)
		return (ft_strdup(""));
	while (i < len && s[start + i] != '\0')
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], i + 1);
	return (str);
}
