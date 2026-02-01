/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:24:43 by kraoui            #+#    #+#             */
/*   Updated: 2025/12/02 13:10:07 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
	int		len1;
	int		len2;
	int		len3;
	char	*res;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	i = 0;
	res = (char *)malloc(sizeof(char) * (len1 + len2 + len3 + 1));
	if (!res)
		return (NULL);
	while (s1 && *s1)
		res[i++] = *s1++;
	while (s2 && *s2)
		res[i++] = *s2++;
	while (s3 && *s3)
		res[i++] = *s3++;
	res[i] = '\0';
	return (res);
}
