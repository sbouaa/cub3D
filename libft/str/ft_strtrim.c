/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:54:22 by kraoui            #+#    #+#             */
/*   Updated: 2025/12/04 10:33:36 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	cmp(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != (char)c && str[i])
	{
		i++;
	}
	if (str[i] == (char)c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	if (!*s1)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1);
	while (i < j && cmp(set, s1[i]) == 1)
		i++;
	while (j > i && cmp(set, s1[j - 1]) == 1)
		j--;
	len = j - i + 1;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[i], len);
	return (str);
}
