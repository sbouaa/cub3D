/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:47:10 by kraoui            #+#    #+#             */
/*   Updated: 2025/08/01 16:41:02 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_strchr_gnl(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (0);
}

static char	*read_ln(int fd, char *part, char *result)
{
	ssize_t	part_len;
	char	*new_result;

	part_len = 0;
	while (ft_strchr_gnl(result, '\n') == 0)
	{
		part_len = read(fd, part, BUFFER_SIZE);
		if (part_len < 0)
			return (ft_puterror(ERR_READ));
		if (part_len == 0)
			break ;
		part[part_len] = '\0';
		new_result = ft_strjoin(result, part);
		free(result);
		result = new_result;
		if (!result)
			return (NULL);
	}
	return (result);
}

static char	*sep_ln(char **line)
{
	char	*next_line;
	char	*current_line;
	int		index;

	index = 0;
	next_line = NULL;
	while ((*line)[index] && (*line)[index] != '\n')
		index++;
	if ((*line)[index] && (*line)[index] == '\n')
		index++;
	current_line = ft_substr(*line, 0, index);
	if (!current_line)
		return (free(*line), *line = NULL, NULL);
	if ((*line)[index])
		next_line = ft_substr(*line, index, -1);
	free(*line);
	*line = NULL;
	*line = current_line;
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*next_line[1024];
	char		*line;
	char		*part;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (ft_puterror(ERR_READ), free(next_line[fd]),
			next_line[fd] = NULL, NULL);
	part = malloc((size_t)BUFFER_SIZE + 1);
	if (!part)
		return (ft_puterror(ERR_MALLOC),
			free(next_line[fd]), next_line[fd] = NULL, NULL);
	line = read_ln(fd, part, next_line[fd]);
	free(part);
	part = NULL;
	if (!line)
		return (next_line[fd] = NULL, NULL);
	next_line[fd] = sep_ln(&line);
	return (line);
}
