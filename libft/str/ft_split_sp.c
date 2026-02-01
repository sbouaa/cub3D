/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:40:11 by kraoui            #+#    #+#             */
/*   Updated: 2025/12/05 13:20:00 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	cw(char const *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '\t' || str[i] == ' '))
			i++;
		if (str[i] && (str[i] != '\t' && str[i] != ' '))
			j++;
		while (str[i] && (str[i] != '\t' && str[i] != ' '))
			i++;
	}
	return (j);
}

static int	cc(char const *str, int j)
{
	int	i;

	i = 0;
	while (j == 2 && str[i] && (str[i] == '\t' || str[i] == ' '))
		i++;
	while (j == 1 && str[i] && (str[i] != '\t' && str[i] != ' '))
		i++;
	return (i);
}

static char	*copy(char const *s, int i)
{
	char	*dest;
	int		j;
	int		len;

	j = 0;
	len = cc(&s[i], 1);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (j < len && s[i] != '\0')
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split_sp(char const *s)
{
	int		i;
	int		j;
	char	**strs;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (cw(s) + 1));
	if (!strs)
		return (NULL);
	while (j < cw(s))
	{
		i += cc(&s[i], 2);
		strs[j] = copy(s, i);
		i += cc(&s[i], 1);
		if (strs[j] == NULL)
			return (free_split(strs, j));
		j++;
	}
	strs[j] = NULL;
	return (strs);
}
