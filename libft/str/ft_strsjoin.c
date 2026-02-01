/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:05:14 by kraoui            #+#    #+#             */
/*   Updated: 2025/12/02 13:10:31 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_total_len(char **strs, char *sep)
{
	int	total_len;
	int	j;

	total_len = 0;
	j = 0;
	while (strs && strs[j])
	{
		total_len += ft_strlen(strs[j]);
		if (strs[j + 1])
			total_len += ft_strlen(sep);
		j++;
	}
	return (total_len);
}

static void	ft_strsjoin_fill(char *str, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (strs && strs[j])
	{
		k = 0;
		while (strs[j][k])
			str[i++] = strs[j][k++];
		if (strs[j + 1] && sep)
		{
			k = 0;
			while (sep[k])
				str[i++] = sep[k++];
		}
		j++;
	}
	str[i] = '\0';
}

char	*ft_strsjoin(char **strs, char *sep)
{
	char	*str;
	int		total_len;

	if (!strs || *strs)
		return (NULL);
	total_len = ft_total_len(strs, sep);
	str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	ft_strsjoin_fill(str, strs, sep);
	return (str);
}
