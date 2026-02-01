/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_onec                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:40:11 by kraoui            #+#    #+#             */
/*   Updated: 2025/12/15 23:20:56 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_strs(char const *s, char c)
{
	int	count;
	int	i;

	if (!s || !*s)
		return (1);
	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static char	*get_line(char const *s, int *pos, char c)
{
	int		start;
	int		end;
	char	*str;

	start = *pos;
	while (s[*pos] && s[*pos] != c)
		(*pos)++;
	end = *pos;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], end - start + 1);
	if (s[*pos] == c)
		(*pos)++;
	return (str);
}

char	**ft_split_by_one(char const *s, char c)
{
	char	**strs;
	int		line_count;
	int		i;
	int		pos;

	if (!s)
		return (NULL);
	line_count = count_strs(s, c);
	strs = malloc(sizeof(char *) * (line_count + 1));
	if (!strs)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < line_count)
	{
		strs[i] = get_line(s, &pos, c);
		if (!strs[i])
			return (free_split(strs, i));
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
