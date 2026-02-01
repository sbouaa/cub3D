/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:08:08 by kraoui            #+#    #+#             */
/*   Updated: 2026/01/20 02:19:04 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_map_start(t_game *game)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (game->file[i])
	{
		trimmed = ft_strtrim(game->file[i], " \t");
		if (!trimmed)
			return (-1);
		if (trimmed[0] != '\0' && is_map_line(trimmed))
		{
			free(trimmed);
			return (i);
		}
		free(trimmed);
		i++;
	}
	return (-1);
}

void	get_map_dimensions(t_game *game, int start, int *height, int *width)
{
	int	i;
	int	len;

	*height = 0;
	*width = 0;
	i = start;
	while (game->file[i] && is_map_line(game->file[i]))
	{
		len = ft_strlen(game->file[i]);
		if (len > *width)
			*width = len;
		(*height)++;
		i++;
	}
}

void	check_map_position(t_game *game, int map_end)
{
	int		i;
	char	*trimmed;

	i = map_end;
	while (game->file[i])
	{
		trimmed = ft_strtrim(game->file[i], " \t");
		if (!trimmed)
			ft_error_msg(ERR_MEM, game);
		if (trimmed[0] != '\0')
		{
			free(trimmed);
			ft_error_msg(ERR_MAP_CONTENT, game);
		}
		free(trimmed);
		i++;
	}
}

int	create_map_grid(t_game *game, int map_start)
{
	int	i;
	int	j;

	game->map->grid = malloc(sizeof(char *) * (game->map->height + 1));
	if (!game->map->grid)
		return (0);
	i = 0;
	while (i < game->map->height)
	{
		game->map->grid[i] = malloc(game->map->width + 1);
		if (!game->map->grid[i])
			return (free_split(game->map->grid, i), 0);
		j = 0;
		while (j < (int)ft_strlen(game->file[map_start + i]))
		{
			game->map->grid[i][j] = game->file[map_start + i][j];
			j++;
		}
		while (j < game->map->width)
			game->map->grid[i][j++] = '\0';
		game->map->grid[i][j] = '\0';
		i++;
	}
	game->map->grid[i] = NULL;
	return (1);
}

void	parse_map(t_game *game)
{
	int	map_start;
	int	map_end;

	map_start = find_map_start(game);
	if (map_start < 0)
		ft_error_msg(ERR_MAP_INVALID, game);
	get_map_dimensions(game, map_start, &game->map->height, &game->map->width);
	map_end = map_start + game->map->height;
	check_map_position(game, map_end);
	if (!create_map_grid(game, map_start))
		ft_error_msg(ERR_MEM, game);
}
